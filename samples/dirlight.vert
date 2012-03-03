void main()
{
	vec3 normal;
	vec3 lightDir;

	float NdotL;

	normal = normalize(gl_NormalMatrix * gl_Normal);
	lightDir = normalize(vec3(gl_LightSource[0].position));

	NdotL = max(dot(normal, lightDir), 0.0);
	gl_FrontColor = vec4(1.0,0.0,0.0,0.0) * NdotL;

	gl_Position = ftransform();
}
