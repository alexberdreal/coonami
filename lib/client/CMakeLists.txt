file(GLOB_RECURSE CLIENT_SOURCES src/*.cpp)
add_library(client STATIC ${CLIENT_SOURCES})
target_include_directories(client PUBLIC include)
