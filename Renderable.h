#pragma once
#include "CommonHeaders.h"
#include "Texture2D.h"
struct Vertex {
	glm::vec2 Position;
	glm::vec2 TexCoord;
};

class Renderable
{
public:
	Renderable();
	Vertex vertices[6];
	void ApplyMatrix(glm::mat4 input);
	void SetPosition(glm::vec2 in);
	void SetScale(glm::vec2 in);
	Texture2D img;
private:
	glm::vec2 Position, Scale;
};

