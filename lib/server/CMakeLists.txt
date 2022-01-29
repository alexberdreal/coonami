file(GLOB_RECURSE SERVER_SOURCES src/*.cpp)
add_library(server STATIC ${SERVER_SOURCES})
target_include_directories(server PUBLIC include)
target_link_libraries(server)