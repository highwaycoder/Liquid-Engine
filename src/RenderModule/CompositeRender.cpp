#include "CompositeRender.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include "stdio.h"

#include "AssetModule/ModelLoader.h"
#include "AssetModule/ImageLoader.h"

#include "Material.h"

#include "VertexShader.h"
#include "FragmentShader.h"
#include "AssetModule/ShaderSource.h"
#include "AssetModule/ModelMesh.h"

CompositeRender::CompositeRender()
{
	model = loadModel("../samples/monkey.obj");

	renderable = new StaticMeshRenderable(model);


	//Image* image = loadImage("../samples/tex.tga");

	//tex = new TextureSample2D(*image);

	printf("CREATED\n");

	Material* material = new Material();

	ShaderSource* shadersrc = new ShaderSource("../samples/flatten.vert");
	shadersrc->print();

	ShaderSource* shadersrc2 = new ShaderSource("../samples/color.frag");
	shadersrc2->print();


	VertexShader* shader = new VertexShader(shadersrc);
	FragmentShader* shader2 = new FragmentShader(shadersrc2);

	material->AttachShader(shader);
	material->LinkMaterial();

	material->AttachShader(shader2);
	material->LinkMaterial();

	material->UseMaterial();
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
	glTranslatef(0.0f, 0.0f, -14.0f);

	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_TEXTURE_2D);

	glDepthFunc(GL_LEQUAL);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(rot, 0.2f, 1.0f, 0.0f);

	rot = rot + 0.05;

	glColor3f(1.0f,1.0f,1.0f);

	//tex->useTexture();

	for (int i = 0; i < 1000; i++)
	{
		renderable->render();
	}

	glFlush();

}
