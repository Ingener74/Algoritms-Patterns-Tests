/*
 * main.cpp
 *
 *  Created on: 02 марта 2014 г.
 *      Author: ingener
 */

#include <iostream>

#include <boost/bind.hpp>
#include <boost/local_function.hpp>
#include <boost/asio.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/thread.hpp>

using namespace boost;
using namespace std;

int main(int argc, char **argv)
{
    try
    {
        std::cout << "test asio server" << std::endl;

        asio::io_service service;

        asio::ip::tcp::endpoint endp(asio::ip::tcp::v4(), 2001);

        asio::ip::tcp::acceptor acc(service, endp);

        while (true)
        {
            auto sock = make_shared<asio::ip::tcp::socket>(service);
            acc.accept(*sock);

            auto th = thread([sock](boost::shared_ptr<asio::ip::tcp::socket> sock)
            {
                try
                {
                    while (true)
                    {
                        char data[512];
                        size_t len = sock->read_some(asio::buffer(data));
                        if (len > 0)
                        {
                            write(*sock, asio::buffer("ok", 2));
                        }
                    }
                }
                catch (const std::exception& e)
                {
                    cout << "client thread error: " << e.what() << endl;
                }
            }, sock);
        }
    }
    catch (const std::exception& e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}
