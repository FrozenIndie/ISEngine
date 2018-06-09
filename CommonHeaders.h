#pragma once
#include "glm\glm.hpp"
#include "glm\common.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <algorithm>
#include "TexManager.h"
#include <vector>
inline static void m_log(const char * message, const char* TheSendingSystem = "") {
	std::cout << "[*] " << TheSendingSystem << " : " << message << std::endl;
};
static TexManager TM;
static bool Running;