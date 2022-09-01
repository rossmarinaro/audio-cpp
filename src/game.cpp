#include "../headers/assets.h"
#include "../headers/game.h"


Sprite* m_background;
Sprite* m_sprite;


Game::Game(Inputs* inputs, GLuint textures[])
{

    //m_background = new Sprite(textures[0], -0.5, -0.5, Assets::Images::menu);
    m_sprite = new Sprite(textures[1], -0.3, -0.3, Assets::Images::swanky_velvet);

}

//-----------------------------------------------------

void Game::Update(Inputs* inputs)
{

    //m_background->Render();//Update(inputs);
    m_sprite->Render();//Update(inputs);

}

Game::~Game()
{

    delete m_sprite;
    //delete m_background;

    Log::write("game closed.");
}




