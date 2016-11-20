#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osg/MatrixTransform>

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

	osg::ref_ptr<osg::Group> root = new osg::Group;
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");
	root->addChild(node.get());

	osg::ref_ptr<osg::MatrixTransform> mat = new osg::MatrixTransform;
	mat->setMatrix(osg::Matrix::scale(0.1, 0.1, 0.1)*osg::Matrix::rotate(osg::PI_4,0,0,1)*osg::Matrix::translate(10, 0, 0));
	mat->addChild(node.get());

	root->addChild(mat.get());
	viewer->setSceneData(root.get());
	viewer->setUpViewInWindow(50, 50, 600, 480);
	viewer->realize();
	viewer->run();
	return 0;
}