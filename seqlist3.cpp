#include "include.h"

#define INITSIZE 10
#define EXTSIXE 5

typedef int ElemType;

typedef struct{
    ElemType* data;
    unsigned int length;
    unsigned int maxsize;
}SeqList,*PSeqList;


// 顺序表LL的初始化操作。
void InitList(PSeqList LL);                     

// 销毁顺序表LL。
void DestroyList(PSeqList LL);

// 扩展顺序表的内存空间，返回值：0-失败；1-成功。
int ExtList(PSeqList LL);

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
void PrintList(PSeqList LL);                    

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int  LocateElem(PSeqList LL, ElemType *ee);

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int  DeleteElem(PSeqList LL, unsigned int ii);  

// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL);

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL);





int main(){

    SeqList sl;
    ElemType ee;
    InitList(&sl);
    ee = 1; InsertList(&sl,1,&ee);
    ee = 4; InsertList(&sl,2,&ee);
    ee = 5; InsertList(&sl,3,&ee);
    ee = 2; InsertList(&sl,2,&ee);
    ee = 3; InsertList(&sl,3,&ee);

    PrintList(&sl);
    cout << "表长：" << LengthList(&sl) << endl;

    cout << "头插：" << endl;
    ee = 10; PushFront(&sl,&ee);
    ee = 20; PushFront(&sl,&ee);
    ee = 130; PushFront(&sl,&ee);
    PrintList(&sl);

    cout << "尾插：" << endl;
    ee = 100; PushBack(&sl,&ee);
    ee = 100; PushBack(&sl,&ee);
    ee = 100; PushBack(&sl,&ee);
    ee = 100; PushBack(&sl,&ee);
    ee = 100; PushBack(&sl,&ee);
    ee = 100; PushBack(&sl,&ee);
    ee = 100; PushBack(&sl,&ee);
    ee = 100; PushBack(&sl,&ee);
    ee = 100; PushBack(&sl,&ee);
    PrintList(&sl);
    cout << "表长：" << LengthList(&sl) << endl;

    GetElem(&sl,8,&ee);
    cout << "第8个位置的元素为： "<< ee << endl;

    ee = 100; int loc = LocateElem(&sl,&ee);
    cout << ee << "在顺序表的第" << loc << "个位置" << endl;

    cout << "删除元素：" << endl;
    DeleteElem(&sl,9);
    PopBack(&sl);
    PopBack(&sl);
    PopBack(&sl);
    PopBack(&sl);
    PopBack(&sl);
    PopBack(&sl);
    PopBack(&sl);
    PopBack(&sl);
    PopFront(&sl);
    PopFront(&sl);
    PopFront(&sl);
    DeleteElem(&sl,1);

    PrintList(&sl);




    return 0;
}










// 顺序表LL的初始化操作。
void InitList(PSeqList LL){
    LL->data = (ElemType*)malloc(sizeof(ElemType)*INITSIZE);
    LL->maxsize = INITSIZE;
    ClearList(LL);
}

// 清空顺序表。
void ClearList(PSeqList LL){
    if(LL == NULL) return;

    memset(LL->data,0,sizeof(ElemType)*LL->maxsize);
    LL->length = 0;
}

// 扩展顺序表的内存空间，返回值：0-失败；1-成功。
int ExtList(PSeqList LL){
    ElemType* newdata = (ElemType*)malloc(sizeof(ElemType)*LL->maxsize + sizeof(ElemType)*EXTSIXE);

    if(newdata == NULL) return 0;

    memset(newdata,0,sizeof(ElemType)*(LL->maxsize + EXTSIXE));

    memcpy(newdata,LL->data,sizeof(ElemType)*LL->maxsize);
    free(LL->data);
    LL->data = newdata;
    LL->maxsize += EXTSIXE;

    return 1;
}

// 在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee){
    if(LL == NULL || ee == NULL) return 0;
    if(LL->length >= LL->maxsize){
        ExtList(LL);     
    }

    for(int i = LL->length + 1;i > ii - 1;i--){
        memcpy((LL->data + i),(LL->data + i - 1),sizeof(ElemType));
    }
    // *(LL->data + ii) = *ee;

    memcpy(LL->data + ii - 1,ee,sizeof(ElemType));
    LL->length++;

    return 1;
}

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType *ee){
    return InsertList(LL,1,ee);
}

// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int  PushBack(PSeqList LL, ElemType *ee){
    return InsertList(LL,LL->length + 1,ee);
}

// 打印顺序表中全部的元素。
void PrintList(PSeqList LL){
    for(int i = 0;i < LL->length;i++){
        cout << *(LL->data + i) << " ";
    }
    cout << endl; 
}

// 求顺序表的长度，返回值：>=0-表LL元素的个数。
int  LengthList(PSeqList LL){
    if(LL == NULL) return 0;
    return LL->length;
}


// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee){
    if(LL == NULL || ee == NULL) return 0;
    if(ii < 1 || ii > LL->length) return 0;
    
    memcpy(ee,LL->data + ii - 1,sizeof(ElemType));
    return 1;
}

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int  LocateElem(PSeqList LL, ElemType *ee){
    if(LL == NULL || ee == NULL) return 0;

    for(int i = 0;i < LL->length;i++){
        if(*(LL->data + i) == *ee) return i + 1;
    }

    return 0;
}

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int  DeleteElem(PSeqList LL, unsigned int ii){
    if(LL == NULL) return 0;
    if(LL->length == 0) return 0;
    if(ii > LL->length) return 0;
    for(int i = ii - 1;i < LL->length;i++){
        memcpy(LL->data + i,LL->data + i + 1,sizeof(ElemType));
    }
    LL->length--;
    return 0;
}  

// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL){
    return DeleteElem(LL,1);
}

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL){
    return DeleteElem(LL,LL->length);
}