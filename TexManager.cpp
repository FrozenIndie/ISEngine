#include "TexManager.h"



TexManager::TexManager()
{
}


TexManager::~TexManager()
{
}
Texture2D TexManager::LoadTexture(const char* filePath, const char* name) {
	int width, height;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filePath, &width, &height, 0, STBI_rgb_alpha);
	Texture2D tex;
	tex.Generate(data, width, height);
	textures[(char*)name] = tex;
	return tex;
}
Texture2D TexManager::GetTexture(char* name) {
	return textures[name];
}