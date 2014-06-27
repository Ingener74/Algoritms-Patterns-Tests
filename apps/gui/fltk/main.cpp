/*
 * main.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: pavel
 */

#include <iostream>
#include <stdexcept>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

using namespace std;

void buttonCallback( Fl_Widget* winget, void* userdata )
{
//    throw runtime_error("button callback");
    cout << "button callback" << endl;
}

int main( int argc, char **argv )
{
    try
    {
        cout << "FLTK test" << endl;

        Fl_Window window(640, 480, "FLTK Test");

        window.begin();
        Fl_Button button(10, 10, 200, 24, "Test");
        window.end();

        button.callback(buttonCallback);

        window.show();

        return Fl::run();
    }
    catch ( exception const & e )
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

