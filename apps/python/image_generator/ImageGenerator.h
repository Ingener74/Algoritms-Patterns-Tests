/*
 * ImageGenerator.h
 *
 *  Created on: Feb 12, 2015
 *      Author: pavel
 */

#ifndef IMAGEGENERATOR_H_
#define IMAGEGENERATOR_H_

#include <vector>

/*
 * Image
 */
class Image
{
public:
    static const int RGB  = 3;
    static const int RGBA = 4;
    static const int M    = 1;

    Image(int type = RGB, int width = 0, int height = 0);
    virtual ~Image();

    const char* getData() const;
    int getWidth() const;
    int getHeight() const;
    int getType() const;

private:
    int type, width, height;
    std::vector<char> buffer;
};

class ImageGenerator
{
public:
    ImageGenerator();
    virtual ~ImageGenerator();

    Image create();
};

#endif /* IMAGEGENERATOR_H_ */
