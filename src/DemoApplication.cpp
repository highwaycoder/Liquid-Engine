#include "DemoApplication.h"

DemoApplication::DemoApplication() : EngineApplication()
{
	
}

void DemoApplication::run()
{
	getWindowManager().dispatchEvents();

	getWindowManager().renderFrames();
}
