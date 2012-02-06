#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>

#include "Vertex.h"
#include "Face.h"

#include "ModelLoader.h"

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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void handle_input()
{

}

void render()
{

	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -10.0f);

	glColor3f(1.0f, 0.0f, 0.0f);


}

void close()
{
	glfwTerminate();
	running = 0;
}

int main(int argc, char** argv)
{
	Model model = loadObj("cyl.obj");

	running = 1;

	init();

	while(running)
	{
		render();
		model.render();

		glfwSwapBuffers();
	}
}


