#pragma once
#include "Texture2D.h"
#include <map>
#include "stb_image.h"
class TexManager
{
public:
	TexManager();
	~TexManager();
	 std::map<char*, Texture2D> textures;

public:
	Texture2D LoadTexture(const char* filePath, const char* name);
	Texture2D GetTexture(char* name);
};

