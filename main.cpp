#include <iostream>
#include <cstring>
#include "Image.h"

//Images taken in as parametres will be the ones on the right of the operator (+,-,*,etc);

using namespace std;

int main(int argc, char* argv[])
{

    //tldlir001::Image img("shrek_rectangular.pgm");
    //tldlir001::Image img2("shrek_rectangular.pgm");
    //tldlir001::Image Mask("donkey_mask.pgm");

    //tldlir001::Image imgP = img + img2;
    //tldlir001::Image imgM = img - img2;
    //tldlir001::Image imgI = !img;
    //tldlir001::Image imgMsk = img/Mask;
    //tldlir001::Image imgT = img*150;
    //tldlir001::Image imgIP = !imgP;

    //imgP.save("output.pgm");
    //img.save("output.pgm");
    //imgMsk.save("outputMask.pgm");

    //ofstream out("output.pgm", ios::binary);
    //out << imgP;

    //ifstream in("shrek_rectangular.pgm");
    //tldlir001::Image im;
    //in >> im; // doesn't work
    //out << im;


    tldlir001::Image image("shrek_rectangular.pgm");
    tldlir001::Image Mask("donkey_mask.pgm");

    if(strcmp(argv[1], "-a")==0) //is true
    {
    	tldlir001::Image imgAdd = image + image;
    	string name = argv[2];
    	imgAdd.save(name);
    }
    else if(strcmp(argv[1], "-s")==0)
    {
    	tldlir001::Image imgSub = image - image;
    	string name = argv[2];
    	imgSub.save(name);
    }
    else if(strcmp(argv[1], "-i")==0)
    {
    	tldlir001::Image imgInv = !image;
    	string name = argv[2];
    	imgInv.save(name);
    }
    else if(strcmp(argv[1], "-l")==0)
    {
    	tldlir001::Image imgMask = image/Mask;
    	string name = argv[2];
    	imgMask.save(name);
    }
    else if(strcmp(argv[1], "-t")==0)
    {
    	int t;
    	cout << "Enter a threshold value" << endl;
    	cin >> t;
    	tldlir001::Image imgThresh = image * t;
    	string name = argv[2];
    	imgThresh.save(name);
    }
    else
    {
    	cout << "No recognized command given" << endl;
    }


    return 0;


}