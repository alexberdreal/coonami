#include <coonami/server/gamer_server.h>

namespace coonami::server {

GamerServer::GamerServer(uint16_t port) : _port(port) {}

void GamerServer::Run() {
    // Create current gamer endpoint
    tcp::endpoint ep(tcp::v4(), _port);
    // Create acceptor
    auto acceptor = std::make_shared<tcp::acceptor>(io_service, ep);
    // The socket, that will be used when we receive the next message via tcp
    auto new_sock = std::make_shared<tcp::socket>(io_service);

    // Async operation which purpose is to execute the callback (2 argument) when socket is not empty
    acceptor->async_accept(*new_sock, [=](const auto& ec) {
        ProcessMessage(acceptor, new_sock, ec);
    });

    // While the acceptor receives messages with async_accept, this call blocks the thread
    io_service.run();
}

void GamerServer::ProcessMessage(std::shared_ptr<tcp::acceptor> acc, std::shared_ptr<tcp::socket> sock,
                                 const boost::system::error_code &ec)
{
    char buffer[256];
    if (!ec) {
        // Read the message to _buffer in case if there is no error code
        sock->async_read_some(boost::asio::buffer(buffer), [this, &buffer](const auto& ec, auto size) {
            for (size_t i = 0; i < size; ++i) {
                std::cout << buffer[i];
            } // TODO: process message later (add event parser -> parse an event -> world engine will handle it)
        });
    }
    else
        throw(std::runtime_error("ProcessMessage error: " + ec.message()));

    // Recursively repeat the previous actions

    auto new_sock = std::make_shared<tcp::socket>(io_service);

    acc->async_accept(*new_sock, [=](const auto& ec) {
        ProcessMessage(acc, new_sock, ec);
    });
}

}