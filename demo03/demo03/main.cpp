#include <osgViewer\Viewer>
#include <osg/Group>
#include <osg/Geometry>
#include <osg/Node>
#include <osgDB/ReadFile>

osg::ref_ptr<osg::Geode> createPlane()
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;

	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

	osg::ref_ptr<osg::Vec3Array> vert = new osg::Vec3Array;
	vert->push_back(osg::Vec3(-10, 0, -10));
	vert->push_back(osg::Vec3(10, 0, -10));
	vert->push_back(osg::Vec3(10, 0, 10));
	vert->push_back(osg::Vec3(-10, 0, 10));
	geom->setVertexArray(vert);
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, vert->size()));

	osg::ref_ptr<osg::Vec3Array> color = new osg::Vec3Array;
	color->push_back(osg::Vec3(1, 0, 0));
	color->push_back(osg::Vec3(0, 1, 0));
	color->push_back(osg::Vec3(0, 0, 1));
	color->push_back(osg::Vec3(1, 1, 1));
	geom->setColorArray(color);
	geom->setColorBinding(osg::Geometry::AttributeBinding::BIND_PER_VERTEX);

	osg::ref_ptr<osg::Vec3Array> norm = new osg::Vec3Array;
	norm->push_back(osg::Vec3(0, 0, 1));
	geom->setNormalArray(norm);
	geom->setNormalBinding(osg::Geometry::AttributeBinding::BIND_OVERALL);

	geode->addDrawable(geom);
	return geode;
}

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> root = new osg::Group;

	osg::ref_ptr<osg::Geode> geode = createPlane();
	root->addChild(geode);

	viewer->setSceneData(root.get());
	viewer->setUpViewInWindow(50, 50, 600, 480);
	viewer->realize();
	viewer->run();
	return 0;
}