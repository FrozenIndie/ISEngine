#pragma once
#include "glm\glm.hpp"
#include "glm\common.hpp"
#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <algorithm>
class Texture2D
{
public:
	Texture2D();
	~Texture2D();
private:
	GLuint ID;
public:
	inline GLuint GetID() { return ID; };
	void Generate(unsigned char* Data,int width,int height);
	void Bind();
	void UnBind();
};

