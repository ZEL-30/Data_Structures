/*
 * 程序名：seqstack2.cpp，此程序演示顺序栈的动态实现，数据元素是整数。
 * 作者：ZEL 日期：20220503
*/
#include "include.h"

#define ININSIZE  10
#define EXTSIZE   5

typedef int ElemType;

typedef struct{
    ElemType*        data;
    int              top;
    unsigned int     maxsize;

}SeqStack,*PSeqStack;

// 顺序栈SS的初始化操作。
void InitStack(PSeqStack SS);                     

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

int ExtStack(PSeqStack SS);


void test01(){

    SeqStack ss;
    ElemType ee;
    ElemType aa;


    InitStack(&ss);
    ee = 1; Push(&ss,&ee);
    ee = 2; Push(&ss,&ee);
    ee = 3; Push(&ss,&ee);
    ee = 4; Push(&ss,&ee);
    ee = 5; Push(&ss,&ee);
    ee = 6; Push(&ss,&ee);
    ee = 7; Push(&ss,&ee);
    ee = 8; Push(&ss,&ee);
    ee = 9; Push(&ss,&ee);
    ee = 10; Push(&ss,&ee);
    ee = 11; Push(&ss,&ee);
    ee = 12; Push(&ss,&ee);
    ee = 13; Push(&ss,&ee);
    PrintStack(&ss);
    cout << "栈的长度为：" << Length(&ss) << endl;
    Pop(&ss,&ee);
    cout << ee << " 出栈" << endl;
    Pop(&ss,&ee);
    cout << ee << " 出栈" << endl;
    Pop(&ss,&ee);
    cout << ee << " 出栈" << endl;
    PrintStack(&ss);
    //GetTop(&ss,&aa);
    cout << "栈顶元素: " << aa << endl;
    cout << "栈的长度为：" << Length(&ss) << endl;


}




int main(){

    test01();

    return 0;
}


// 顺序栈SS的初始化操作。
void InitStack(PSeqStack SS){
    SS->data = (ElemType*)malloc(sizeof(ElemType)*ININSIZE);
    SS->maxsize = ININSIZE;
    Clear(SS);
}

// 清空顺序栈。
void Clear(PSeqStack SS){
    if(SS == NULL) return;
    memset(SS->data,0,sizeof(ElemType)*ININSIZE);
    SS->top = -1;
}

int ExtStack(PSeqStack SS){
    if(SS == NULL) return 0;
    ElemType* newdata = (ElemType*)malloc(sizeof(ElemType)*(SS->maxsize + EXTSIZE));
    memcpy(newdata,SS->data,sizeof(ElemType)*SS->maxsize);
    free(SS->data);
    SS->data = newdata;
    SS->maxsize += EXTSIZE;
    return 1;
}

// 元素入栈，返回值：0-失败；1-成功。
int Push(PSeqStack SS, ElemType *ee){
    if(SS == NULL || ee == NULL) return 0;
    if(SS->top >= SS->maxsize) ExtStack(SS);
    SS->top++;
    memcpy((SS->data + SS->top),ee,sizeof(ElemType));
    return 1;
}



// 元素出栈，返回值：0-失败；1-成功。
int Pop(PSeqStack SS, ElemType *ee){
    if(SS == NULL || ee == NULL) return 0;
    memcpy(ee,SS->data + SS->top,sizeof(ElemType));
    SS->top--;
    return 1;
}

// 求顺序栈的长度，返回值：栈SS中元素的个数。
int Length(PSeqStack SS){
    if(SS == NULL) return 0;
    return SS->top + 1;
}


// 打印顺序栈中全部的元素。
void PrintStack(PSeqStack SS){
    if(SS == NULL) return;
    for(int i = 0;i < Length(SS);i++){
        cout << *(SS->data + i) << " ";
    }
    cout << endl;
}