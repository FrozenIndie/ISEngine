#pragma once
#include  "CommonHeaders.h"
class Window
{
public:
	Window(const char* name, int width, int height);
	~Window();
	void Create();
	SDL_Window* m_window;

private:
	const char* m_name;
	int m_width, m_height;
};

