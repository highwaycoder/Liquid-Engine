#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "DemoApplication.h"
#include "DemoEventHandler.h"

#include "AssetModule/ModelLoader.h"
#include "AssetModule/ImageLoader.h"

#include "AssetModule/ShaderSource.h"
#include "RenderModule/VertexShader.h"

#include <GL/gl.h>
#include <GL/glu.h>

int main(int argc, char** argv)
{

	DemoApplication* app = new DemoApplication();
	EngineWindow* window = app->getWindowManager().createWindow();
	window->registerEventHandler(new DemoEventHandler());

	//ShaderSource* shadersrc = new ShaderSource("../samples/flatten.vert");
	//shadersrc->print();

	//VertexShader* shader = new VertexShader(shadersrc);

	//loadModel("../samples/container.obj");

	while (1)
	{
		app->run();
	}
}


