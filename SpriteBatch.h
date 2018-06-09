#pragma once
#include "CommonHeaders.h"
#include "Renderable.h"
class SpriteBatch
{
public:
	SpriteBatch();
	void Init();
	void Begin();
	void Submit(Renderable In);
	void End();
	void flush();
private:
	GLuint VAO, VBO;
	Vertex* m_buffer;
	int I_VertexCount;
	std::vector<Renderable> sprites;
private:
	static bool SortingTextures(Renderable ab, Renderable bc);
	void SortSprites();
	void RenderBatch(GLuint first, GLuint last, GLuint TexID);
};

