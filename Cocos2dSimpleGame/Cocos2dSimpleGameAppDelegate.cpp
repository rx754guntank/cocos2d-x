// Application application cpp file.
 
// Original file name: cocosTemplateApp.cpp
// Generated by TOPS Builder:Project wizard,Date:2010-09-27
 
#include "Cocos2dSimpleGameAppDelegate.h"
#include "HelloWorldScene.h"
#include "Resource.h"

using namespace cocos2d;
extern const AppResourceEntry Cocos2dSimpleGameResourceEntry;

// the works are the same as NSObject<UIApplicationDelegate>::applicationDidFinishLaunching of cocos2d-iphone
bool AppDelegate::initCocos2d()
{
	// init director
	CCDirector *pDirector = CCDirector::getSharedDirector();
	pDirector->setOpenGLView(m_pMainWnd);

	// sets landscape mode
	pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);

	// turn on display FPS
	pDirector->setDisplayFPS(true);

    // set the ResourceEntry and Images ResInfo (name and ResID)
    CCFileUtils::setResourceEntry(&Cocos2dSimpleGameResourceEntry);
    CCFileUtils::setResourceInfo(ResInfo, sizeof(ResInfo) / sizeof(T_ResourceInfo));

    // set the ResourceEntry and sound ResInfo (filename and ResID)
    SimpleAudioEngine::getSharedEngine()->setResourceEntry(&Cocos2dSimpleGameResourceEntry);
    SimpleAudioEngine::getSharedEngine()->setSoundResInfo(SoundResInfo, sizeof(SoundResInfo) / sizeof(T_SoundResInfo));

	// create a scene. it's an autorelease object
	CCScene *pScene = HelloWorld::scene();

	// run
	CCDirector::getSharedDirector()->runWithScene(pScene);

	return true;
}

AppDelegate::AppDelegate()
:m_rcWnd(0, 0, GetScreenWidth(), GetScreenHeight())
,m_pMainWnd(NULL)
{

}

AppDelegate::~AppDelegate()
{

}

Boolean  AppDelegate::EventHandler(EventType*  pEvent)
{
	Boolean bHandled = FALSE;

	switch(pEvent->eType)
	{
	case EVENT_AppLoad:
		{
			// it's important to use CCXEGLView, or you may inherit it to add your implement
			if (! (m_pMainWnd = new CCXEGLView(this)) || ! m_pMainWnd->Create(&m_rcWnd))
			{
        		// create window failed, quit application
				SendStopEvent();
				bHandled = TRUE;
				break;
			}
			SetActiveWindow(m_pMainWnd);
			// do not return bHandle equal TRUE, CCXApplication::EventHandler need do some thing.
			break;
		}
		bHandled = TRUE;
		break;

	case EVENT_AppStopNotify:
		{
			
		}
		bHandled = FALSE;
		break;
	}

	return (bHandled) ? TRUE : CCXApplication::EventHandler(pEvent);
}