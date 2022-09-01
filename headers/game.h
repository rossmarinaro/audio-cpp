#pragma once

#include "./window.h"

//tmp
	// int m_frame = 1;
	// int mAnimFrame = 0; 
	// const int m_WALKING_ANIMATION_FRAMES = 4;  
	// SDL_Rect mSpriteClips[m_WALKING_ANIMATION_FRAMES];  


class Game {
    
public: 

    static Sprite* background;
    static Sprite* sprite;
    static SDL_Rect* currentClip;
    static Inputs* inputs;

    static void Update(Inputs* inputs);

    Game(Inputs* inputs, GLuint TextureID[]);
   ~Game();

};
