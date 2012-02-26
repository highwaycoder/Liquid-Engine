#include "CompositeRender.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include "stdio.h"

#include "AssetModule/ModelLoader.h"

CompositeRender::CompositeRender()
{
	model = loadModel("../samples/monkey.obj");

	renderable = new StaticMeshRenderable(model);
}

void CompositeRender::Render()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, 1.0, 0.1f, 40.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -4.0f);

	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	//rot = rot + 0.05;

	printf("no %i\n", model->getTriangleCount());

	glColor3f(1.0f,1.0f,1.0f);

	renderable->render();

	for (int face = 0; face < model->getTriangleCount(); face++)
	{
		printf("Face: %i of %i\n\n", face, model->getTriangleCount());
	}

	glFlush();
}
