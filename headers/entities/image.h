#pragma once
#include <iostream>
#include <vector>
#include <fstream>

#include "../window.h"
#include "../inputs.h"

#include "../../vendors/nlohmann/json.hpp"
#include "../../headers/entities/sprite.h"


class Image {

    public:       

		int m_renderMode;

		float m_posX, 	
              m_posY,
			  m_srcWidth = 1.0, 
			  m_srcHeight = 1.0;

		double m_degrees = 0; 
		const char* m_filepath; 
		SDL_Surface* m_texture;

		void _init(GLuint &id, float x, float y)
		{
			SDL_Surface* image = IMG_Load(m_filepath);

			if (image == NULL) 
				Log::error(SDL_GetError()); 

			else 
			{ 

			//render image as opengl texture
			
				glBindTexture(GL_TEXTURE_2D, id);
				
				m_renderMode = GL_RGB;
				
				if (image->format->BytesPerPixel == 4) 
				{ 
					m_renderMode = GL_RGBA; 
					Log::write("rgba enabled"); 
				}

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			//Get image dimensions and render

				m_posX = x;
				m_posY = y;
				m_texture = image;
			}
		}

		~Image()
		{
			SDL_FreeSurface(m_texture);
		}

	private:

		GLuint m_inst;

		void _setColor(Uint8 red, Uint8 green, Uint8 blue);
		void _setBlendMode( SDL_BlendMode blending );
		void _setAlpha(Uint8 alpha);
	
};



