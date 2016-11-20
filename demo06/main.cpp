#include <QCoreApplication>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgText/Text>
#include <string>

using namespace std;

osg::ref_ptr<osgText::Text> createText(string str)
{
    osg::ref_ptr<osgText::Text> text = new osgText::Text;
    text->setFont("Fonts/shruti.ttf");
    text->setCharacterSize(10);
//    text->setAxisAlignment(osgText::Text::XZ_PLANE);
    text->setAutoRotateToScreen(true);
    text->setPosition(osg::Vec3(0.0,0.0,10.0));
    text->setColor(osg::Vec4(1.0,1.0,0.0,1.0));
    text->setText(str.c_str());
    return text;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

    osg::ref_ptr<osg::Group> root = new osg::Group;

    osg::ref_ptr<osg::Geode> textGeo = new osg::Geode;
    textGeo->addDrawable(createText("hello world"));
    root->addChild(textGeo.get());

    root->addChild(osgDB::readNodeFile("cow.osg"));
    viewer->setSceneData(root.get());


    viewer->setUpViewInWindow(50,50,600,480);
    viewer->run();

    return a.exec();
}

