#pragma once
#include "CommonHeaders.h"

#include "Shader.h"
#include "Renderable.h"
#include "SpriteBatch.h"

class Game
{
public:
	Game();
	~Game();
	void InitGame();
	void InitSystems();
	void InitEntities();
	void PreRender();
	void Render(SDL_Window * m_win, bool *LoopingCondition, SDL_Event e);

//Testing Part
private:

	Shader * x;
	Renderable* SpriteTest;
	SpriteBatch sb;
};

