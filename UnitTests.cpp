

#include "Image.h"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("Default Image Constructor","Tests functionality of default Constructor")
{
	tldlir001::Image img;
	REQUIRE(img.getHeight() == 0);
	REQUIRE(img.getWidth() == 0);
	REQUIRE(img.getData() == nullptr);
}

TEST_CASE("Normal Image Constructor","Tests functionality of Normal Constructor and by proxy the Load and getter functions as well")
{
	tldlir001::Image img("shrek_rectangular.pgm");
	REQUIRE(img.getHeight() == 1280);
	REQUIRE(img.getWidth() == 1207);

	ifstream in("shrek_rectangular.pgm");
	//skip 4 Lines
	string line = "";
    getline(in, line);
    getline(in, line);
	getline(in, line);
	getline(in, line); 
	
	for (auto i = img.begin(); i != img.End(); ++i)
    {
        REQUIRE(*i == in.get());
    }
    
}

TEST_CASE("Copy Image Constructor","Tests functionality of Copy Constructor")
{
	tldlir001::Image img("shrek_rectangular.pgm");
	tldlir001::Image imgCopy(img);
	REQUIRE(imgCopy.getHeight() == img.getHeight());
	REQUIRE(imgCopy.getWidth() == img.getWidth());

	auto j = img.begin();
	for (auto i = imgCopy.begin(); i != imgCopy.End(); ++i)
    {
        REQUIRE(*i == *j);
        ++j;
    }
}

TEST_CASE("Move Image Constructor","Tests functionality of Move Constructor")
{
	tldlir001::Image img("shrek_rectangular.pgm");
	tldlir001::Image imgCopy(img); //copy of img before move
	tldlir001::Image imgMove = std::move(img); // move img into imgMove (my constructor is invoked like this)

	//Tests that img has been moved into imgMove
	REQUIRE(imgMove.getHeight() == imgCopy.getHeight());
	REQUIRE(imgMove.getWidth() == imgCopy.getWidth());

	auto j = imgCopy.begin();
	for (auto i = imgMove.begin(); i != imgMove.End(); ++i)
    {
        REQUIRE(*i == *j);
        ++j;
    }

    //Tests that img in now empty
	REQUIRE(img.getHeight() == 0);
	REQUIRE(img.getWidth() == 0);
	REQUIRE(img.getData() == nullptr);

}

TEST_CASE("Clamp Method", "Tests functionality of Clamp Method")
{
	tldlir001::Image img;

	REQUIRE(img.clamp(300) == 255);
	REQUIRE(img.clamp(-50) == 0);
}


TEST_CASE("Addition Operator","Tests functionality of Addition Operator")
{
	tldlir001::Image img("shrek_rectangular.pgm");
	tldlir001::Image imgA = img + img; 

	auto j = imgA.begin();
    for (auto i = img.begin(); i != img.End(); ++i)
    {
        int c = (int)(*i) + (int)(*i);
        REQUIRE(*j == img.clamp(c));
        ++j;
    }

}

TEST_CASE("Subtraction Operator","Tests functionality of Subtraction Operator")
{
	tldlir001::Image img("shrek_rectangular.pgm");
	tldlir001::Image imgS = img - img; 

	auto j = imgS.begin();
    for (auto i = img.begin(); i != img.End(); ++i)
    {
        int c = (int)(*i) - (int)(*i);
        REQUIRE(*j == img.clamp(c));
        ++j;
    }

}

TEST_CASE("Invert Operator","Tests functionality of Invert Operator")
{
	tldlir001::Image img("shrek_rectangular.pgm");
	tldlir001::Image imgI = !img; 

	auto j = imgI.begin();
    for (auto i = img.begin(); i != img.End(); ++i)
    {
        int c = 255 - (int)*i;
        REQUIRE(*j == img.clamp(c));

        ++j;
    }

}

TEST_CASE("Mask Operator","Tests functionality of Mask Operator")
{
	tldlir001::Image img("shrek_rectangular.pgm");
	tldlir001::Image Mask("donkey_mask.pgm");
	tldlir001::Image imgM = img/Mask; 

	auto j = imgM.begin();
	auto m = Mask.begin();
    for (auto i = img.begin(); i != img.End(); ++i)
    {
        if (*m == 255)
        {
            REQUIRE(*j == img.clamp(*i));
        }
        else 
        {   
            REQUIRE(*j == 0);
        }

        ++m;
        ++j;


    }

}

TEST_CASE("Threshold Operator","Tests functionality of Threshold Operator")
{
	tldlir001::Image img("shrek_rectangular.pgm");
	tldlir001::Image imgT = img * 50; 

	auto j = imgT.begin();
	for (auto i = img.begin(); i != img.End(); ++i)
    {
        if((int)*i > 50)
        {
            REQUIRE(*j == 255);
        }
        else
        {
            REQUIRE(*j == 0);
        }

        ++j;
    }

}

TEST_CASE("Save And Load (i/o) Operators","Tests functionality of Save and load Operators and by proxy the save and load methods")
{
    tldlir001::Image img;
    img << "shrek_rectangular.pgm";
    img << "Test_Output.pgm";
    tldlir001::Image img2("Test_Output.pgm");


    auto i2 = img2.begin();
    for (auto i = img.begin(); i != img.End(); ++i)
    {
        REQUIRE(*i == *i2);
        ++i2;
    }

}




