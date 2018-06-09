#include "Texture2D.h"



Texture2D::Texture2D()
{
}


Texture2D::~Texture2D()
{
}

void Texture2D::Generate(unsigned char * Data, int width, int height)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, GetID());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);
	glGenerateMipmap(GL_TEXTURE_2D);
	UnBind();
}
void Texture2D::Bind() {
	glBindTexture(GL_TEXTURE_2D, ID);
}
void Texture2D::UnBind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}
