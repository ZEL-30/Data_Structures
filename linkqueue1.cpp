/*
 * 程序名：linkqueue1.cpp，此程序演示队列的链表实现（带头结点）。
 * 作者：ZEL 日期：20220505
*/

#include "include.h"

typedef int ElemType;

typedef struct LNode{
    ElemType    data;
    LNode*      next;
};

typedef struct{
    LNode*      front;
    LNode*      rear;
}LinkQueue,*PLinkQueue;

// 队列QQ的初始化操作。
int InitQueue(PLinkQueue QQ);                     

// 销毁队列QQ。
void DestroyQueue(PLinkQueue QQ);

// 清空队列。
void Clear(PLinkQueue QQ);                    

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PLinkQueue QQ, ElemType *ee);

// 打印队列中全部的元素。
void PrintQueue(PLinkQueue QQ);                    

// 求队列的长度，返回值：>=0-队列QQ元素的个数。
int  Length(PLinkQueue QQ);                   

// 判断队列是否已满，链式队列不存在队满的说法。
int IsFull(PLinkQueue QQ);

// 判断队列是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PLinkQueue QQ);                    

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PLinkQueue QQ, ElemType *ee);

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PLinkQueue QQ, ElemType *ee);


int main(){

    LinkQueue QQ;     // 创建队列。

    memset(&QQ,0,sizeof(LinkQueue));

    InitQueue(&QQ);  // 初始化队列。

    ElemType ee;     // 创建一个数据元素。

    printf("元素（1、2、3、4、5、6、7、8、9、10）入队。\n");
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

    Clear(&QQ);
    printf("元素（41、42、43、44、45）入队。\n");
    ee=41;  InQueue(&QQ, &ee);
    ee=42;  InQueue(&QQ, &ee);
    ee=43;  InQueue(&QQ, &ee);
    ee=44;  InQueue(&QQ, &ee);
    ee=45;  InQueue(&QQ, &ee);

    printf("队列的长度是%d\n",Length(&QQ));

    PrintQueue(&QQ);

    DestroyQueue(&QQ); // 销毁队列QQ。

    return 0;

}

// 队列QQ的初始化操作。
int InitQueue(PLinkQueue QQ){
    if(QQ == NULL) return 0;
    LNode* head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    QQ->front = QQ->rear = head;
    return 1;
}                     

// 销毁队列QQ。
void DestroyQueue(PLinkQueue QQ){
    if(QQ == NULL) return;
    LNode* cur = QQ->front;
    LNode* tmp;
    while(cur != NULL){
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    QQ->front=QQ->rear=NULL;  // 防止野指针。
}

// 清空队列。
void Clear(PLinkQueue QQ){
    if(QQ == NULL) return;
    LNode* cur = QQ->front->next;
    LNode* tmp;
    while(cur != NULL){
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    QQ->rear = QQ->front;
    QQ->front->next = NULL;
}  

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PLinkQueue QQ, ElemType *ee){
    if(QQ == NULL || ee == NULL) return 0;
    LNode* newnode = (LNode*)malloc(sizeof(LNode));
    memcpy(&newnode->data,ee,sizeof(ElemType));
    newnode->next = QQ->rear->next;
    QQ->rear->next = newnode;
    QQ->rear = QQ->rear->next;
    return 1;
}

// 打印队列中全部的元素。
void PrintQueue(PLinkQueue QQ){
    if(QQ == NULL) return;
    LNode* cur = QQ->front->next;
    while(cur != NULL){
        cout << cur->data << " ";
        cur  = cur->next;
    }
    cout << endl;
}                   

// 求队列的长度，返回值：>=0-队列QQ元素的个数。
int  Length(PLinkQueue QQ){
    if(QQ == NULL) return 0;
    LNode* cur = QQ->front->next;
    int len = 0;
    while(cur != NULL){
        len++;
        cur  = cur->next;
    }
    return len;
}                   

// 判断队列是否已满，链式队列不存在队满的说法。
int IsFull(PLinkQueue QQ){
    if(QQ == NULL) return 0;
    return 1;
}

// 判断队列是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PLinkQueue QQ){
    if(QQ == NULL) return 0;
    if(QQ->front->next = NULL) return 1;
    return 0;
}     

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PLinkQueue QQ, ElemType *ee){
    if(QQ == NULL || ee == NULL) return 0;
    LNode* tmp = QQ->front->next;
    memcpy(ee,&tmp->data,sizeof(ElemType));
    QQ->front->next = QQ->front->next->next;
    free(tmp); tmp = NULL;
    return 1;
}

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PLinkQueue QQ, ElemType *ee){
    if(QQ == NULL || ee == NULL) return 0;
    memcpy(ee,&QQ->front->next->data,sizeof(ElemType));
    return 1;
}