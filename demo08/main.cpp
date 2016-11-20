#include <QCoreApplication>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgText/Text>
#include <osgGA/GUIEventHandler>
#include <string>
#include <osg/MatrixTransform>
#include <osg/NodeVisitor>
#include <osgGA/GUIEventAdapter>

using namespace std;

class MyEventHandle:public osgGA::GUIEventHandler
{
public:
    MyEventHandle(osgViewer::Viewer *viewer)
    {
        this->_viewer = viewer;
    }
    bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa)
    {
        switch (ea.getEventType()) {
        case osgGA::GUIEventAdapter::KEYDOWN:
            if(ea.getKey() == osgGA::GUIEventAdapter::KEY_W)
            {
                osg::ref_ptr<osg::Group> root =_viewer->getSceneData()->asGroup();
                for(int i = 0;i<root->getNumChildren();i++)
                {
                    if(root->getChild(i)->getName() == "cow")
                    {
                        cout<<"cow";
                    }

                }
            }

            break;
        default:
            break;
        }
        return false;
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
    node->setName("cow");

    root->addChild(node.get());

    viewer->setSceneData(root.get());
    viewer->addEventHandler(new MyEventHandle(viewer));
    viewer->setUpViewInWindow(50,50,600,480);
    viewer->run();

    return a.exec();
}

