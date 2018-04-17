//
// Created by tldlir001 on 2018/04/17.
//

#include <vector>

#ifndef IMAGEOPS_IMAGE_H
#define IMAGEOPS_IMAGE_H

namespace tldlir001
{
    class Image
    {
        public:
            int width;
            int height;
            std::vector<unsigned char**> slices;

            void load(std::string name); //read
            void save(std::string name); //write

            Image operator+(const Image &);
            Image operator-(const Image &);
            Image operator!(const Image &);
            Image operator/(const Image &);
            Image operator*(const Image &);

            Image();
            ~Image();

    };
}


#endif //IMAGEOPS_IMAGE_H
