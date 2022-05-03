#include "include.h"


int main(){

    int a;
    char b;
    char c[10];
    cout << sizeof(a) << endl;   // 4
    cout << sizeof(b) << endl;   // 1
    cout << sizeof(c) << endl;   // 10

    struct stu{
        char          name[50];
        int           age;
        char          gender[20];
        long long     sid;
    };

    cout << sizeof(stu) << endl;   // 74 + 10 + 2 = 82




    return 0;
}