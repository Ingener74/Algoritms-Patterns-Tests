/*
 * main.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: pavel
 */

#include <iostream>
#include <stdexcept>
#include <thread>
#include <future>
#include <iomanip>

using namespace std;

int main( int argc, char **argv )
{
	try
	{
		cout << "test promise<exception_ptr>" << endl;

		auto thread_func = [](promise<exception_ptr>& start)
		{
			try
			{
				throw runtime_error("test exception"); // to test normal comment this line

				start.set_value(exception_ptr());
			}
			catch (exception const & e)
			{
				start.set_exception(current_exception());
			}
		};

		promise<exception_ptr> start;

		auto fs = start.get_future();

		thread th( thread_func, ref( start ) );
		th.detach();

		fs.wait();
		if ( fs.get() ) rethrow_exception( fs.get() );

		cout << "normal exit" << endl;
	}
	catch ( exception const & e )
	{
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}
