cmake_minimum_required(VERSION 3.0)

project(Data_Structures)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

add_executable(seqlist1 seqlist1.cpp)

add_executable(seqlist2 seqlist2.cpp)

add_executable(seqlist3 seqlist3.cpp)

add_executable(linklist1 linklist1.cpp)

add_executable(linklist2 linklist2.cpp)

add_executable(sizeof sizeof.cpp)

add_executable(memcpy memcpy.cpp)

add_executable(mystring mystring.cpp src/MyString.cpp)

add_executable(seqstack1 seqstack1.cpp)

add_executable(seqstack2 seqstack2.cpp)

add_executable(seqstack3 seqstack3.cpp)

add_executable(seqstack4 seqstack4.cpp)

add_executable(linkstack1 linkstack1.cpp)

add_executable(seqqueue1 seqqueue1.cpp)

add_executable(linkqueue1 linkqueue1.cpp)
