/*
 * 程序名：seqstack1.cpp，此程序演示顺序栈的实现，数据元素是整数。
 * 作者：ZEL 日期：20220503
*/
#include "include.h"

#define MAX 100

typedef int ElemType; 


typedef struct{
    ElemType     data[MAX];
    int          top;
}SeqStack,*PSeqStack;

// 顺序栈SS的初始化操作。
void InitStack(PSeqStack SS);                     

// 顺序栈SS的初始化操作。
SeqStack* InitStack1();

// 销毁顺序栈SS。
void DestroyStack(PSeqStack SS);

// 元素入栈，返回值：0-失败；1-成功。
int Push(PSeqStack SS, ElemType *ee);

// 元素出栈，返回值：0-失败；1-成功。
int Pop(PSeqStack SS, ElemType *ee);

// 求顺序栈的长度，返回值：栈SS中元素的个数。
int Length(PSeqStack SS);                   

// 清空顺序栈。
void Clear(PSeqStack SS);                    

// 判断顺序栈是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqStack SS);                    

// 判断顺序栈是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqStack SS);

// 打印顺序栈中全部的元素。
void PrintStack(PSeqStack SS);     

// 获取栈顶元素，返回值：0-失败；1-成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(PSeqStack SS, ElemType *ee);

void test01(){

    SeqStack ss;
    ElemType ee;
    ElemType aa;


    InitStack(&ss);
    ee = 1; Push(&ss,&ee);
    ee = 2; Push(&ss,&ee);
    ee = 3; Push(&ss,&ee);
    PrintStack(&ss);
    GetTop(&ss,&aa);
    cout << "aa : " << aa << endl;

}


void test02(){

    PSeqStack ss;
    ElemType ee;
    ElemType aa;


    ss = InitStack1();
    ee = 1; Push(ss,&ee);
    ee = 2; Push(ss,&ee);
    ee = 3; Push(ss,&ee);
    ee = 4; Push(ss,&ee);
    ee = 5; Push(ss,&ee);
    PrintStack(ss);
    cout << "栈的长度为：" << Length(ss) << endl;
    Pop(ss,&ee);
    cout << ee << " 出栈" << endl;
    Pop(ss,&ee);
    cout << ee << " 出栈" << endl;
    Pop(ss,&ee);
    cout << ee << " 出栈" << endl;
    PrintStack(ss);
    GetTop(ss,&aa);
    cout << "栈顶元素: " << aa << endl;
    cout << "栈的长度为：" << Length(ss) << endl;


}




int main(){

    //test01();
    test02();

    return 0;
}



// 顺序栈SS的初始化操作。
void InitStack(PSeqStack SS){
    
    Clear(SS);
}

// 顺序栈SS的初始化操作。
SeqStack* InitStack1(){
    SeqStack* SS = (SeqStack*)malloc(sizeof(SeqStack));
    Clear(SS);
    return SS;
}


// 清空顺序栈。
void Clear(PSeqStack SS){
    if(SS == NULL) return;
    SS->top = -1;
    memset(SS->data,0,sizeof(ElemType)*MAX);
}

// 元素入栈，返回值：0-失败；1-成功。
int Push(PSeqStack SS, ElemType *ee){

    if(SS == NULL || ee == NULL) return 0;
    if(SS->top > MAX) return 0;
    SS->top++;    
    memcpy((SS->data + SS->top),ee,sizeof(ElemType));
    return 1;
}

// 元素出栈，返回值：0-失败；1-成功。
int Pop(PSeqStack SS, ElemType *ee){
    if(SS == NULL || ee == NULL) return 0;
    GetTop(SS,ee);
    SS->top--;
    return 1;
}

// 打印顺序栈中全部的元素。
void PrintStack(PSeqStack SS){
    if(SS == NULL) return;
    if(SS->top == -1) return;
    for(int i = 0;i < Length(SS);i++){
        cout << SS->data[i] << " ";
    }
    cout << endl;
}

// 获取栈顶元素，返回值：0-失败；1-成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(PSeqStack SS, ElemType *ee){
    if(SS == NULL || ee == NULL) return 0;
    memcpy(ee,&SS->data[SS->top],sizeof(ElemType));
    return 1;
}

// 求顺序栈的长度，返回值：栈SS中元素的个数。
int Length(PSeqStack SS){
    if(SS == NULL) return 0;
    return SS->top + 1;
}


// 判断顺序栈是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqStack SS){
    if(SS == NULL) return 0;
    if(SS->top == -1) return 1;
    return 0;
}                    

// 判断顺序栈是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqStack SS){
    if(SS == NULL) return 0;
    if(SS->top > MAX) return 1;
    return 0;
}

// 销毁顺序栈SS。
void DestroyStack(PSeqStack SS){
    if(SS == NULL) return;
    Clear(SS);
}