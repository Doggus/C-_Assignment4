#include <iostream>
#include "Image.h"

//Images taken in as parametres will be the ones on the right of the operator (+,-,*,etc);

using namespace std;

int main()
{

    tldlir001::Image img("shrek_rectangular.pgm");
    tldlir001::Image img2("shrek_rectangular.pgm");
    tldlir001::Image Mask("donkey_mask.pgm");

    tldlir001::Image imgP = img + img2;
    //tldlir001::Image imgM = img - img2;
    //tldlir001::Image imgI = !img;
    //tldlir001::Image imgMsk = img/Mask;
    //tldlir001::Image imgT = img*150;
    //tldlir001::Image imgIP = !imgP;

    //imgP.save("output.pgm");
    //img.save("output.pgm");

    //ofstream out("output.pgm", ios::binary);
    //out << imgP;

    //ifstream in("shrek_rectangular.pgm");
    //tldlir001::Image im;
    //in >> im; // doesn't work
    //out << im;



    return 0;


}