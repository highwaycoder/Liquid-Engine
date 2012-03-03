#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "AssetModule/ModelLoader.h"
#include "AssetModule/ImageLoader.h"

#include "AssetModule/ShaderSource.h"
#include "RenderModule/VertexShader.h"

#include "RenderModule/CompositeRender.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include <SFML/Window.hpp>

int main(int argc, char** argv)
{
	sf::Window App(sf::VideoMode(800, 600, 32), "SFML OpenGL");

	CompositeRender c;

	const unsigned char* version = glGetString(GL_VERSION);

	printf("OpenGL Version: %s\n", version);

	App.UseVerticalSync(false);

	App.SetActive();

	float Framerate;

	while(App.IsOpened())
	{
		c.Render();
		App.Display();

		Framerate = 1.f / App.GetFrameTime();

		if (Framerate > 2000)
			printf("FPS: %f\n", Framerate);
	}
}


