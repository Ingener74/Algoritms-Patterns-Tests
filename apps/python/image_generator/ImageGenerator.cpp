/*
 * ImageGenerator.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: pavel
 */

#include <iostream>

#include "ImageGenerator.h"

using namespace std;

Image::Image(int width, int height) :
        width(width), height(height), buffer(width * height)
{
    std::cout << __PRETTY_FUNCTION__ << " " << width << " " << height << " " << buffer.size() << std::endl;
}

Image::~Image()
{
    std::cout << __PRETTY_FUNCTION__ << " " << width << " " << height << " " << buffer.size() << std::endl;
}

const uint8_t* Image::getData() const
{
    return buffer.data();
}

int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

ImageGenerator::ImageGenerator()
{
    std::cout << __PRETTY_FUNCTION__ << "" << std::endl;
}

ImageGenerator::~ImageGenerator()
{
    std::cout << __PRETTY_FUNCTION__ << "" << std::endl;
}

Image ImageGenerator::create()
{
    return {640, 480};
}
