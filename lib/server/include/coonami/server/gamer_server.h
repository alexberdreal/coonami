#pragma once
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <coonami/utils/utils.h>
#include <iostream>

namespace coonami::server {

class GamerServer {
using tcp = boost::asio::ip::tcp;
public:
    GamerServer(uint16_t port);
    void Run();

private:
    void ProcessMessage(std::shared_ptr<tcp::acceptor> acc, std::shared_ptr<tcp::socket> sock, const boost::system::error_code& ec);
    char _buffer[256];
    uint16_t _port;
    boost::asio::io_service io_service;
};

}