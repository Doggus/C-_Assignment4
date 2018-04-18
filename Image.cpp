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

    width = img.width;
    height = img.height;
    data = unique_ptr<unsigned char[]>(new unsigned char[width*height]); //assign space
    for (int i = 0; i < width*height; ++i)
    {
        data[i] = img.data[i]; //copy
    }

}

tldlir001::Image::Image(tldlir001::Image &&img) //no const because we want to change values
{
    /*
    //Auto
    width = img.width;
    height = img.height;
    //might have to make img.w and img.h =0 and img.data = nullptr if std::move doesn't work
    data = std::move(img.data); //should do what Manual code does
    */

    //Manual:

    //assign new values
    width = img.width;
    height = img.height;
    data = unique_ptr<unsigned char[]>(new unsigned char[width*height]); //assign space
    for (int i = 0; i < width*height; ++i)
    {
        data[i] = img.data[i]; //copy
    }

    //deletes old values
    img.height = 0;
    img.width = 0;
    img.data = nullptr;

    //hence Move
}

tldlir001::Image::~Image()
{
    data = nullptr;
}


tldlir001::Image tldlir001::Image::operator+(const Image &)
{

}


tldlir001::Image tldlir001::Image::operator-(const Image &)
{

}

tldlir001::Image tldlir001::Image::operator!(void)
{

}

tldlir001::Image tldlir001::Image::operator/(const Image &)
{

}

tldlir001::Image tldlir001::Image::operator*(const int &)
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
        getline(in, line);
        getline(in, line);

        getline(in, line); //height and width always on third line (height width)

        istringstream buf(line);
        istream_iterator<string> beg(buf), end;

        vector<string> tokens(beg, end);

        height = stoi(tokens[0]);
        width = stoi(tokens[1]);

        data = unique_ptr<unsigned char[]>(new unsigned char[width*height]);

        //skip one more line
        getline(in,line);

//        for (int i = 0; i < width*height; ++i)
//        {
//            data[i] = in.get();
//        }

        for (auto i = begin(); i != End(); ++i)
        {
            *i = in.get();
        }

    }

}

void tldlir001::Image::save(std::string name)
{
    ofstream out(name, ios::binary);

//    for (int i = 0; i < width*height; i++)
//    {
//        out.put(data[i]);
//    }

     for(auto i = begin(); i != End(); ++i)
     {
         out.put(*i);
     }

    out.close();

}

tldlir001::Image::iterator tldlir001::Image::begin(void)
{
    return iterator(&data.get()[0]);
}

tldlir001::Image::iterator tldlir001::Image::End(void)
{
    return iterator(&data.get()[width*height]);
}

u_char &tldlir001::Image::iterator::operator*(void)
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

tldlir001::Image::iterator &tldlir001::Image::iterator::operator=(const iterator & rhs)
{
    this->ptr = rhs.ptr;
    return *this;
}

bool tldlir001::Image::iterator::operator!=(const iterator & rhs)
{
    return this->ptr != rhs.ptr;
}





