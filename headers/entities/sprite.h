#pragma once

#include "./image.h"

///------------------- Sprite 


class Sprite : public Image {

    private:

	//anims enumerations / parsing

		enum anims {
			jump, 
			walk,
			idle
		};

		anims parseString(std::string const &string)
		{
			if (string == "jump") return jump;
			if (string == "walk") return walk;
			if (string == "idle") return idle;
		}

	public:  

		std::int64_t
				m_frame = 1, 
				m_currentFrameX,
				m_currentFrameY,
				m_currentFrameWidth,
				m_currentFrameHeight;
		
		float m_scaleX = 0.5f,
			  m_scaleY = 0.5f;

		void Render();
		void Update(Inputs* inputs);
		void Animate(std::string animKey);
		
		Sprite(GLuint &id, float x, float y, const char* key[2]);
	   ~Sprite();
       
};




