#include "OsgMainApp.hpp"
#include "crossnodegeode.h"
#include "AuxiliaryViewUpdater.h"
#include "GeometricVisObject.h"

#include <sstream>
#include <tigl.h>
#include <CCPACSConfigurationManager.h>
#include <CCPACSConfiguration.h>
#include <CCPACSWing.h>
#include <CCPACSWingSegment.h>
#include <CCPACSFuselage.h>
#include <CCPACSFuselageSegment.h>
#include <CTiglTriangularizer.h>

#define HOME_POS 80


OsgMainApp::OsgMainApp(){

    _lodScale = 1.0f;
    _prevFrame = 0;

    _initialized = false;
    _clean_scene = false;

}
OsgMainApp::~OsgMainApp(){

}
void OsgMainApp::addCross(osg::ref_ptr<CrossNode>& crossnode,osg::ref_ptr<osgViewer::Viewer> view , osg::Group* group ,
						  int x, int y, int w, int h)
{
    osg::ref_ptr<CrossNodeGeode> crossgeode = new CrossNodeGeode;
    crossnode = new CrossNode();
    crossnode->setViewport(y,y,h,h);
    crossnode->setProjectionMatrix(osg::Matrixd::ortho(-1.5, 1.5, -1.5, 1.5, -10.0, 10.0));
    crossnode->setCrossBody(crossgeode->initNodeGeode());
    crossnode->setMainCamera(view->getCamera());
    crossnode->setRenderOrder( osg::Camera::POST_RENDER );
    crossnode->setClearMask( GL_DEPTH_BUFFER_BIT );
    crossnode->setAllowEventFocus( false );
    crossnode->setReferenceFrame( osg::Transform::ABSOLUTE_RF );
    crossnode->setName("CrossNode");

    group->addChild(crossnode.get());

    osg::LightSource* lightSource = new osg::LightSource;
    lightSource->getLight()->setPosition(osg::Vec4d( 0.0f, 0.0f, 5.f, 1.0f )); // point light
    crossnode->addChild(lightSource);
}

void OsgMainApp::initOsgWindow(int x,int y,int width,int height){

	 __android_log_write(ANDROID_LOG_ERROR, "OSGANDROID",
	            "Initializing geometry");

	    _notifyHandler = new OsgAndroidNotifyHandler();
	    _notifyHandler->setTag("Osg Viewer");
	    osg::setNotifyHandler(_notifyHandler);


	    screenHeight = height * 1.0;
	    screenWidth = width * 1.0;

	    soleViewer = new osgViewer::Viewer();
	    soleViewer->setUpViewerAsEmbeddedInWindow(x,y,width,height);
	    soleViewer->getEventQueue()->setMouseInputRange(x,y,x+width,y+height);
	    soleViewer->getCamera()->setClearColor( osg::Vec4(98/255. * 1.1 , 166/255. * 1.1 , 1.0 , 1.0) );

	    tm = new osgGA::TrackballManipulator();
	    tm->setHomePosition(osg::Vec3(-HOME_POS,-HOME_POS,HOME_POS), osg::Vec3(20,0,0), osg::Vec3(0,0,1));


	   // cviewer = new osgViewer::CompositeViewer();
	   //osgViewer::GraphicsWindowEmbedded* _gwe = new osgViewer::GraphicsWindowEmbedded(x,y,width,height);

	    root_1 = new osg::Group();

	    // root_2 = new osg::Group();
	    // root_3 = new osg::Group();
	    // root_4 = new osg::Group();

	    // cviewer->setThreadingModel(osgViewer::CompositeViewer::SingleThreaded);

	    soleViewer->setCameraManipulator(tm);
	    soleViewer->realize();
	    addCross(crossnode1,soleViewer, root_1.get() , x , y , width/3, height/3);
	    soleViewer->setSceneData(root_1.get());

    	_state = root_1->getOrCreateStateSet();


	    _state->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	 	_state->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
	 	_state->setMode(GL_CULL_FACE, osg::StateAttribute::ON);


	 	soleViewer->addEventHandler(new osgViewer::StatsHandler);

	    // cviewer->addView(createView(x,height/2,width/2,height/2,_gwe,1));
	    // cviewer->addView(createView(x,y,width/2,height/2,_gwe,2));
	    // cviewer->addView(createView(width/2,y,width/2,height/2,_gwe,4));
	    // cviewer->addView(createView(width/2,height/2,width/2,height/2,_gwe,3));


	    vvo = new VirtualVisObject();
	    root_1->addChild(vvo->main.get());


	    // root_2->addChild(vvo->main.get());
	    // root_3->addChild(vvo->main.get());
	    // root_4->addChild(vvo->main.get());

	    _initialized = true;
}

/*
osgViewer::View* OsgMainApp::createView(int x, int y, int width, int height
							,osgViewer::GraphicsWindowEmbedded* _gwe, int id)
{
	osgViewer::View* _viewer = new osgViewer::View;

	osgGA::TrackballManipulator* tm = new osgGA::TrackballManipulator();
	osgGA::TrackballManipulator* tm1 = new osgGA::TrackballManipulator();
	osgGA::TrackballManipulator* tm2 = new osgGA::TrackballManipulator();
	osgGA::TrackballManipulator* tm3 = new osgGA::TrackballManipulator();
	tm->setHomePosition(osg::Vec3(300,300,300), osg::Vec3(0,0,0), osg::Vec3(0,0,1));
	tm1->setHomePosition(osg::Vec3(0,300,0), osg::Vec3(0,0,0), osg::Vec3(0,0,1));
	tm2->setHomePosition(osg::Vec3(-300,0,0), osg::Vec3(0,0,0), osg::Vec3(0,0,1));
	tm3->setHomePosition(osg::Vec3(0,0,300), osg::Vec3(0,0,0), osg::Vec3(0,0,1));

	 osg::ref_ptr<osg::Camera> _camera = _viewer->getCamera();
	_camera->setViewport(new osg::Viewport(x,y,width,height));
    _camera->setGraphicsContext(_gwe);

    switch(id)
    {
    case(1):
	{
    	addCross(crossnode1,_viewer, root_1.get() , x , y , width/4, height/4);
    	_viewer->setSceneData(root_1.get());
    	_state = root_1->getOrCreateStateSet();
    	//_camera->setViewMatrixAsLookAt(osg::Vec3(300,300,300), osg::Vec3(0,0,0), osg::Vec3(0,0,1));
    	_viewer->setCameraManipulator( tm );
    	break;
	}
    case(2):
	{
    	addCross(crossnode2,_viewer, root_2.get(), x , y , width/4, height/4);
    	_viewer->setSceneData(root_2.get());
    	_state = root_2->getOrCreateStateSet();
    	_camera->setViewMatrixAsLookAt(osg::Vec3(-300,0,0), osg::Vec3(0,0,0),osg::Vec3(0,0,1));
    	_viewer->addEventHandler(new AuxiliaryViewUpdater());
    	break;
	}
    case(3):
	{
    	addCross(crossnode3,_viewer, root_3.get(), x , y , width/4, height/4);
    	_viewer->setSceneData(root_3.get());
    	_state = root_3->getOrCreateStateSet();
    	_camera->setViewMatrixAsLookAt(osg::Vec3(0,300,0), osg::Vec3(0,0,0),osg::Vec3(0,0,1));
    	_viewer->addEventHandler(new AuxiliaryViewUpdater());
    	break;
	}
    case(4):
	{
    	addCross(crossnode4,_viewer, root_4.get(), x , y , width/4, height/4);
    	_viewer->setSceneData(root_4.get());
    	_state = root_4->getOrCreateStateSet();
    	_camera->setViewMatrixAsLookAt(osg::Vec3(0,0,300), osg::Vec3(0,0,0),osg::Vec3(0,1,0));
    	_viewer->addEventHandler(new AuxiliaryViewUpdater());
    	break;
	}

    }

    _state->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	_state->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
	_state->setMode(GL_CULL_FACE, osg::StateAttribute::ON);


    _viewer->addEventHandler(new osgViewer::StatsHandler);
	_viewer->addEventHandler(new osgGA::StateSetManipulator(_viewer->getCamera()->getOrCreateStateSet()));
	_viewer->addEventHandler(new osgViewer::ThreadingHandler);
	_viewer->addEventHandler(new osgViewer::LODScaleHandler);

	return _viewer;

}
*/
//Draw
void OsgMainApp::draw(){
    currentCamera();
    soleViewer->frame();
}
//Events
void OsgMainApp::addObjectFromVTK(std::string filepath)
{
	osg::notify(osg::ALWAYS)<<"opening wing from VTK"<<std::endl;

	osg::ref_ptr<GeometricVisObject> geode = new GeometricVisObject;
	geode->readVTK(filepath.c_str());
	geode->setName(filepath);

    root_1->addChild(geode.get());

}
void OsgMainApp::addObjectFromCPACS(std::string filepath)
{
		osg::notify(osg::ALWAYS)<<"opening wing from Tigl"<<std::endl;
	 	TixiDocumentHandle handle = -1;
	    TiglCPACSConfigurationHandle tiglHandle = -1;

	    if(tixiOpenDocument(filepath.c_str(), &handle ) != SUCCESS){
	    }
	    if(tiglOpenCPACSConfiguration(handle, "", &tiglHandle) != TIGL_SUCCESS) {
	    	osg::notify(osg::ALWAYS) << "Error opening cpacs file " << filepath << std::endl;
	    }

	    tigl::CCPACSConfigurationManager & manager = tigl::CCPACSConfigurationManager::GetInstance();
	    tigl::CCPACSConfiguration & config = manager.GetConfiguration(tiglHandle);

	    double tesselationAccu = 0.01;

	    for (int iWing = 1; iWing <= config.GetWingCount(); ++iWing)  {
		    tigl::CCPACSWing& wing = config.GetWing(iWing);

		    for(int iSegment = 1; iSegment <=  wing.GetSegmentCount(); ++iSegment) {
		    	tigl::CCPACSWingSegment& segment = (tigl::CCPACSWingSegment &) wing.GetSegment(iSegment);
		    	osg::notify(osg::ALWAYS)<<"Meshing Wing Segment "<< iSegment << std::endl;
		    	tigl::CTiglTriangularizer t(segment.GetLoft(), tesselationAccu);

		    	std::stringstream stream;
		    	stream << "Wing" << iWing << "_Segment" << iSegment;
			    osg::ref_ptr<GeometricVisObject> geode = new GeometricVisObject;
			    geode->readTiglPolydata(t);
			    geode->setName(stream.str().c_str());
			    root_1->addChild(geode.get());
		    }

			if(wing.GetSymmetryAxis() == TIGL_NO_SYMMETRY)
				continue;

			for (int i = 1; i <= wing.GetSegmentCount(); i++)
			{
				tigl::CCPACSWingSegment& segment = (tigl::CCPACSWingSegment &) wing.GetSegment(i);
		    	TopoDS_Shape loft = segment.GetMirroredLoft();
				tigl::CTiglTriangularizer t(loft, tesselationAccu);

		    	std::stringstream stream;
		    	stream << "Wing" << iWing << "_Segment" << i << "_mirrored";
			    osg::ref_ptr<GeometricVisObject> geode = new GeometricVisObject;
			    geode->readTiglPolydata(t);
			    geode->setName(stream.str().c_str());
			    root_1->addChild(geode.get());
			}

	    }

	    for (int f = 1; f <= config.GetFuselageCount(); f++) {
	    	tigl::CCPACSFuselage& fuselage = config.GetFuselage(f);

	    	for (int i = 1; i <= fuselage.GetSegmentCount(); i++) {
	    		tigl::CCPACSFuselageSegment& segment = (tigl::CCPACSFuselageSegment &) fuselage.GetSegment(i);
	    		TopoDS_Shape loft = segment.GetLoft();

	    		// Transform by fuselage transformation
	    		loft = fuselage.GetFuselageTransformation().Transform(loft);
	    		osg::notify(osg::ALWAYS)<<"Meshing Fuselage Segment "<< i << std::endl;
	    		try {
	    			tigl::CTiglTriangularizer t(loft, tesselationAccu);
					osg::notify(osg::ALWAYS)<<"Done meshing segment "<< i << std::endl;
					std::stringstream stream;
					stream << "Fuselage" << f << "_Segment" << i;
					osg::ref_ptr<GeometricVisObject> geode = new GeometricVisObject;
				    geode->readTiglPolydata(t);
				    geode->setName(stream.str().c_str());
					root_1->addChild(geode.get());
					osg::notify(osg::ALWAYS)<<"Done adding segment "<< i << std::endl;
	    		}
	    		catch(...){
	    			osg::notify(osg::ALWAYS)<<"Error: could not triangularize fuselage segment "<< i << std::endl;
	    		}
	    	}
	    }

}
void OsgMainApp::removeObjects()
{
	root_1->removeChildren(2,root_1->getNumChildren());
}
void OsgMainApp::currentCamera()
{

	 if(viewSelected == 0)
		{
			osgGA::TrackballManipulator* tm1 = new osgGA::TrackballManipulator();
			tm1->setHomePosition(osg::Vec3(-HOME_POS,-HOME_POS,HOME_POS), osg::Vec3(20,0,0), osg::Vec3(0,0,1));
			soleViewer->setCameraManipulator(tm1);

			viewSelected = -1;
		}
		else if(viewSelected ==1)
		{
			osgGA::TrackballManipulator* tm1 = new osgGA::TrackballManipulator();
			tm1->setHomePosition(osg::Vec3(20,0,HOME_POS), osg::Vec3(20,0,0), osg::Vec3(0,0,1));
			soleViewer->setCameraManipulator(tm1);

			viewSelected = -1;
		}
		else if(viewSelected == 2)
		{
			osgGA::TrackballManipulator* tm1 = new osgGA::TrackballManipulator();
			tm1->setHomePosition(osg::Vec3(20,HOME_POS,0), osg::Vec3(20,0,0), osg::Vec3(0,0,1));
			soleViewer->setCameraManipulator(tm1);

			viewSelected = -1;
		}
		else if(viewSelected == 3)
		{
			osgGA::TrackballManipulator* tm1 = new osgGA::TrackballManipulator();
			tm1->setHomePosition(osg::Vec3(-HOME_POS,0,0), osg::Vec3(0,0,0), osg::Vec3(0,0,1));
			soleViewer->setCameraManipulator(tm1);

			viewSelected = -1;
		}

}
void OsgMainApp::changeCamera(int view)
{
	viewSelected = view;

}
void OsgMainApp::mouseButtonPressEvent(float x,float y,int button, int view)
{
	soleViewer->getEventQueue()->mouseButtonPress(x,y,button);
//	if(view == 1)
//	cviewer->getView(0)->getEventQueue()->mouseButtonPress(x, y, button);
//	if(view == 2)
//	cviewer->getView(1)->getEventQueue()->mouseButtonPress(x, y, button);
//	if(view == 3)
//	cviewer->getView(2)->getEventQueue()->mouseButtonPress(x, y, button);
//	if(view == 4)
//	cviewer->getView(3)->getEventQueue()->mouseButtonPress(x, y, button);

}
void OsgMainApp::mouseButtonReleaseEvent(float x,float y,int button, int view){

	soleViewer->getEventQueue()->mouseButtonRelease(x ,y,button);
//	if(view == 1)
//	cviewer->getView(0)->getEventQueue()->mouseButtonRelease(x, y, button);
//	if(view == 2)
//	cviewer->getView(1)->getEventQueue()->mouseButtonRelease(x, y, button);
//	if(view == 3)
//	cviewer->getView(2)->getEventQueue()->mouseButtonRelease(x, y, button);
//	if(view == 4)
//	cviewer->getView(3)->getEventQueue()->mouseButtonRelease(x, y, button);

}
void OsgMainApp::mouseMoveEvent(float x,float y, int view){

	soleViewer->getEventQueue()->mouseMotion(x,y);
//	if(view == 1)
//	cviewer->getView(0)->getEventQueue()->mouseMotion(x, y);
//	if(view == 2)
//	cviewer->getView(1)->getEventQueue()->mouseMotion(x, y);
//	if(view == 3)
//	cviewer->getView(2)->getEventQueue()->mouseMotion(x, y);
//	if(view == 4)
//	cviewer->getView(3)->getEventQueue()->mouseMotion(x, y);

}
