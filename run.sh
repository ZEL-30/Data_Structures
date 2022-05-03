#!/bin/zsh
#ZEL
#运行C++程序

cd build
cmake ..

echo "--------------------------编译程序----------------------------"
make $1 | grep "Built" && messages=Built || messages=
if [ $messages==Built ];then
    clear
    echo "--------------------------执行程序----------------------------"
    ./$1
    echo "--------------------------程序退出----------------------------"
fi

