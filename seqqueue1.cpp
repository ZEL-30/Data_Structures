/*
 * 程序名：seqqueue1.cpp，此程序演示循环队列的数组实现，队尾指针指向队尾的下一个元素，增加了length的辅助变量。
 * 作者：ZEL 日期：20220504
*/

#include "include.h"

#define MAXSIZE 10

typedef int ElemType;

typedef struct{
    ElemType*       data;
    int             front;
    int             rear;
    unsigned int    length;
}SeqQueue,*PSeqQueue;

// 循环队列QQ的初始化操作。
void InitQueue(PSeqQueue QQ);                     

// 销毁循环队列QQ。
void DestroyQueue(PSeqQueue QQ);

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PSeqQueue QQ, ElemType *ee);

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PSeqQueue QQ, ElemType *ee);

// 求循环队列的长度，返回值：>=0-队列QQ元素的个数。
int Length(PSeqQueue QQ);                   

// 清空循环队列。
void Clear(PSeqQueue QQ);                    

// 判断循环队列是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqQueue QQ);                    

// 判断循环队列是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqQueue QQ);

// 打印循环队列中全部的元素。
void PrintQueue(PSeqQueue QQ);                    

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PSeqQueue QQ, ElemType *ee);


int main(){

    SeqQueue QQ;     // 创建循环队列。

    InitQueue(&QQ);  // 初始化循环队列。

    ElemType ee;     // 创建一个数据元素。

    printf("元素（1、2、3、4、5、6、7、8、9、10、11）入队。\n");
    ee=1;  InQueue(&QQ, &ee);
    ee=2;  InQueue(&QQ, &ee);
    ee=3;  InQueue(&QQ, &ee);
    ee=4;  InQueue(&QQ, &ee);
    ee=5;  InQueue(&QQ, &ee);
    ee=6;  InQueue(&QQ, &ee);
    ee=7;  InQueue(&QQ, &ee);
    ee=8;  InQueue(&QQ, &ee);
    ee=9;  InQueue(&QQ, &ee);
    ee=10; InQueue(&QQ, &ee);
    ee=11; InQueue(&QQ, &ee);

    printf("队列的长度是%d\n",Length(&QQ));
    PrintQueue(&QQ);

    if (OutQueue(&QQ,&ee)==1)  printf("出队的元素值为%d\n",ee);
    if (OutQueue(&QQ,&ee)==1)  printf("出队的元素值为%d\n",ee);
    if (OutQueue(&QQ,&ee)==1)  printf("出队的元素值为%d\n",ee);
    if (OutQueue(&QQ,&ee)==1)  printf("出队的元素值为%d\n",ee);
    if (OutQueue(&QQ,&ee)==1)  printf("出队的元素值为%d\n",ee);
    if (OutQueue(&QQ,&ee)==1)  printf("出队的元素值为%d\n",ee);
    if (OutQueue(&QQ,&ee)==1)  printf("出队的元素值为%d\n",ee);

    printf("队列的长度是%d\n",Length(&QQ));
    PrintQueue(&QQ);

    printf("元素（11、12、13、14、15）入队。\n");
    ee=11;  InQueue(&QQ, &ee);
    ee=12;  InQueue(&QQ, &ee);
    ee=13;  InQueue(&QQ, &ee);
    ee=14;  InQueue(&QQ, &ee);
    ee=15;  InQueue(&QQ, &ee);

    printf("队列的长度是%d\n",Length(&QQ));

    PrintQueue(&QQ);

    // 只查看队头元素的值，元素不出队。
    if (GetHead(&QQ,&ee)==1)  printf("队头的元素值为%d\n",ee);

    return 0;



}


// 循环队列QQ的初始化操作。
void InitQueue(PSeqQueue QQ){
    if(QQ == NULL) return;
    QQ->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    Clear(QQ);
}


// 清空循环队列。
void Clear(PSeqQueue QQ){
    if(QQ == NULL) return;
    memset(QQ->data,0,sizeof(ElemType)*MAXSIZE);
    QQ->front = QQ->rear = QQ->length = 0;
}

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PSeqQueue QQ, ElemType *ee){
    if(QQ == NULL || ee == NULL) return 0;
    if(IsFull(QQ) == 1) return 0;
    memcpy(QQ->data + QQ->rear,ee,sizeof(ElemType));
    QQ->rear = (QQ->rear+1) % MAXSIZE; 
    QQ->length++;
    return 1;
}

// 打印循环队列中全部的元素。
void PrintQueue(PSeqQueue QQ){
    if(QQ == NULL) return;
    for(int i = 0;i < QQ->length;i++){
        cout << *(QQ->data + (QQ->front + i) % MAXSIZE) << " ";
    }
    cout << endl;
}

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PSeqQueue QQ, ElemType *ee){
    if(QQ == NULL || ee == NULL) return 0;
    if(IsEmpty(QQ) == 1) return 0;
    memcpy(ee,QQ->data + QQ->front,sizeof(ElemType));
    QQ->front = (QQ->front + 1) % MAXSIZE;
    QQ->length--;
    return 1;
}

// 求循环队列的长度，返回值：>=0-队列QQ元素的个数。
int Length(PSeqQueue QQ){
    if(QQ == NULL) return 0;
    return QQ->length;
}

// 判断循环队列是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqQueue QQ){
    if(QQ == NULL) return 0;
    if(QQ->length == 0) return 1;
    return 0;
}                   

// 判断循环队列是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqQueue QQ){
    if(QQ == NULL) return 0;
    if(QQ->length == MAXSIZE) return 1;
    return 0;
}

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PSeqQueue QQ, ElemType *ee){
    if(QQ == NULL || ee == NULL) return 0;
    memcpy(ee,QQ->data + QQ->front,sizeof(ElemType));
    return 1;
}