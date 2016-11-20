#include <QCoreApplication>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgText/Text>
#include <string>
#include <osg/MatrixTransform>
#include <osg/NodeVisitor>

using namespace std;

class MyCallback:public osg::NodeCallback
{
public:
    MyCallback(osgViewer::Viewer *viewer)
    {
        this->_viewer = viewer;
    }

    virtual void operator ()(osg::Node *node,osg::NodeVisitor *nv)
    {
        cout<<"in 1";
        if(_viewer)
        {
            cout<<"in 2";
            osg::MatrixTransform* mat = dynamic_cast<osg::MatrixTransform*>(node);
            if(nv->getVisitorType() == osg::NodeVisitor::UPDATE_VISITOR)
            {
                cout<<"in 3";
                osg::Matrix matrix = osg::computeLocalToWorld(nv->getNodePath());
                osg::Vec3 pos = matrix.getTrans();
                mat->setMatrix(osg::Matrix::translate(pos.x(),pos.y()+0.1,pos.z()));
            }
            traverse(node,nv);
        }
    }

private:
    osgViewer::Viewer *_viewer;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

    osg::ref_ptr<osg::Group> root = new osg::Group;

    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");
    osg::ref_ptr<osg::MatrixTransform> mat = new osg::MatrixTransform;
    mat->setMatrix(osg::Matrix::translate(0,0,0));
    mat->setUpdateCallback(new MyCallback(viewer));
    mat->addChild(node.get());
    root->addChild(mat.get());

    viewer->setSceneData(root.get());


    viewer->setUpViewInWindow(50,50,600,480);
    viewer->run();

    return a.exec();
}

