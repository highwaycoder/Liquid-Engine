#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>

#include "AssetModule/Vertex.h"
#include "AssetModule/Face.h"
#include "AssetModule/Model.h"
#include "AssetModule/ObjLoader.h"


#include "RenderModule/CompositeRender.h"

#include "UIModule/EngineWindowManager.h"
#include "UIModule/EngineWindow.h"

#include <SFML/Window.hpp>

int running = 0;

void init();
void render();
void close();

int window_width = 800;
int window_height = 800;
float aspect_ratio = ((float)window_height) / window_width;
float angle = 0.0;


void render()
{
	//glClearColor(0.0, 0.0, 0.0, 1.0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glLoadIdentity();

	//glTranslatef(0.0f, 0.0f, -30.0f);

	//glRotatef(angle, 0.0f, 1.0f, 0.0f);
	//angle = angle + 0.05;
}

void close()
{
	running = 0;
}

int main(int argc, char** argv)
{
	//Model* model = loadObj("hex.obj");


	running = 1;

	//sf::Window App(sf::VideoMode(800, 600, 32), "SFML OpenGL");
	//sf::Window App2(sf::VideoMode(800, 600, 32), "SFML OpenGL");

	//struct Bitmap bitmap = loadBMP("./samples/wood.bmp");
	//struct Targa targa = loadTGA("./samples/tex.tga");
	//glTexImage2D(GL_TEXTURE_2D, 0, 4, targa.header.image_specifications.image_width, targa.header.image_specifications.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, targa.pixel_data);
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, bitmap.info_header.width, bitmap.info_header.height, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap.pixel_data);

	//startUIModule();


	// Set color and depth clear value
	glClearDepth(1.f);
	glClearColor(1.f, 0.f, 0.f, 0.f);

	// Enable Z-buffer read and write
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 500.f);

	CompositeRender* render = new CompositeRender;

	EngineWindowManager manager;

	manager.createWindow();

	while(1)
	{
		manager.processWindows();
	}

	//closeUIModule();

}


