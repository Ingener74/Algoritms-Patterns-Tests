/*
 * main.cpp
 *
 *  Created on: 02 марта 2014 г.
 *      Author: ingener
 */

#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost;
using namespace boost::asio;

int main(int argc, char **argv)
{
    cout << "test asio client" << endl;

    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
    ip::tcp::socket sock(service);
    sock.async_connect(ep, [](const system::error_code& ec)
    {
        cout << "connnection success" << endl;
    });
    service.run();

    return 0;
}
