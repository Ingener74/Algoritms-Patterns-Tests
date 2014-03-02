/*
 * main.cpp
 *
 *  Created on: 02 марта 2014 г.
 *      Author: ingener
 */

#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char **argv) {
    std::cout << "test asio server" << std::endl;

    using namespace boost::asio;
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("128.0.0.1"), 2001);
    ip::tcp::socket sock(service);
    sock.connect(ep);

    return 0;
}



