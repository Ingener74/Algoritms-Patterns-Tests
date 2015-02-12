
%module imagegen

%{
    #include <ImageGenerator.h>
%}

class Image
{
public:
    Image(int width = 0, int height = 0);
    virtual ~Image();

    const uint8_t* getData() const;
    int getWidth() const;
    int getHeight() const;
};

class ImageGenerator
{
public:
    ImageGenerator();
    virtual ~ImageGenerator();

    Image create();
};
