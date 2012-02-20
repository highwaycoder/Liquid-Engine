#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "EngineModule/EngineWindowManager.h"
#include "EngineModule/EngineWindow.h"


int main(int argc, char** argv)
{

	EngineWindowManager manager;

	manager.createWindow();

	while(1)
	{
		manager.processWindows();
	}
}


