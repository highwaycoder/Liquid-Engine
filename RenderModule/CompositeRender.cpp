#include "CompositeRender.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include "stdio.h"

CompositeRender::CompositeRender()
{

}

void CompositeRender::Render()
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0, 200, 200, 0, -1, 1 );

	glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

	glClearColor(1.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
 
	glBegin( GL_QUADS );
    
		glColor4f( 1.0, 1.0, 0.0, 1.0 );

		glVertex3f( 0,            0,             0 );
		glVertex3f( 20, 0,             0 );
		glVertex3f( 20, 20, 0 );
		glVertex3f( 0,            20, 0 );

	glEnd();

	glFlush();
}
