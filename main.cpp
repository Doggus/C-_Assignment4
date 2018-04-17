#include <iostream>
#include "Driver.h"
#include "Image.h"

using namespace std;

int main()
{

    std::cout << "Hello, World!" << std::endl;

    tldlir001::Image img;
    img.load("shrek_rectangular.pgm");

    cout << "height: " << img.height << endl;
    cout << "width: " << img.width << endl;
    

    img.save("output.txt");


    return 0;



}