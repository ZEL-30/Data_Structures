#include "MyString.h"


//MyString::

MyString::MyString(){
    _data = (char*)malloc(sizeof(char)*INITSIZE);
    _maxsize = INITSIZE;
    CleanChar();
   
}

int MyString::CleanChar(){
    if(this == NULL) return 0;
    memset(_data,0,sizeof(char)*_maxsize);
    _length = 0;
    return 1;
}


void MyString::ExtChar(){
    char* newdata = (char*)malloc(sizeof(char)*(_maxsize + EXTSIZE));
    memset(newdata,0,sizeof(char)*(_maxsize + EXTSIZE));
    
    memcpy(newdata,_data,sizeof(char)*(_maxsize + EXTSIZE));
    free(_data);
    _data = newdata;
    _maxsize += EXTSIZE;

}

int  MyString::InsertChar(unsigned int ii, const char* s){
    if(this == NULL) return 0;
    if(_length >= _maxsize) ExtChar();
    for(int i = _length + 1;i > ii - 1;i--){
        memcpy(_data + i,_data + i - 1,sizeof(char));
    }
    memcpy(_data + ii - 1,s,sizeof(char));
    _length++;
    return 1;
}

 int  MyString::PushFront(const char* s){
    return InsertChar(1,s);
 }

 int  MyString::PushBack(const char* s){
    return InsertChar(_length + 1,s);
 }

void MyString::PrintChar(){
    for(int i = 0;i < _length;i++){
        cout << *(_data + i);
    }
    cout << endl;
}

int  MyString::GetElem(unsigned int ii, char* s){
    if(this == NULL) return 0;
    if(ii < 0 || ii > _length) return 0;

    memcpy(s,_data + ii -1,sizeof(char));
    return 1;
}  

int  MyString::IsEmpty(){
    if(this == NULL) return 0;
    if(_length == 0) return 1; 
    return 0;
}



int  MyString::LocateElem(char* s){
    if(this == NULL) return 0;
    for(int i = 0;i < _length;i++){
        if(*(_data + i) == *s){
            return i + 1;
        }
    }
    return 0;
}


int MyString::DeleteChar(unsigned int ii){
    if(this == NULL) return 0;
    if(ii > _length) return 0;
    for(int i = ii - 1;i < _length;i++){
        memcpy(_data + i,_data + i + 1,sizeof(char));
    }
    _length--;
    return 1;
}

int MyString::PopBack(){
    return DeleteChar(_length);
}

int MyString::PopFront(){
    return DeleteChar(1);
}


MyString& MyString::assign(const char s){
    CleanChar();
    PushBack(&s);
    return *this;
}

MyString& MyString::assign(const MyString &str){
    CleanChar();
    for(int i = 0;i < str._length;i++){
        PushBack(str._data + i);
    }
    return *this;

}

MyString& MyString::assign(const char str[]){
    CleanChar();
    for(int i = 0;;i++){
        if(*(str + i) == '\0')  break;
        PushBack((str + i));
    }
    return *this;

}

MyString::MyString(const char str[]){
    _data = (char*)malloc(sizeof(char)*INITSIZE);
    _maxsize = INITSIZE;
    assign(str);
}

MyString::MyString(const MyString &str){
    _data = (char*)malloc(sizeof(char)*INITSIZE);
    _maxsize = INITSIZE;
    assign(str);
}



ostream& operator<<(ostream &cout,MyString &string){
    for(int i = 0;i < string._length;i++){
        cout << *(string._data + i);
    }
    return cout;
}


MyString& MyString::operator=(const char s){
    return assign(s);
}

MyString& MyString::operator=(const MyString &str){
    return assign(str);
}


MyString& MyString::operator=(const char str[]){
    return assign(str);
}


int MyString::size(){
    if(this == NULL) return 0;
    return _length;
}









MyString::~MyString(){
    if(this == NULL || _data == NULL) return;
    free(_data);
    _data = NULL;
    _maxsize = 0;
    _length = 0;
}

