#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>

#include "AssetModule/Vertex.h"
#include "AssetModule/Face.h"
#include "AssetModule/Model.h"
#include "AssetModule/ObjLoader.h"

#include "UIModule/UIModule.h"

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
	Model* model = loadObj("hex.obj");


	running = 1;


	//struct Bitmap bitmap = loadBMP("./samples/wood.bmp");
	//struct Targa targa = loadTGA("./samples/tex.tga");
	//glTexImage2D(GL_TEXTURE_2D, 0, 4, targa.header.image_specifications.image_width, targa.header.image_specifications.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, targa.pixel_data);
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, bitmap.info_header.width, bitmap.info_header.height, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap.pixel_data);

	startUIModule();

	while(running)
	{

	}

	closeUIModule();

}


