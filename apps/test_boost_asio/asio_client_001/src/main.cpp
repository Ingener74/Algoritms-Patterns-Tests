/*
 * main.cpp
 *
 *  Created on: 02 марта 2014 г.
 *      Author: ingener
 */

#include <iostream>
#include <boost/asio.hpp>

void connect_handler(const boost::system::error_code&);

int main(int argc, char **argv) {
    std::cout << "test asio client" << std::endl;

    using namespace boost::asio;
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
    ip::tcp::socket sock(service);
    sock.async_connect(ep, connect_handler);
    service.run();

    return 0;
}

void connect_handler(const boost::system::error_code& ec){
}
