#include <iostream>
#include <cstring>
#include "Image.h"

//Images taken in as parametres will be the ones on the right of the operator (+,-,*,etc);

using namespace std;

int main(int argc, char* argv[])
{

    //tldlir001::Image image("shrek_rectangular.pgm");
    //tldlir001::Image Mask("donkey_mask.pgm");

    if(strcmp(argv[1], "-a")==0) //is true
    {
        string Input1 = argv[2];
        string Input2= argv[3];
        tldlir001::Image image1(Input1);
        tldlir001::Image image2(Input2);
        tldlir001::Image imgAdd = image1 + image2;
    	string name = argv[4];
    	imgAdd.save(name);
    }
    else if(strcmp(argv[1], "-s")==0)
    {
        string Input1 = argv[2];
        string Input2= argv[3];
        tldlir001::Image image1(Input1);
        tldlir001::Image image2(Input2);
        tldlir001::Image imgSub = image1 - image2;
    	string name = argv[4];
    	imgSub.save(name);
    }
    else if(strcmp(argv[1], "-i")==0)
    {
        string Input = argv[2];
        tldlir001::Image image(Input);
        tldlir001::Image imgInv = !image;
    	string name = argv[3];
    	imgInv.save(name);
    }
    else if(strcmp(argv[1], "-l")==0)
    {
        string Input1 = argv[2];
        string Input2 = argv[3];
        tldlir001::Image image(Input1);
        tldlir001::Image mask(Input2);
        tldlir001::Image imgMask = image/mask;
    	string name = argv[4];
    	imgMask.save(name);
    }
    else if(strcmp(argv[1], "-t")==0)
    {
    	int t;
    	cout << "Enter a threshold value" << endl;
    	cin >> t;
        string Input = argv[2];
        tldlir001::Image image(Input);
    	tldlir001::Image imgThresh = image * t;
    	string name = argv[3];
    	imgThresh.save(name);
    }
    else
    {
    	cout << "No recognized command given" << endl;
    }


    return 0;


}