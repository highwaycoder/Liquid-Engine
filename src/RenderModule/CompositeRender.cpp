#include "CompositeRender.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include "stdio.h"

#include "AssetModule/ModelLoader.h"
#include "AssetModule/ImageLoader.h"

CompositeRender::CompositeRender()
{
	model = loadModel("../samples/monkey.obj");

	renderable = new StaticMeshRenderable(model);


	Image* image = loadImage("../samples/tex.tga");

	tex = new TextureSample2D(*image);

	printf("CREATED\n");

	//glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//glGenTextures(1, &m_gltexture_handle);

	//glBindTexture(GL_TEXTURE_2D, m_gltexture_handle);

	//if (image->getBPP() == 32)
	{
	//	printf("fuck\n");
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->getWidth(), image->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image->getData());
	}	
	//else if (image->getBPP() == 24)
	{
	//	printf("shit\n");
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->getWidth(), image->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image->getData());
	}

	//glTexImage2D(GL_TEXTURE_2D, 0, 4, 1024, 1024, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->getData());

	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}

void CompositeRender::Render()
{
	GLenum error;

	//printf("frame\n");

	if (error = glGetError())
	{
		const unsigned char* errstring = gluErrorString(error);
		printf("Error: %s\n\n", errstring);
		exit(0);
	}

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, 1.0, 0.1f, 40.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -34.0f);

	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_TEXTURE_2D);

	//glDepthFunc(GL_LEQUAL);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(rot, 0.2f, 1.0f, 0.0f);

	rot = rot + 0.05;

	glColor3f(1.0f,1.0f,1.0f);

	tex->useTexture();

	renderable->render();


	glFlush();

}
