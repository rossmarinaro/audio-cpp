#pragma once

#include <windows.h>
#include <string>
#include <SDL.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h> 

#if defined(IMGUI_IMPL_OPENGL_ES2)   
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif

#include "./app.h"
#include "./inputs.h"
#include "./logs.h"

#include "../vendors/imgui/imgui.h"
#include "../vendors/imgui/imgui_impl_sdl.h"
#include "../vendors/imgui/imgui_impl_opengl3.h"


void InitializeWindow(Inputs* inputs);

