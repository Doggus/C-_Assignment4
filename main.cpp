#include <iostream>
#include "Driver.h"
#include "Image.h"

using namespace std;

int main()
{

    std::cout << "Hello, World!" << std::endl;

    tldlir001::Image img;
    img.load("shrek_rectangular.pgm");

    for (int i = 0; i < img.height; ++i)
    {
        for (int j = 0; j < img.width; ++j)
        {
            cout << img.slices[i][j] << endl;
        }
    }


    return 0;



}