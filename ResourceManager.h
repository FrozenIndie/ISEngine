#pragma once
#include "CommonHeaders.h"
#include "Texture2D.h"
#include "stb_image.h"
#include <map>
class ResourceManager{
public:
	static std::map<char*, Texture2D> textures;
 static Texture2D LoadTexture(const char* filePath,const char* name) {
	 int width, height;
	 stbi_set_flip_vertically_on_load(true);
	 unsigned char* data = stbi_load(filePath, &width, &height, 0, STBI_rgb_alpha);
	 Texture2D tex;
	 tex.Generate(data, width, height);
	 textures[(char*)name] = tex;
	 return tex;
 }
inline static Texture2D GetTexture(char* name) {
	return textures[name];
}
};