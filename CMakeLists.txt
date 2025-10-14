cmake_minimum_required(VERSION 3.10)
project(blockchain_ateliers CXX)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenSSL REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SRC_COMMON
    src/MerkleTree.cpp
    src/Block.cpp
    src/Blockchain.cpp
    src/PoS.cpp
)

add_executable(ex1 ${SRC_COMMON} src/main_ex1.cpp)
add_executable(ex2 ${SRC_COMMON} src/main_ex2.cpp)
add_executable(ex3 ${SRC_COMMON} src/main_ex3.cpp)
add_executable(ex4 ${SRC_COMMON} src/main_ex4.cpp)

target_link_libraries(ex1 OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(ex2 OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(ex3 OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(ex4 OpenSSL::SSL OpenSSL::Crypto)
