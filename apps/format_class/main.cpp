/*
 * main.cpp
 *
 *  Created on: Jul 7, 2014
 *      Author: pavel
 */

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

class frmt
{
public:
	frmt() = default;
	virtual ~frmt() = default;

	template <typename T>
	frmt& operator<<( const T& t )
	{
		_ << t;
		return *this;
	}
	string operator<<( const frmt& s )
	{
		return _.str();
	}

private:
	stringstream _;
};

int main( int argc, char **argv )
{
	try
	{
		string formatClass = frmt() << "Test string " << "String" << ", test integer = " << 120 << ""
				", Pi = " << 3.1415926 << ", e = " << 2.72 << frmt();

		cout << "Test format class = " << formatClass << endl;
	}
	catch ( exception const & e )
	{
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}

