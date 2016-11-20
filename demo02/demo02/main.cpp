#include <osgViewer\Viewer>
#include <osg/Group>
#include <osg/Node>
#include <osgDB/ReadFile>

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> root = new osg::Group;

	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");
	root->addChild(node.get());
	viewer->setSceneData(root.get());
	viewer->setUpViewInWindow(50, 50, 600, 480);
	viewer->realize();
	viewer->run();
	return 0;
}