#include "MyString.h"

void test01(){

    // MyString str;
    // char s;
    // s = 'z'; str.InsertChar(1,&s);
    // s = 'e'; str.InsertChar(2,&s);
    // s = 'l'; str.InsertChar(3,&s);
    // str.PrintChar();

    // s = 'w'; str.PushBack(&s);
    // s = 'z'; str.PushBack(&s);
    // s = 'y'; str.PushBack(&s);
    // str.PrintChar();

    // s = 'a'; str.PushFront(&s);
    // s = 'h'; str.PushFront(&s);
    // s = 'a'; str.PushFront(&s);
    // s = 'h'; str.PushFront(&s);
    // str.PrintChar();
    // str.GetElem(5,&s);
    // cout << "s:" << s << endl;

    // s = 'z'; int loc = str.LocateElem(&s);
    // cout << s << "在第" << loc << "个位置" << endl;

    // cout << "删除元素：" << endl;
    // str.PopFront();
    // str.PopFront();
    // str.PopFront();
    // str.PopFront();
    // str.PopBack();
    // str.PopBack();
    // str.PopBack();
    // str.PrintChar();

}

void test02(){

    MyString str1;
    str1 = "zel love wzy";
    MyString str2 = str1;
    MyString str3 = "勇士总冠军";
    cout <<"str1: " << str1 << endl;
    cout <<"str2: " << str2 << endl;
    cout <<"str3: " << str3 << endl;
    cout << "str2的长度：" << str2.size() << endl;


}


void test03(){
    int* p1 = (int*)malloc(sizeof(int));
    *p1 = 10;
    cout <<"p1: "<< *p1 <<endl;
    int* p2 = (int*)malloc(sizeof(int));
    *p2 = 20;
    free(p1);
    p1 = p2;
    cout << "p1: " << &p1 <<endl;
    cout << "p2: " << &p2 <<endl;

    

}



int main(){
   
    // test01();
    test02();
    //test03();
    return 0;
}