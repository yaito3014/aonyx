cmake_minimum_required(VERSION 3.20)

project(
    Aonyx
    VERSION 0.1.0
    LANGUAGES CXX
)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost CONFIG REQUIRED COMPONENTS
    system
    url
)
find_package(OpenSSL REQUIRED)

add_library(aonyx
    src/dom/html_node/html_node.cpp
    src/dom/html_tag/html_tag.cpp

    src/http/server/helper/convert.cpp

    src/http/server/router/router.cpp

    src/http/client/client/client.cpp

    src/http/server/server/server.cpp
    src/http/server/server/server_impl.cpp

    src/http/server/session/session.cpp
)

target_include_directories(aonyx
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/thirdparty

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(aonyx
    PRIVATE
        Boost::system
        Boost::url
        OpenSSL::SSL
        OpenSSL::Crypto
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


install(
    TARGETS aonyx
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
