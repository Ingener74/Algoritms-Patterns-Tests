/*
 * ImageGenerator.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: pavel
 */

#include <iostream>

#include "ImageGenerator.h"

using namespace std;

Image::Image(int type, int width, int height) :
        type(type), width(width), height(height), buffer(type * width * height)
{
    std::cout << __PRETTY_FUNCTION__ << " " << type << " " << width << " " << height << " " << buffer.size() << std::endl;

    auto ptr = buffer.data();
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j, ptr += type)
        {
            ptr[0] = 1;
            ptr[1] = 255;
            ptr[2] = 1;
        }
    }
}

Image::~Image()
{
    std::cout << __PRETTY_FUNCTION__ << " " << width << " " << height << " " << buffer.size() << std::endl;
}

const char* Image::getData() const
{
    std::cout << __PRETTY_FUNCTION__ << " " << reinterpret_cast<long>(buffer.data()) <<  std::endl;
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

int Image::getType() const
{
    return type;
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
    return {Image::RGB, 640, 480};
}
