/*
 * client.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: pavel
 */

#include <iostream>
#include <stdexcept>

#include <boost/asio.hpp>
#include <boost/smart_ptr.hpp>

using namespace std;
using namespace boost;

/*
 * get from http://habrahabr.ru/post/195386/
 */

int main(int argc, char **argv)
{
    try
    {
        cout << "echo sync client" << endl;
    }
    catch (const std::exception& e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

