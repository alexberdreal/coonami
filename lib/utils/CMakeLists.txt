file(GLOB_RECURSE UTILS_SOURCES src/*.cpp)
add_library(utils STATIC ${UTILS_SOURCES})
target_include_directories(utils PUBLIC include boost)
target_link_libraries(utils)