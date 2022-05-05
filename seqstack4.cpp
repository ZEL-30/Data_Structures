/*
 * 程序名：seqstack4.cpp，此程序演示用顺序栈实现中缀表达式转后缀表达式。
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

// 把中缀表达式str1转换为后缀表达式str2。
int torpolish(char *str1,char *str2);






int main(){

    char str1[100];
    char str2[100];
    cout << "请输入中缀表达式：" << endl;
    cin >> str1;
    if(torpolish(str1,str2) == 0) cout << "转换失败！" << endl;
    else cout << "后缀表达式：" << str2 <<endl;

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
    if (SS->top == -1) { printf("栈为空。\n"); return 0; }
    memcpy(ee,&SS->data[SS->top],sizeof(ElemType));  // 用数组的下标访问。
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


// 把中缀表达式str1转换为后缀表达式str2。
int torpolish(char *str1,char *str2){
    if(str1 == NULL || str2 == NULL) return 0;
    int ipos1 = 0,ipos2 = 0;
    SeqStack ss;
    ElemType ee;
    InitStack(&ss);

    for(ipos1 = 0;ipos1 < strlen(str1);ipos1++){
        // 1.数字和字母直接追加到后缀表达式后面
        if(*(str1 + ipos1) >= '0' && *(str1 + ipos1) <= '9' || *(str1 + ipos1) >= 'a' && *(str1 + ipos1) <= 'z' || *(str1 + ipos1) >= 'A' && *(str1 + ipos1) <= 'Z'){
            *(str2 + ipos2) = *(str1 + ipos1);
            ipos2++;
            continue;
        }

        // 2.左括号直接入栈
        if(*(str1 + ipos1) == '('){
            Push(&ss,str1 + ipos1);  continue;
        }

        // 3.如果是右括号 ')'，进入循环，依次弹出栈中的运算符并追加到后缀表达式后面，如果弹出的左括号 '('，循环中止。
        if(*(str1 + ipos1) == ')'){
            while(1){
                if(Pop(&ss,&ee) != 1) return 0;
                //cout << ee << endl;
                if(ee == '(') break;
                *(str2 + ipos2) = ee;  ipos2++;
            }
            continue;
        }


        // 4.如果当前字符是运算符 '+'、'-'、'*'、'/'，则进入循环
        if(*(str1 + ipos1) == '+' || *(str1 + ipos1) == '-' || *(str1 + ipos1) == '*' || *(str1 + ipos1) == '/'){
            while(1){
                if(IsEmpty(&ss) != 0) break;
                GetTop(&ss,&ee);
                int pri1 = 0;   // 当前运算符的优先级。
                int pri2 = 0;   // 栈中运算符的优先级。

                if(*(str1 + ipos1) == '+' || *(str1 + ipos1) == '-') pri1 = 1;
                if(*(str1 + ipos1) == '*' || *(str1 + ipos1) == '/') pri1 = 2;
                if(ee == '+' || ee == '-') pri2 = 1;
                if(ee == '*' || ee == '/') pri2 = 2;

                if(pri2 >= pri1){
                    Pop(&ss,&ee);
                    *(str2 + ipos2) = ee;  ipos2++;
                }else if(IsEmpty(&ss) || pri2 < pri1 || *(str1 + ipos1) == '(') break;


                // // 如果当前运算符的优先级 高于 栈中运算符的优先级，停止判断，当前运算符将入栈。
                // if (pri1>pri2) break;  

                // // 把栈中优先级 高于等于 当前运算符的元素依次弹出，追加到后缀表达式后面。
                // Pop(&ss,&ee); str2[ipos2]=ee; ipos2++; continue;
            }
            // 当前运算符入栈。
            Push(&ss,str1 + ipos1);
            continue;
        }
    }

    // 5.扫描完中缀表达式后，弹出栈中剩下的运算符，追加到后缀表达式后面。
    while(!IsEmpty(&ss)){
        Pop(&ss,&ee);
        *(str2 + ipos2) = ee;  ipos2++;
    }
    *(str2 + ipos2) = '\0';
    return 1;

}