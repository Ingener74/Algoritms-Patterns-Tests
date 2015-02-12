
%module imagegen

%{
    #include <ImageGenerator.h>
%}

class Image
{
public:
    static const int RGB  = 3;
    static const int RGBA = 4;
    static const int G    = 1;

    Image(int type = RGB, int width = 0, int height = 0);
    virtual ~Image();

    const char* getData() const;

    int getWidth() const;
    int getHeight() const;
    int getType() const;
};

class ImageGenerator
{
public:
    ImageGenerator();
    virtual ~ImageGenerator();

    Image create();
};
