#include <iostream>
#include "Driver.h"
#include "Image.h"

using namespace std;

int main()
{
    std::cout << "Hello, World!" << std::endl;

    tldlir001::Image img("shrek_rectangular.pgm");

    //cout << "height: " << img.height << endl;
    //cout << "width: " << img.width << endl;

    tldlir001::Image Cimg(img);
    //Cimg.save("CopyOutput.txt");
    //cout <<"done"<<endl;

    //img.save("output.pgm");

    return 0;



}