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
    Image(int width = 0, int height = 0);
    virtual ~Image();

    const uint8_t* getData() const;
    int getWidth() const;
    int getHeight() const;
private:
    int width, height;
    std::vector<uint8_t> buffer;
};

class ImageGenerator
{
public:
    ImageGenerator();
    virtual ~ImageGenerator();

    Image create();
};

#endif /* IMAGEGENERATOR_H_ */
