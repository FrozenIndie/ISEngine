#include "Window.h"



Window::Window(const char* name, int width, int height)
{
	m_name = name;
	m_width = width;
	m_height = height;

}


Window::~Window()
{
}

void Window::Create() {
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow(m_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GLContext glContext = SDL_GL_CreateContext(m_window);
}