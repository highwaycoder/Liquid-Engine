#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "DemoApplication.h"
#include "DemoEventHandler.h"

int main(int argc, char** argv)
{

	DemoApplication* app = new DemoApplication();

	EngineWindow* window = app->getWindowManager().createWindow();

	window->registerEventHandler(new DemoEventHandler());

	while (1)
	{
		app->run();
	}
}


