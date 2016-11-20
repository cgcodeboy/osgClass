#include <QCoreApplication>
#include <osg/Texture2D>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osg/Geode>
#include <osg/ShapeDrawable>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

    osg::ref_ptr<osg::Group> root = new osg::Group;

    osg::ref_ptr<osg::HeightField> heightField = new osg::HeightField;
    osg::ref_ptr<osg::Image> image = osgDB::readImageFile("001.bmp");
    heightField->allocate(image->s(),image->t());
    heightField->setOrigin(osg::Vec3(0,0,0));
    heightField->setXInterval(1);
    heightField->setYInterval(1);

    for(int i = 0;i<heightField->getNumColumns();i++)
    {
        for(int j = 0;j<heightField->getNumRows();j++)
        {
            heightField->setHeight(i,j,(*image->data(i,j)));
        }
    }

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(new osg::ShapeDrawable(heightField));

    viewer->setSceneData(geode.get());
    viewer->setUpViewInWindow(50,50,600,480);
    viewer->run();

    return a.exec();
}

