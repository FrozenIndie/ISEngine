#include "Game.h"
Renderable* TexTest;
Game::Game()
{
	SpriteTest = new Renderable();
	TexTest = new Renderable();
	x = new Shader("coloring.vert", "coloring.frag");
}


Game::~Game()
{
}

void Game::InitGame()
{

}

void Game::InitSystems()
{

	glewInit();
	m_log("Glew Has Initialized", "InitSystems()");

}

void Game::InitEntities()
{
	x->Init();
	SpriteTest->img = TM.LoadTexture("Container.jpg", "first");
	TexTest->img = TM.LoadTexture("Tile.png", "second");
	
	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(400, 60, -3.0f));
	
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(200, 0, 0));
	model = glm::scale(model, glm::vec3(200, 200, 0));
	glm::mat4 MVP = projection * view * model;
	TexTest->ApplyMatrix(MVP);
	sb.Init();
}

void Game::PreRender()
{
}

void Game::Render(SDL_Window * m_win, bool * LoopingCondition, SDL_Event e)
{
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT) {
		m_log("Got Closed", "WINDOW_HANDLING");
		*LoopingCondition = false;
	}

	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	x->Use();
	sb.Begin();

	sb.Submit(*SpriteTest);
	sb.Submit(*TexTest);
	sb.End();
	sb.flush();
	SDL_GL_SwapWindow(m_win);
}
