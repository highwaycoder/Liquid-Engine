#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>

#include "AssetModule/Vertex.h"
#include "AssetModule/Face.h"
#include "AssetModule/Model.h"
#include "AssetModule/ObjLoader.h"

#include "UIModule/control.h"

int running = 0;

void init();
void render();
void close();

int window_width = 800;
int window_height = 800;
float aspect_ratio = ((float)window_height) / window_width;
float angle = 0.0;

void init()
{

	if (glfwInit() != GL_TRUE)
		close();

	if (glfwOpenWindow(window_width, window_height, 5, 6, 5, 0, 0, 0, GLFW_WINDOW) != GL_TRUE)
		close();


	glfwSetWindowTitle("Render");


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, aspect_ratio, 0.1f, 40.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void handle_input()
{

}

void render()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -30.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	angle = angle + 0.05;


}

void close()
{
	glfwTerminate();
	running = 0;
}

int main(int argc, char** argv)
{

	running = 1;

	init();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	GLuint tex;

	Model model = loadObj("container.obj");
	//struct Bitmap bitmap = loadBMP("./samples/wood.bmp");
	//struct Targa targa = loadTGA("./samples/tex.tga");

	glGenTextures(1, &tex);

	glBindTexture(GL_TEXTURE_2D, tex);

	//glTexImage2D(GL_TEXTURE_2D, 0, 4, targa.header.image_specifications.image_width, targa.header.image_specifications.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, targa.pixel_data);
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, bitmap.info_header.width, bitmap.info_header.height, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap.pixel_data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	show();

	while(running)
	{
		render();
		//model.render();

		glBindTexture(GL_TEXTURE_2D, tex);

		//glBegin(GL_QUADS);
		//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
		//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
		//	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
		//	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		//glEnd();

		glfwSwapBuffers();
	}
}


