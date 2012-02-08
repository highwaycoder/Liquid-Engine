#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>

#include "Vertex.h"
#include "Face.h"

#include "ModelLoader.h"
#include "BitmapLoader.h"
#include "TargaLoader.h"

#include "Targa.h"

int running = 0;

void init();
void render();
void close();

int window_width = 800;
int window_height = 800;
float aspect_ratio = ((float)window_height) / window_width;


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

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void handle_input()
{

}

void render()
{

	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -30.0f);

	//glColor3f(1.0f, 0.0f, 0.0f);


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

	//Model model = loadObj("container.obj");
	loadBMP("./samples/24bpp.bmp");
	struct Targa targa = loadTGA("./samples/wood-rle.tga");

	glGenTextures(1, &tex);

	glBindTexture(GL_TEXTURE_2D, tex);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, targa.header.image_specifications.image_width, targa.header.image_specifications.image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, targa.pixel_data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);



	while(running)
	{
		render();
		//model.render();

		glBindTexture(GL_TEXTURE_2D, tex);

		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();

		glfwSwapBuffers();
	}
}


