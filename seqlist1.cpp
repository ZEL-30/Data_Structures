/*
 * 程序名：seqlist1.cpp，此程序演示顺序表的静态实现，数据元素是整数。
 * 作者：ZEL 日期：20220430
*/

#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1000

typedef int ElemType;

typedef struct{
    ElemType data[MAX];
    unsigned int length;
}SeqList,*PSeqList;

// 顺序表LL的初始化操作。
void InitList(PSeqList LL);                     

// 销毁顺序表LL。
void DestroyList(PSeqList LL);

// 在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee);   

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType *ee);

// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int  PushBack(PSeqList LL, ElemType *ee);

// 求顺序表的长度，返回值：>=0-表LL元素的个数。
int  LengthList(PSeqList LL);                   

// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee);  

// 清空顺序表。
void ClearList(PSeqList LL);                    

// 判断顺序表是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PSeqList LL);                    

// 打印顺序表中全部的元素。
void PrintList(SeqList LL);                    

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int  LocateElem(PSeqList LL, ElemType *ee);

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int  DeleteElem(PSeqList LL, unsigned int ii);  

// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL);

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL);

// 采用归并的方法，将两个升序的顺序表La和Lb，合并成一个升序的顺序表Lc。
int MergeList(PSeqList La,PSeqList Lb,PSeqList Lc);




void test01(){

    SeqList sl;
    ElemType ee;

    InitList(&sl);

    cout << "顺序表:" << endl;
    ee = 4; InsertList(&sl,0,&ee);
    ee = 5; InsertList(&sl,1,&ee);
    ee = 6; InsertList(&sl,2,&ee);
    ee = 7; InsertList(&sl,3,&ee);
    PrintList(sl);
    cout << "表长：" << LengthList(&sl) << endl;

    cout << "尾插 8 9 10 :" << endl;
    ee = 8; PushBack(&sl,&ee);
    ee = 9; PushBack(&sl,&ee);
    ee = 10; PushBack(&sl,&ee);
    PrintList(sl);
    cout << "表长：" << LengthList(&sl) << endl;


    cout << "头插 1 2 3 :" << endl;
    ee = 3; PushFront(&sl,&ee);
    ee = 2; PushFront(&sl,&ee);
    ee = 1; PushFront(&sl,&ee);
    PrintList(sl);
    cout << "表长：" << LengthList(&sl) << endl;

    
    ee = 4; int loc = LocateElem(&sl,&ee);
    cout << "lco: " << loc <<endl;


    DeleteElem(&sl,10);
    cout << "删除元素：" << endl;
    PrintList(sl);

    PopBack(&sl);
    PrintList(sl);

    PopFront(&sl);
    PrintList(sl);    

}

void test02(){
    SeqList sl1;
    SeqList sl2;
    SeqList sl3;

    ElemType e;

    InitList(&sl1);
    InitList(&sl2);
    InitList(&sl3);

    e = 1; PushBack(&sl1,&e);
    e = 20; PushBack(&sl1,&e);
    e = 34; PushBack(&sl1,&e);
    e = 45; PushBack(&sl1,&e);
    e = 56; PushBack(&sl1,&e);

    e = 6; PushBack(&sl2,&e);
    e = 7; PushBack(&sl2,&e);
    e = 8; PushBack(&sl2,&e);
    e = 9; PushBack(&sl2,&e);
    e = 10; PushBack(&sl2,&e);

    cout << "顺序表一：" << endl;
    PrintList(sl1);
    cout << "顺序表二：" << endl;
    PrintList(sl2);

    cout << "归并合并后：" << endl;
    MergeList(&sl1,&sl2,&sl3);
    PrintList(sl3);



}


int main (){
    
    test01();
    //test02();
    return 0;

}








void InitList(PSeqList LL){
    ClearList(LL);
}

void ClearList(PSeqList LL){
    if(LL == NULL) return;
    LL->length = 0;
    memset(LL->data,10,sizeof(ElemType)*MAX);
}

// 在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee){
    if(LL->length > MAX) return 0;
    if(ii > LL->length) return 0;

    for(int i = LL->length + 1;i > ii;i--){
        LL->data[i] = LL->data[i - 1]; 
    }
    LL->data[ii] = *ee;
    LL->length++;
    return 1;
}



// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int  PushBack(PSeqList LL, ElemType* ee){
    return InsertList(LL,LL->length,ee);
}

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType *ee){
    return InsertList(LL,0,ee);
}

// 打印顺序表中全部的元素。
void PrintList(SeqList LL){
    if (LL.length == 0) return;

    for(int i = 0;i < LL.length;i++){
        cout << LL.data[i] << " ";
    }
    cout << endl;
}

// 求顺序表的长度，返回值：>=0-表LL元素的个数。
int  LengthList(PSeqList LL){
    if (LL == NULL) return 0;
    return LL->length;
}

// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee){
    if(ii < 1 || ii > LL->length) return 0;
    if(ee == NULL || LL == NULL) return 0;

    memcpy(ee,&LL->data[ii - 1],sizeof(ElemType));
    return 1;

}

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int  LocateElem(PSeqList LL, ElemType *ee){
    if(LL == NULL || ee == NULL) return 0;
    for(int i = 0;i < LL->length;i++){
        if(*ee == LL->data[i]) return i + 1;
    }
    return 0;

}

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int  DeleteElem(PSeqList LL, unsigned int ii){
    if(LL == NULL) return 0;
    if(ii < 1 || ii > LL->length) return 0;
    for(int i = ii - 1;i < LL->length;i++){
        memcpy(&LL->data[i],&LL->data[i + 1],sizeof(ElemType));
    }
    LL->length--;
    return 1;
}  

// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL){
    return DeleteElem(LL,1);
}

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL){
    return DeleteElem(LL,LL->length);
}

// 采用归并的方法，将两个升序的顺序表La和Lb，合并成一个升序的顺序表Lc。
int MergeList(PSeqList La,PSeqList Lb,PSeqList Lc){
    if(La == NULL || Lb == NULL) return 0;
    if(La->length + Lb->length > MAX){
        printf("Lc的表长不足，无法合并！\n");
        return 0;
    }

    int La_start = 0;
    int Lb_start = 0;
    int Lc_start = 0;

    while(La_start < La->length && Lb_start < Lb->length){
        Lc->data[Lc_start++] = La->data[La_start] > Lb->data[Lb_start] ? Lb->data[Lb_start++] : La->data[La_start++];
    }
    while(La_start < La->length) Lc->data[Lc_start++] = La->data[La_start++];
    while(Lb_start < Lb->length) Lc->data[Lc_start++] = Lb->data[Lb_start++];
    Lc->length = La->length + Lb->length;

    return 1;
}

// 销毁顺序表LL。
void DestroyList(PSeqList LL)
{
  // 静态顺序表无需释放内存，不需要销毁操作。
  return;
}