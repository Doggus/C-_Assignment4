//
// Created by tldlir001 on 2018/04/17.
//

#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
#include <string>

#ifndef IMAGEOPS_IMAGE_H
#define IMAGEOPS_IMAGE_H

namespace tldlir001
{
    class Image
    {
        public:
            int width;
            int height;
            std::vector<unsigned char*> slices;

            void load(std::string name); //read
            void save(std::string name); //write

            Image operator+(const Image &);
            Image operator-(const Image &);
            Image operator!(void);
            Image operator/(const Image &);
            Image operator*(const int &);
            Image operator<<(const Image &);
            Image operator>>(const Image &);

            Image();
            ~Image();

    };
}


#endif //IMAGEOPS_IMAGE_H
