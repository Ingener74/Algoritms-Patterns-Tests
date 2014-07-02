/*
 * main.cpp
 *
 *  Created on: Jul 2, 2014
 *      Author: pavel
 */

#include <iostream>
#include <stdexcept>
#include <cmath>

#include <boost/lexical_cast.hpp>

using namespace std;

double operator "" _rad(long double degrees)
{
	return degrees * 3.1415926 / 180.0;
}

double operator "" _deg(long double radians)
{
	return radians * 180.0 / 3.1415926;
}

int operator "" _int(const char* str, size_t size)
{
	return boost::lexical_cast<int>(str);
}

int main( int argc, char **argv )
{
	try
	{
		cout << 180.0 << " degrees in radians " << 180.0_rad << endl;

		cout << 3.1415926 << " radians in degrees " << 3.1415_deg << endl;

		int testToInt = "123"_int;
		cout << "test toInt " << testToInt << endl;

		int testToInt2 = "ThisStringIsNotNumber"_int;
		cout << "test toInt2 " << testToInt2 << endl;
	}
	catch ( exception const & e )
	{
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}

