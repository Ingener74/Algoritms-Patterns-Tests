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

class TestClass {
public:
	TestClass() = default;
	virtual ~TestClass() = default;

	friend ostream& operator<<(ostream&, const TestClass&);

private:
	double _testDouble  = 2.72;
	string _testString  = "TestClass";
	int    _testInteger = 123;
};
ostream& operator<<( ostream& out, const TestClass& rho )
{
	out << endl << "TestClass._testDouble =  " << rho._testDouble << "," << endl << "TestClass._testString =  "
			<< rho._testString << "," << endl <<"TestClass._testInteger = " << rho._testInteger;
	return out;
}

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
		TestClass tc;

		string formatClass = frmt() << "Test string " << "String" << ", test integer = " << 120 << ""
				", Pi = " << 3.1415926 << ", e = " << 2.72 << ", test custom class = " << tc << frmt();

		cout << "Test format class = " << formatClass << endl;
	}
	catch ( exception const & e )
	{
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}

