#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <fstream>
#include <sstream>

class Shader
{
public:
	Shader(const char* a_VertexFilePath, const char* a_FragmentFilePath);
	~Shader();
	void Init();
	GLuint _ShaderID;
	void Use();
private:
	GLuint _FragmentShaderID, _VertexShaderID;
	const char* VertexFilePath;
	const char* FragmentFilePath;
};