find_package(
        Boost 1.71.0 COMPONENTS
        filesystem
        system
        container
        context
        chrono
        thread
        coroutine
        regex
)

set(BOOST_INCLUDE_DIR ${Boost_INCLUDE_DIRS})
set(BOOST_LIBRARIES
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_CONTAINER_LIBRARY}
        ${Boost_CONTEXT_LIBRARY}
        ${Boost_CHRONO_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_COROUTINE_LIBRARY}
        ${Boost_REGEX_LIBRARY}
        )