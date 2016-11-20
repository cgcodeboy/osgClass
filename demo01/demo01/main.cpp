#include <osgViewer\Viewer>

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setUpViewInWindow(50, 50, 600, 480);
	viewer->realize();
	viewer->run();
	return 0;
}