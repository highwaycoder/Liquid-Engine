#include "CompositeRender.h"

#include <GL/gl.h>
#include <GL/glu.h>

CompositeRender::CompositeRender()
{

}

void CompositeRender::Render()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 25, 25);
 
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
		glColor3f(0.4, 0.5, 0.4);
		glVertex2f(0.0, -0.8);
	glEnd();
 
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(0.1, 0.1);
		glVertex2f(-0.1, 0.1);
		glVertex2f(-0.1, -0.1);
		glVertex2f(0.1, -0.1);
	glEnd();

	glFlush();
}
