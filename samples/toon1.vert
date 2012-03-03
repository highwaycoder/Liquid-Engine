varying vec3 normal;
varying vec3 lightDir;

void main(void)
{
	lightDir = vec3(gl_LightSource[0].position);

	normal = gl_NormalMatrix * gl_Normal;
	gl_Position = ftransform();
}

