//
// Created by tldlir001 on 2018/04/17.
//

#include "Image.h"

using namespace std;

tldlir001::Image::Image()
{

}

void tldlir001::Image::load(std::string name)
{
    ifstream in(name);

    if(!in)
    {
        cout << "Couldn't open file" << endl;
    }
    else
    {
        //skip two lines
        string line = "";
        getline(in,line);
        getline(in,line);

        getline(in,line); //height and width always on third line (height width)

        istringstream buf(line);
        istream_iterator<string> beg(buf), end;

        vector<string> tokens(beg,end);

        height = stoi(tokens[0]);
        width = stoi(tokens[1]);

        //make necessary space for vector
        for (int i = 0; i < height; i++)
        {
            slices[i] = new unsigned char [height];
            for (int j = 0; j < width ; j++)
            {
                slices[j] = new unsigned char[width];
            }
        }

        //skip one more line
        getline(in,line);

        //storing byte data in vector
        for (int k = 0; k < height; k++)
        {
            for (int l = 0; l < width; l++)
            {

                
                in.read((char*)slices[k],width);
            }
        }



    }

}

void tldlir001::Image::save(std::string)
{

}

/*
Image tldlir001::Image::operator+(const Image &)
{

}

Image tldlir001::Image::operator-(const Image &)
{

}

Image tldlir001::Image::operator!(void)
{

}

Image tldlir001::Image::operator/(const Image &)
{

}

Image tldlir001::Image::operator*(const int &)
{

}
*/

tldlir001::Image::~Image()
{

}
