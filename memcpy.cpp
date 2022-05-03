#include "include.h"

class Student{

public:
    Student();
    Student(string name,int age,string gender);
    void showinfo();

private:
    string _name;
    int    _age;
    string _gender;
};




int main(){

    Student st1("张恩乐",22,"男");
    Student st2;
    cout << "学生类一：" << endl;
    st1.showinfo();
    memcpy(&st2,&st1,sizeof(st1));
    cout << "学生类二：" << endl;
    st2.showinfo();

}

Student::Student(){

}

Student::Student(string name,int age,string gender){
    this->_name = name;
    this->_age = age;
    this->_gender = gender;
}

void Student::showinfo(){
    cout << "姓名：" << _name << "\t年龄：" << _age << "\t性别：" << _gender << endl;
}