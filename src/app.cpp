	#pragma once

	#include "../headers/app.h"
	#include "../headers/entities/sprite.h"



    Application::Application()
	{

		bool m_isRunning = true;

	//// init app

		m_audioMgr = new Audio();
		m_inputMgr = new Inputs();

	//new thread for window / gui
	
		std::thread m_window_thread(&InitializeWindow, m_inputMgr); 
		m_window_thread.join();

												   
		
	};

	Application::~Application()
	{
		delete m_audioMgr;
		delete m_inputMgr;
		
		//std::terminate();

		Log::write("Application terminated");
	};



//----------------------- update

	void Application::update(bool &isRunning)
	{	
		while( isRunning == true )
		{			

	

		}
	}