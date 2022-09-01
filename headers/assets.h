#pragma once

#include <map>
#include "./entities/sprite.h"

namespace Assets {

    namespace Images {
            const char* menu[2] = { "menu", "assets/images/menu.png"};
            const char* swanky_velvet[2] = { "swanky_velvet", "assets/images/swanky_velvet.png" };
    }
}

// class Assets
// {
//     public:

//         static Assets& get(){
//             static Assets self;
//             return self;
//         } 

//         Assets(Assets const&) = delete;

//         void operator= (Assets const&) = delete;

//         Sprite* getSprite(std::string name)
//         {
//             return m_mapAsset[name];
//         }

//         void loadAsset(Window* &window, int _x, int _y, int _width, int _height, const char* filepath)
//         {
//             auto load = [&](std::string name, const char* filepath/* std::wstring filename */)
//             {
//                 //Sprite* sprite = new Sprite(window, _x, _y, _width, _height, filepath );
//                 //m_mapAsset[filepath] = sprite;
//             };
//         }

//     private: 
//         Assets();
//         ~Assets();

//         std::map<std::string, Sprite*> m_mapAsset;
// };