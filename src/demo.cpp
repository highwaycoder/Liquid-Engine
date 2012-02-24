#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "DemoApplication.h"
#include "DemoEventHandler.h"

#include "AssetModule/MD2Model.h"

int main(int argc, char** argv)
{

	//DemoApplication* app = new DemoApplication();
	//EngineWindow* window = app->getWindowManager().createWindow();
	//window->registerEventHandler(new DemoEventHandler());

	MD2Model model;
	model.load("../samples/cube.md2");

	printf("Size of Model: %i\n", sizeof(model));

	while (1)
	{
		//app->run();
	}
}


