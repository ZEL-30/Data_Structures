#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define INITSIZE 10
#define EXTSIZE 5


class MyString{

    friend ostream& operator<<(ostream &cout,MyString &string);

public:
    MyString();

    MyString(const char str[]);               //有参构造

    MyString(const MyString &str);            //拷贝构造

    MyString& assign(const char s);

    MyString& assign(const MyString &str);

    MyString& assign(const char str[]);

    MyString& operator=(const char s);

    MyString& operator=(const char str[]);

    MyString& operator=(const MyString &str);

    int size();

    ~MyString();

private:

    void ExtChar();

    int  InsertChar(unsigned int ii, const char* s);

    int  PushFront(const char* s);

    int  PushBack(const char* s);

    void PrintChar();

    int  GetElem(unsigned int ii, char* s);  

    int  IsEmpty(); 

    int  LocateElem(char* s);

    int DeleteChar(unsigned int ii);

    int PopBack();

    int PopFront();

    int CleanChar();
   

    char* _data;
    unsigned int _length;
    unsigned int _maxsize;
};