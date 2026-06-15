cmake_minimum_required(VERSION 3.20)

project(
    Aonyx
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost CONFIG REQUIRED COMPONENTS system)

add_library(aonyx
    src/dom/html_node/html_node.cpp
    src/dom/html_tag/html_tag.cpp

    src/http/helper/convert.cpp

    src/http/router/router.cpp

    src/http/server/server.cpp
    src/http/server/server_impl.cpp

    src/http/session/session.cpp
)

target_include_directories(aonyx
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(aonyx
    PRIVATE
        Boost::system
)

target_compile_features(aonyx
    PUBLIC
        cxx_std_23
)

add_executable(example
    examples/main.cpp
)

target_link_libraries(example
    PRIVATE
        aonyx
)
