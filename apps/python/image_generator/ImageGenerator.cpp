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
    auto ptr = buffer.data();
    cout << __PRETTY_FUNCTION__ << type << " " << width << " " << height << " " << buffer.size() << endl;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j, ptr += type)
        {
            ptr[0] = 255;
            ptr[1] = 1;
            ptr[2] = 1;
        }
    }
}

Image::~Image()
{
    cout << __PRETTY_FUNCTION__ << " " << width << " " << height << " " << buffer.size() << endl;
}

const void* Image::getData() const
{
    cout << __PRETTY_FUNCTION__ << " 0x" << hex << reinterpret_cast<long>(buffer.data()) << endl;
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
    cout << __PRETTY_FUNCTION__ << "" << endl;
}

ImageGenerator::~ImageGenerator()
{
    cout << __PRETTY_FUNCTION__ << "" << endl;
}

Image ImageGenerator::create()
{
    return {Image::RGB, 640, 480};
}
