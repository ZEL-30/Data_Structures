cmake_minimum_required(VERSION 3.0)

project(Data_Structures)

include_directories(include)

add_compile_options(-Wall -O2)

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