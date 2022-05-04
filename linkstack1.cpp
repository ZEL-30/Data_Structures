/*
 * 程序名：linkstack1.c，此程序演示链栈的实现，数据元素是整数。
 * 作者：ZEL 日期：20220504
*/

#include "include.h"

typedef int ElemType;

typedef struct SNode{
    ElemType*       data;
    SNode*          next;
}*LinkStack;

// 链栈SS的初始化操作，分配头结点，返回头结点的地址。
SNode *InitStack();

// 销毁链栈SS。
void DestroyStack(LinkStack SS);

// 元素入栈，返回值：0-失败；1-成功。
int Push(LinkStack SS, ElemType *ee);

// 元素出栈，返回值：0-失败；1-成功。
int Pop(LinkStack SS, ElemType *ee);

// 求链栈的长度，返回值：栈SS中元素的个数。
int  Length(LinkStack SS);                   

// 清空链栈。
void Clear(LinkStack SS);                    

// 判断链栈是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(LinkStack SS);                    

// 打印链栈中全部的元素。
void PrintStack(LinkStack SS);                    

// 获取栈顶元素，返回值：0-失败；1-成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(LinkStack SS, ElemType *ee);


int main(){

    LinkStack ls;
    ElemType ee;

    ls = InitStack();
    ee = 1; Push(ls,&ee);
    ee = 2; Push(ls,&ee);
    ee = 3; Push(ls,&ee);
    ee = 10; Push(ls,&ee);
    ee = 11; Push(ls,&ee);
    ee = 12; Push(ls,&ee);
    ee = 13; Push(ls,&ee);
    PrintStack(ls);
    cout << "栈的长度为：" << Length(ls) << endl;
    Pop(ls,&ee);
    cout << ee << " 出栈" << endl;
    Pop(ls,&ee);
    cout << ee << " 出栈" << endl;
    Pop(ls,&ee);
    cout << ee << " 出栈" << endl;
    PrintStack(ls);
    cout << "栈的长度为：" << Length(ls) << endl;
    GetTop(ls,&ee);
    cout << "栈顶元素为：" << ee << endl;
    DestroyStack(ls);

    return 0;
}


// 链栈SS的初始化操作，分配头结点，返回头结点的地址。
SNode* InitStack(){
    SNode* head = (SNode*)malloc(sizeof(SNode));
    if(head == NULL) return NULL;
    head->next = NULL;
    return head;

}

// 清空链栈。
void Clear(LinkStack SS){
    if(SS == NULL) return;
    SNode* tmp1;
    SNode* tmp2 = SS->next;
    while(SS != NULL){
        tmp1 = tmp2->next;
        free(tmp2);
        tmp2 = tmp1;
    }

    SS->next = NULL;
    
    return;
}

// 元素入栈，返回值：0-失败；1-成功。
int Push(LinkStack SS, ElemType *ee){
    if(SS == NULL || ee == NULL) return 0;

    SNode* newnode = (SNode*)malloc(sizeof(SNode));
    newnode->data = (ElemType*)malloc(sizeof(ElemType));
    memcpy(newnode->data,ee,sizeof(ElemType));
    newnode->next = SS->next;
    SS->next = newnode;
    return 1;
}

// 元素出栈，返回值：0-失败；1-成功。
int Pop(LinkStack SS, ElemType *ee){
    if(SS == NULL || ee == NULL) return 0;
    memcpy(ee,SS->next->data,sizeof(ElemType));
    SS->next = SS->next->next;
    return 1;
}


// 打印链栈中全部的元素。
void PrintStack(LinkStack SS){
    if(SS == NULL) return;
    SNode* cur = SS->next;
    while(cur != NULL){
        cout << *(cur->data) << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 求链栈的长度，返回值：栈SS中元素的个数。
int  Length(LinkStack SS){
    if(SS == NULL) return 0;
    SNode* cur = SS->next;
    int len = 0;
    while(cur != NULL){
        len++; cur = cur->next;
    }
    return len;
}

// 获取栈顶元素，返回值：0-失败；1-成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(LinkStack SS, ElemType *ee){
    if(SS == NULL || ee == NULL) return 0;
    memcpy(ee,SS->next->data,sizeof(ElemType));
    return 1;
}

// 销毁链栈SS。
void DestroyStack(LinkStack SS){
    if(SS == NULL) return;
    SNode* tmp;
    while(SS != NULL){
        tmp = SS->next;
        free(SS);
        SS = tmp;
    }
    return;
}