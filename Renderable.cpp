#include "Renderable.h"

#pragma region VertexShit
/*
0.5f, 0.5f, 0.0f,  // top right
0.5f, -0.5f, 0.0f,  // bottom right
-0.5f, 0.5f, 0.0f,  // top left 
					// second triangle
0.5f, -0.5f, 0.0f,  // bottom right
-0.5f, -0.5f, 0.0f,  // bottom left
-0.5f, 0.5f, 0.0f   // top left
*/
#pragma endregion 
Renderable::Renderable()
{
	vertices[0].Position = glm::vec2(0.5f, 0.5f);
	vertices[0].TexCoord = glm::vec2(1.0f, 1.0f);

	vertices[1].Position = glm::vec2(0.5f, -0.5f);
	vertices[1].TexCoord = glm::vec2(1.0f, 0.0f);
	
	vertices[2].Position = glm::vec2(-0.5f, 0.5f);
	vertices[2].TexCoord = glm::vec2(0.0f, 1.0f);

	vertices[3].Position = glm::vec2(0.5f, -0.5f);
	vertices[3].TexCoord = glm::vec2(1.0f, 0.0f);

	vertices[4].Position = glm::vec2(-0.5f, -0.5f);
	vertices[4].TexCoord = glm::vec2(0.0f, 0.0f);
	
	vertices[5].Position = glm::vec2(-0.5f, 0.5f);
	vertices[5].TexCoord = glm::vec2(0.0f, 1.0f);
}

void Renderable::ApplyMatrix(glm::mat4 input)
{
	vertices[0].Position = glm::vec4(0.5f, 0.5f,0,1) * input;

	vertices[1].Position = glm::vec4(0.5f, -0.5f,0,1)* input;
								   
	vertices[2].Position = glm::vec4(-0.5f, 0.5f,0,1)* input;
								   
	vertices[3].Position = glm::vec4(0.5f, -0.5f,0,1)* input;
								   
	vertices[4].Position = glm::vec4(-0.5f, -0.5f,0,1)* input;
								   
	vertices[5].Position = glm::vec4(-0.5f, 0.5f,0,1)* input;

}

void Renderable::SetPosition(glm::vec2 in)
{
	Position = in;

	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(400, 60, -3.0f));

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model,in);
	model = glm::scale(model, glm::vec3(200, 200, 0));


	glm::mat4 input = projection * view * model;
	

	vertices[0].Position = glm::vec4(0.5f, 0.5f, 0, 1) * input;

	vertices[1].Position = glm::vec4(0.5f, -0.5f, 0, 1)* input;

	vertices[2].Position = glm::vec4(-0.5f, 0.5f, 0, 1)* input;

	vertices[3].Position = glm::vec4(0.5f, -0.5f, 0, 1)* input;

	vertices[4].Position = glm::vec4(-0.5f, -0.5f, 0, 1)* input;

	vertices[5].Position = glm::vec4(-0.5f, 0.5f, 0, 1)* input;


}

void Renderable::SetScale(glm::vec2 input)
{
}

