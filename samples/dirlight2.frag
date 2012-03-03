varying vec3 normal;

void main()
{
	float NdotL;
	vec3 lightDir;

	lightDir = normalize(vec3(gl_LightSource[0].position));


	NdotL = max(dot(normal, lightDir), 0.0);

	gl_FragColor = vec4(1.0,1.0,1.0,0.0) * NdotL;

}

