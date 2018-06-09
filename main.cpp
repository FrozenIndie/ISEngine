#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include "Window.h"
#include "Game.h"
int main(int argc,char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	Window window("ISEngnie", 800, 600);
	window.Create();
	Game game;
	game.InitSystems();
	game.InitGame();
	game.InitEntities();
	game.PreRender();
	bool Looping = true;
	SDL_Event* e = new SDL_Event();
	while (Looping) {
		game.Render(window.m_window,&Looping,*e);
	}
	return 0;
}