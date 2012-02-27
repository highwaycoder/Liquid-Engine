#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


#include <GL/gl.h>
#include <GL/glu.h>

#include "DemoApplication.h"
#include "DemoEventHandler.h"

#include "AssetModule/ModelLoader.h"
#include "AssetModule/ImageLoader.h"

int main(int argc, char** argv)
{

	DemoApplication* app = new DemoApplication();
	EngineWindow* window = app->getWindowManager().createWindow();
	window->registerEventHandler(new DemoEventHandler());


	//loadModel("../samples/container.obj");

	while (1)
	{
		app->run();
	}
}


