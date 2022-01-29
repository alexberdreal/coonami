#include <coonami/server/gamer_server.h>

using namespace coonami::server;

int main() {
    GamerServer server(4445);
    server.Run();
    return 0;
}