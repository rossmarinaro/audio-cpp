#pragma once

#include <string>
#include <vector>

using string = std::string;

namespace Assets {

    namespace Spritesheets {



        enum Options {
            menu,
            swanky_velvet
        };

        Options resolveString(string const &input)
        {
            if (input == "swanky_velvet") 
                return swanky_velvet;
			if (input == "menu") 
                return menu;
        };

        const char* GetResource(string key)
        {
            switch (resolveString(key))
            {
                case swanky_velvet:
                    return "assets/json/swanky_velvet.json";

            }
        }

        
    }
}

