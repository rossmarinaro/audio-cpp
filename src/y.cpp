
#include <iostream>

#include "../headers/logs.h"
int main()
{
    for (int i = 0; i < 1000000; i++)
    {
        std::cout << i << std::endl;
    }
Log::write("yooo");
    return 0;
}