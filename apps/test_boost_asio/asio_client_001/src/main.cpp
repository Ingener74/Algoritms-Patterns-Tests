/*
 * main.cpp
 *
 *  Created on: 02 марта 2014 г.
 *      Author: ingener
 */

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;
using namespace std;

int main(int argc, char **argv)
{
    std::cout << "test asio client" << std::endl;

    asio::io_service service;
    asio::ip::tcp::endpoint ep(asio::ip::address::from_string("127.0.0.1"),
            2001);
    asio::ip::tcp::socket sock(service);
    sock.async_connect(ep, [](const system::error_code& ec)
    {
        cout << "connnection success" << endl;
    });
    service.run();

    return 0;
}
