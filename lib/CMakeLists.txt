add_library(coonami INTERFACE)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(utils)
target_link_libraries(
        coonami INTERFACE
        ${BOOST_LIBRARIES}
        client
        server
        utils
)

