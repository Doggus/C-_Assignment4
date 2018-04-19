#include <iostream>
#include "Driver.h"
#include "Image.h"

using namespace std;

int main()
{

    tldlir001::Image img("shrek_rectangular.pgm");
    tldlir001::Image img2("shrek_rectangular.pgm");

    tldlir001::Image img3 = img + img2;

    img3.save("output.pgm");
    //img.save("output.pgm");

    return 0;


}