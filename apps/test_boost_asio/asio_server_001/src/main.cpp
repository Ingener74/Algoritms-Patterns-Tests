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

using namespace boost::asio;
using namespace boost::local_function;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

void client_session(socket_ptr);

int main(int argc, char **argv) {
    std::cout << "test asio server" << std::endl;

    io_service service;
    ip::tcp::endpoint endp(ip::tcp::v4(), 2001);
    ip::tcp::acceptor acc(service, endp);
    while(1){
        socket_ptr sock(new ip::tcp::socket(service));
        acc.accept(*sock);

//        int BOOST_LOCAL_FUNCTION(void) {
//            return 0;
//        } BOOST_LOCAL_FUNCTION(test_thread)

        boost::thread(boost::bind(client_session, sock));
    }

    return 0;
}

void client_session(socket_ptr sock){
    while(true){
        char data[512];
        size_t len = sock->read_some(buffer(data));
        if(len > 0){
            write(*sock, buffer("ok", 2));
        }
    }
}
