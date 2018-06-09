#include "SpriteBatch.h"



SpriteBatch::SpriteBatch() : I_VertexCount(0)
{
}


void SpriteBatch::Init()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoord));

	glBufferData(GL_ARRAY_BUFFER, 500 * sizeof(Vertex) * 6, NULL, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void SpriteBatch::Begin()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	m_buffer = (Vertex*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	
}

void SpriteBatch::Submit(Renderable In)
{
	sprites.push_back(In);
	m_buffer->Position = In.vertices[0].Position;
	m_buffer->TexCoord = In.vertices[0].TexCoord;
	m_buffer++;
	m_buffer->Position = In.vertices[1].Position;
	m_buffer->TexCoord = In.vertices[1].TexCoord;
	m_buffer++;
	m_buffer->Position = In.vertices[2].Position;
	m_buffer->TexCoord = In.vertices[2].TexCoord;
	m_buffer++;
	m_buffer->Position = In.vertices[3].Position;
	m_buffer->TexCoord = In.vertices[3].TexCoord;
	m_buffer++;
	m_buffer->Position = In.vertices[4].Position;
	m_buffer->TexCoord = In.vertices[4].TexCoord;
	m_buffer++;
	m_buffer->Position = In.vertices[5].Position;
	m_buffer->TexCoord = In.vertices[5].TexCoord;
	m_buffer++;
	I_VertexCount += 6;
}

void SpriteBatch::End()
{
	glUnmapBuffer(GL_ARRAY_BUFFER);
	SortSprites();
}

void SpriteBatch::flush()
{
	int end = 0;
	int start = 0;
	for (int i =0;i<sprites.size();i++)
	{
		if (i + 1 < sprites.size()) {
			if (sprites[i].img.GetID() == sprites[i + 1].img.GetID()) {
				end += 1;
			}
			else {
				end += 1;
				RenderBatch(start, end, sprites[i].img.GetID());
				start = 6;
			}
		}
		else {
			start = end;
			end += 1;
			RenderBatch(start, end, sprites[i].img.GetID());
		}
	}
	sprites.clear();
}

void SpriteBatch::SortSprites() {
	std::stable_sort(sprites.begin(), sprites.end(),&SpriteBatch::SortingTextures);

}

void SpriteBatch::RenderBatch(GLuint first, GLuint last, GLuint TexID)
{
	glBindTexture(GL_TEXTURE_2D, TexID);
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, first * 6, (last * 6) - (first * 6));
}

bool SpriteBatch::SortingTextures(Renderable ab, Renderable ac)
{
	return (ab.img.GetID() < ac.img.GetID());
}
