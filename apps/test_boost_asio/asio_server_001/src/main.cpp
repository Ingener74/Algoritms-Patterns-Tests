/*
 * main.cpp
 *
 *  Created on: 02 марта 2014 г.
 *      Author: ingener
 */

#include <iostream>

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/thread.hpp>

using namespace std;
using namespace boost;
using namespace boost::asio;

int main(int argc, char **argv)
{
    try
    {
        cout << "test asio server" << endl;

        io_service service;

        ip::tcp::endpoint endp(ip::tcp::v4(), 2001);

        ip::tcp::acceptor acc(service, endp);

        while (true)
        {
            auto sock = make_shared<ip::tcp::socket>(service);
            acc.accept(*sock);

            auto th = thread([](boost::shared_ptr<ip::tcp::socket> sock)
            {
                try
                {
                    while (true)
                    {
                        char data[512];
                        size_t len = sock->read_some(buffer(data));
                        if (len > 0)
                        {
                            write(*sock, buffer("ok", 2));
                        }
                    }
                }
                catch (const std::exception& e)
                {
                    cout << "client thread error: " << e.what() << endl;
                }
            }, sock);
        }
    } catch (const std::exception& e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}
