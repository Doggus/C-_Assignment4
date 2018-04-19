//
// Created by tldlir001 on 2018/04/17.
//

#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <memory>
//#include <iterator>

#ifndef IMAGEOPS_IMAGE_H
#define IMAGEOPS_IMAGE_H

namespace tldlir001
{
    class Image
    {
        private:
            int width;
            int height;
            std::unique_ptr<unsigned char[]> data;

        public:
            void load(std::string name); //read
            void save(std::string name); //write

            Image operator+(const Image &);
            Image operator-(const Image &);
            Image operator!(void);
            Image operator/(const Image &);
            Image operator*(const int &);
            Image operator<<(const Image &);
            Image operator>>(const Image &);

            Image(std::string name); //normal
            Image(); //default
            Image(const tldlir001::Image &img); //copy
            Image(tldlir001::Image &&img); //move

            ~Image(); //destructor

            unsigned char clamp(int c);

        class iterator
        {

            private:
                unsigned char *ptr;
                iterator(u_char *p) : ptr(p){}; //constructor (defined in header)
                friend class Image;

            public:
                //iterator(const tldlir001::iterator &i); //copy
                //iterator(const tldlir001::iterator &&i); //move
                //~iterator(); //destructor

            u_char &operator*(void);
            tldlir001::Image::iterator operator++(void);
            tldlir001::Image::iterator operator--(void);
            tldlir001::Image::iterator &operator=(const iterator & rhs);
            bool operator!=(const iterator & rhs);

        };

        iterator begin(void);
        iterator End(void);

    };


}


#endif //IMAGEOPS_IMAGE_H
