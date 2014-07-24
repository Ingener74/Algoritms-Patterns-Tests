/*
 * main.cpp
 *
 *  Created on: Jul 18, 2014
 *      Author: pavel
 */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <initializer_list>

using namespace std;

void foo1( initializer_list<int> args )
{
	for ( auto i : args )
	{
		cout << i << " ";
	}
	cout << endl;
}

int main( int argc, char **argv )
{
	try
	{
		cout << "initializer list" << endl;

		foo1( { 1, 10, 100, 1000 } );
	}
	catch ( exception const & e )
	{
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}

