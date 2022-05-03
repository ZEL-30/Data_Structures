/*
 * 程序名：linklist2.cpp，此程序演示带头结点的单链表的实现，数据元素是结构体。
 * 作者：ZEL 日期：20220502
*/


#include "include.h"


typedef struct{
    char          name[50];
    int           age;
    char          gender[20];
    long long     sid;
}ElemType;


typedef struct LNode{
    ElemType      data;
    LNode*        next;
}*LinkList;
  
// 初始化链表LL，返回值：失败返回NULL，成功返回头结点的地址。
LNode *InitList1();

// 传入指针变量的地址的方法。
// 初始化链表，返回值：0-失败；1-成功。
int InitList2(LinkList *LL);

// C++引用的方法，在Linux下，需要用g++编译。
// 初始化链表，返回值：0-失败；1-成功。
// int InitList3(LinkList &LL);

// 如果参数采用转指针LL的值，LL的值只能传进去，无法返回，这种方法是不行的。
int InitList4(LinkList LL);

// 销毁链表LL。
void DestroyList1(LinkList LL);

// 销毁链表LL。
// 传入指针的地址的方法。
void DestroyList2(LinkList *LL);

// C++引用的方法，在Linux下，需要用g++编译。
// 传入指针的地址的方法。
// void DestroyList3(LinkList &LL);

// 清空链表。
void ClearList(LinkList LL);                    

// 在链表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(LinkList LL, unsigned int ii, ElemType *ee);   

// 打印链表中全部的元素。
void PrintList(LinkList LL);                    

// 在链表LL的头部插入元素ee，返回值：0-失败；1-成功。
int  PushFront(LinkList LL, ElemType *ee);

// 在链表LL的尾部插入元素ee，返回值：0-失败；1-成功。
int  PushBack(LinkList LL, ElemType *ee);

// 删除链表LL中的第ii个结点，返回值：0-位置ii不合法；1-成功。
int  DeleteNode(LinkList LL, unsigned int ii);  

// 删除链表LL中第一个结点，返回值：0-位置不合法；1-成功。
int PopFront(LinkList LL);

// 删除链表LL中最后一个结点，返回值：0-位置不合法；1-成功。
int PopBack(LinkList LL);

// 求链表的长度，返回值：>=0-表LL结点的个数。
int  LengthList(LinkList LL);                   

// 判断链表是否为空，返回值：0-非空或失败，1-空。
int IsEmpty(LinkList LL);

// 获取链表中第ii个结点，成功返回结点的地址，失败返回空。
// 注意，ii可以取值为0，表示头结点。
LNode *LocateNode(LinkList LL, unsigned int ii);

// 查找元素ee在链表LL中的结点地址，如果没找到返回NULL，否则返回结点的地址。
LNode *LocateElem(LinkList LL, ElemType *ee);

// 在指定结点pp之后插入元素ee，返回值：0-失败；1-成功。
int InsertNextNode(LNode *pp, ElemType *ee);

// 在指定结点pp之前插入元素ee，返回值：0-失败；1-成功。
int InsertPriorNode(LNode *pp, ElemType *ee);

// 删除指定结点。
int DeleteNode1(LNode *pp);


// 把链表pp结点之后的结点原地逆置（反转
LNode* ReverseList(LNode *pp);


void test01(){

    LinkList ll = NULL;
    ElemType ee;


    ll = InitList1();
    ee = {"张恩乐",23,"男",201802464052};  InsertList(ll,1,&ee);
    ee = {"王仔怡",20,"女",201802464072};  PushBack(ll,&ee);
    ee = {"周鸿",23,"男",201802464047};  PushFront(ll,&ee);
    ee = {"杨广",21,"男",201802464042};  PushBack(ll,&ee);
    ee = {"陈哲",21,"男",201802464036};  PushBack(ll,&ee);
    PrintList(ll);

    // cout << "删除元素：" << endl;
    // DeleteNode(ll,4);
    // PopBack(ll);
    // PopFront(ll);
    // PrintList(ll);
    // cout << "表长为：" << LengthList(ll) << endl;

    LNode* node = LocateNode(ll,3);
    cout << node->data.name << endl;

    ElemType bb = {"周鸿",23,"男",201802464047};
    LNode* aa = LocateElem(ll,&bb);
    cout << aa->data.name << endl;

    LNode* pp = (LNode*)malloc(sizeof(LNode)); pp->next = NULL;
    LNode* zxc = (LNode*)malloc(sizeof(LNode)); zxc->next = NULL;
    ElemType ww = {"张恩乐",23,"男",201802464047};
    ElemType oo = {"杨文龙",23,"男",201802464047};
    InsertNextNode(pp,&ww);
    InsertPriorNode(pp,&oo);
    cout << "pp的前面：" << zxc->data.name << "pp的后面："<< pp->next->data.name << endl;

}


void test02(){

    LinkList ll = NULL;
    ElemType ee;


    ll = InitList1();
    ee = {"张恩乐",23,"男",201802464052};  InsertList(ll,1,&ee);
    ee = {"王仔怡",20,"女",201802464072};  PushBack(ll,&ee);
    ee = {"周鸿",23,"男",201802464047};  PushFront(ll,&ee);
    ee = {"杨广",21,"男",201802464042};  PushBack(ll,&ee);
    ee = {"陈哲",21,"男",201802464036};  PushBack(ll,&ee);
    PrintList(ll);

    cout << "反转后:" << endl;
    
    PrintList(ReverseList(ll));

}





int main(){

    // test01();
    test02();

    return 0;
}









// 初始化链表LL，返回值：失败返回NULL，成功返回头结点的地址。
LNode *InitList1(){
    LNode* head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    return head;
}

// 在链表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(LinkList LL, unsigned int ii, ElemType *ee){
    if(LL == NULL || ee == NULL) return 0;
    if(ii < 1){
        cout << "插入位置不合法" << endl;
        return 0;
    }
    LNode* cur = LL;

    int i = 0;
    while(cur != NULL && i < ii - 1){
        cur = cur->next;
        i++;
    }
    if(cur == NULL){
        cout << "位置"<< ii <<"不合法，超过了表长。" << endl;
        return 0;
    }

    LNode* newnode = (LNode*)malloc(sizeof(LNode));
    // LNode* newnode = new LNode();
    if(newnode == NULL) return 0;
    memcpy(&newnode->data,ee,sizeof(ElemType));
    newnode->next = cur->next;
    cur->next = newnode;
    return 1;

}

// 打印链表中全部的元素。
void PrintList(LinkList LL){

    LNode* cur = LL->next;
    while(cur != NULL){
        cout << "姓名：" << cur->data.name << "年龄：" << cur->data.age<< "性别：" << cur->data.gender << "学号：" << cur->data.sid << endl;
        cur = cur->next;
    }
}

// 在链表LL的头部插入元素ee，返回值：0-失败；1-成功。
int  PushFront(LinkList LL, ElemType *ee){
    return InsertList(LL,1,ee);
}


// 在链表LL的尾部插入元素ee，返回值：0-失败；1-成功。
int  PushBack(LinkList LL, ElemType *ee){
    return InsertList(LL,LengthList(LL) + 1,ee);
}

// 删除链表LL中的第ii个结点，返回值：0-位置ii不合法；1-成功。
int  DeleteNode(LinkList LL, unsigned int ii){
    if(LL == NULL) return 0;
    if(ii < 1) return 0;
    int i = 0;
    LNode* cur = LL;
    while(cur != NULL && i < ii - 1){
        cur = cur->next; i++;
    }
    if(cur == NULL) return 0;
    LNode* tmp = cur->next;
    cur->next = cur->next->next;
    free(tmp); tmp = NULL;
    return 1;
}

// 删除链表LL中第一个结点，返回值：0-位置不合法；1-成功。
int PopFront(LinkList LL){
    return DeleteNode(LL,1);

}

// 删除链表LL中最后一个结点，返回值：0-位置不合法；1-成功。
int PopBack(LinkList LL){
    return DeleteNode(LL,LengthList(LL));
}

// 求链表的长度，返回值：>=0-表LL结点的个数。
int  LengthList(LinkList LL){
    int length = 0;
    LNode* cur = LL->next;
    while(cur != NULL){
        cur = cur->next;
        length++;
    }
    return length;
}

// 判断链表是否为空，返回值：0-非空或失败，1-空。
int IsEmpty(LinkList LL){
    if(LL == NULL) return 0;
    if(LL->next == NULL) return 1;
    return 0;
}


// 获取链表中第ii个结点，成功返回结点的地址，失败返回空。
// 注意，ii可以取值为0，表示头结点。
LNode* LocateNode(LinkList LL, unsigned int ii){
    if(LL == NULL) return NULL;
    if(ii > LengthList(LL)) return NULL;
    int i = 0;
    LNode* cur = LL;
    while(cur != NULL && i < ii){
        cur = cur->next; i++;
    } 
    return cur;

}

// 查找元素ee在链表LL中的结点地址，如果没找到返回NULL，否则返回结点的地址。
LNode* LocateElem(LinkList LL, ElemType *ee){
    if(LL == NULL || ee == NULL) return NULL;
    LNode* cur = LL->next;
    while(cur != NULL){
        if(cur->data.sid == ee->sid) return cur;
        cur = cur->next;
    }
    return NULL;
}

// 在指定结点pp之后插入元素ee，返回值：0-失败；1-成功。
int InsertNextNode(LNode *pp, ElemType *ee){
    if(pp == NULL || ee == NULL) return 0;
    LNode* tmp = (LNode*)malloc(sizeof(LNode));
    memcpy(&tmp->data,ee,sizeof(ElemType));
    tmp->next = pp->next;
    pp->next = tmp;
    return 1;
}

// 在指定结点pp之前插入元素ee，返回值：0-失败；1-成功。
int InsertPriorNode(LNode *pp, ElemType *ee){
    if(pp == NULL || ee == NULL) return 0;
    LNode* head = (LNode*)malloc(sizeof(LNode)); 
    head->next = pp;
    InsertNextNode(head,ee);
    return 1;
}

// 删除指定结点。
int DeleteNode1(LNode *pp){
    if(pp == NULL) return 0;
    LNode* tmp = pp->next;
    memcpy(&pp->data,&tmp->data,sizeof(ElemType));
    free(tmp);
    return 1;
}


// 把链表pp结点之后的结点原地逆置（反转）
LNode* ReverseList(LNode *pp){
    LNode* p = NULL;
    LNode* cur = pp->next;

    while(cur != NULL){
        LNode* tmp = cur->next;
        cur->next = p;
        p = cur;
        cur = tmp;
    }
    LNode* head = (LNode*)malloc(sizeof(LNode));
    head->next = p;
    return head;
}
