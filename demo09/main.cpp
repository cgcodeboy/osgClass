#include <QCoreApplication>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgText/Text>
#include <osgGA/GUIEventHandler>
#include <string>
#include <osg/MatrixTransform>
#include <osg/AnimationPath>
#include <osg/NodeVisitor>
#include <osgGA/GUIEventAdapter>

osg::ref_ptr<osg::AnimationPathCallback> myPathCallback()
{
    osg::ref_ptr<osg::AnimationPathCallback> callback = new osg::AnimationPathCallback;
    osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode(osg::AnimationPath::LOOP);
    osg::AnimationPath::ControlPoint point;

    for(int i =0 ;i<100;i++)
    {
        point.setPosition(osg::Vec3(0,0,sin(i)));
        point.setScale(osg::Vec3(float(i)/100,float(i)/100,float(i)/100));
        path->insert(i,point);
    }

    callback->setAnimationPath(path);
    return callback;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

    osg::ref_ptr<osg::Group> root = new osg::Group;

    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");

    osg::ref_ptr<osg::MatrixTransform> mat = new osg::MatrixTransform;
    mat->setUpdateCallback(myPathCallback());
    mat->addChild(node.get());

    root->addChild(mat.get());

    viewer->setSceneData(root.get());
    viewer->setUpViewInWindow(50,50,600,480);
    viewer->run();


    return a.exec();
}

