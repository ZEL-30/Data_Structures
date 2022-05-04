/*
 * 程序名：seqstack3.cpp，此程序演示用顺序栈检查括号是否匹配，支持()[]{}三种括号。
 * 作者：ZEL 日期：20220505
*/

#include "include.h"

#define MAX 100

typedef char ElemType; 


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

// 检查表达式括号是否匹配，返回值：0-不匹配，1-匹配。
int checkbrackets(char *str);








int main(){

    char str[101];  
    memset(str,0,sizeof(str));

    printf("请输入待检查的字符串：");
    // fgets(str,100,stdin);    // 不建议用gets函数，gets函数编译时可能会出现警号。
    cin >> str;
    // str[strlen(str)-1]=0;    // 删除str最后的换行。
    printf("输入的字符串是=%s=\n",str);

    if (checkbrackets(str) == 0) { printf("匹配失败。\n"); return -1; }

    printf("匹配成功。\n");

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


// 检查表达式括号是否匹配，返回值：0-不匹配，1-匹配。
int checkbrackets(char *str){
    if(str == NULL) return 0;

    PSeqStack ss;
    ElemType ee;
    int status = 0;
    ss = InitStack1();
    int len = strlen(str);
    for(int i = 0;i < len;i++){
        if(*(str+i) == '{' || *(str+i) == '[' || *(str+i) == '('){
            Push(ss,str + i);
        }else if (*(str+i) == '}' || *(str+i) == ']' || *(str+i) == ')'){
            status = 1;
            GetTop(ss,&ee);
            switch(*(str + i)){
            case '}' : ee == '{' ? Pop(ss,&ee) : status = 0;
                break;
            case ')' : ee == '(' ? Pop(ss,&ee) : status = 0;
                break;
            case ']' : ee == '[' ? Pop(ss,&ee) : status = 0;
                break;
            }
            if(status == 0) return 0;
        }else{
            return 0;
        }
    }

    if(IsEmpty(ss) == 1) return 1;
    else return 0;
    return 0;

}