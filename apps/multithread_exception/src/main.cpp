/*
 * main.cpp
 *
 *  Created on: May 21, 2014
 *      Author: pavel
 */

#include <boost/thread.hpp>
#include <boost/exception_ptr.hpp>

#include <stdexcept>
#include <iostream>

using namespace std;
using namespace boost;

class Second
{
public:
    Second()
    {
    }
    virtual ~Second()
    {
    }

    void operator()(boost::exception_ptr &error)
    {
        try
        {
            throw enable_current_exception(std::runtime_error("test exception"));
        }
        catch (std::exception const & e)
        {
            std::cout << "second thread error: " << e.what() << std::endl;
            error = boost::current_exception();
        }
    }

private:
};

int main(int argc, char **argv)
{
    try
    {
        boost::exception_ptr error;
        Second sec;
        thread t = thread(sec, boost::ref(error));
        t.join();

        if (error) rethrow_exception(error);
    }
    catch (std::exception const & e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    return 0;
}

