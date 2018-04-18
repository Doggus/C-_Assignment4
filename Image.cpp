//
// Created by tldlir001 on 2018/04/17.
//

#include "Image.h"

using namespace std;


//default
tldlir001::Image::Image()
{
    width = 0;
    height = 0;
    data;
}

//normal
tldlir001::Image::Image(string name)
{
    load(name);
}

tldlir001::Image::Image(const tldlir001::Image &img)
{

    cout << "1" << endl;
    width = img.width;
    cout << "2" << endl;
   // height = img.height; //this line causes segmentation fault WHY!!!!!!!!!!!!!!!!!!!!!
    //slices = img.slices;


    /*
    for (int i = 0; i< img.height; i++)
    {
        for (int j = 0; j < img.width; ++j)
        {
            slices[i][j] = img.slices[i][j];
        }

    }
    */

}

tldlir001::Image::Image(const tldlir001::Image &&img)
{
}

/*

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

        slices.reserve(height);
        //make necessary space for vector
        for (int i = 0; i < height; i++)
        {
            slices[i] = new unsigned char[width];
        }


        //skip one more line
        getline(in,line);

        //storing byte data in vector
        for (int k = 0; k < height; k++)
        {
            in.read((char*)slices[k],width);
        }


        in.close();

    }

}

void tldlir001::Image::save(std::string name)
{
    ofstream out;

    out.open(name);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            out << slices[i][j];
        }
    }

    out.close();

}


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


tldlir001::Image::~Image()
{
    for (int i = 0; i < height; i++)
    {
        delete[] slices[i];
    }
}
*/

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
        getline(in, line);
        getline(in, line);

        getline(in, line); //height and width always on third line (height width)

        istringstream buf(line);
        istream_iterator<string> beg(buf), end;

        vector<string> tokens(beg, end);

        height = stoi(tokens[0]);
        width = stoi(tokens[1]);

        data = unique_ptr<unsigned char[]>(new unsigned char[width*height]);


        for (int i = 0; i < width*height; ++i)
        {
            data[i] = in.get();
        }
    }

}

void tldlir001::Image::save(std::string name)
{
    ofstream out(name, ios::binary);

    for (int i = 0; i < width*height; i++)
    {
        out.put(data[i]);
    }

    out.close();

}

tldlir001::Image::iterator tldlir001::Image::Begin(void)
{
    return iterator(&data.get()[0]);
}

tldlir001::Image::iterator tldlir001::Image::End(void)
{
    return iterator(&data.get()[width*height]);
}

unsigned char tldlir001::Image::iterator::operator*(void)
{
    return *ptr;
}

tldlir001::Image::iterator tldlir001::Image::iterator::operator++(void)
{
    ptr += sizeof(unsigned char);
    return *this;
}

tldlir001::Image::iterator tldlir001::Image::iterator::operator--(void)
{
    ptr -= sizeof(unsigned char);
    return *this;
}

tldlir001::Image::iterator tldlir001::Image::iterator::operator=(const iterator & rhs)
{
    this->ptr = rhs.ptr;
}





