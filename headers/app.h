#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>


#include "./audio.h"
#include "./window.h"       
#include "./inputs.h"
#include "./entities/sprite.h"


/****** Application *****/

class Application 
{

	public:

		//bool m_running = true;

		static Application* s_instance;

		//Window* m_winMgr;
		Audio* m_audioMgr;
		Inputs* m_inputMgr;

		//Sprite* background_image; 
		//Sprite* sprite; 

		std::thread m_window_thread;

	public:		
			
		Application();
	   ~Application();

		void update(bool &isRunning/* Window* &win */);

};