#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 50
typedef struct Stack
{
    char *top;
    char *base;
    int stacksize;
} Stack;

typedef struct Que
{
    char *base;
    int front; // 头指针
    int rear;  // 尾指针
} Que;

bool isSpChar(char c)
{
    // 判断字符是否为特殊字符
    return !(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
}

void re_SpChars(char *str) // 删除特殊字符
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (!isSpChar(str[i]))
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '#';      // 在字符串末尾添加 #
    str[j + 1] = '\0'; // 添加字符串结束标记
}

Que initQue(Que Q) // 初始化队列
{
    Q.base = (char *)malloc(sizeof(char) * MAX);
    if (!Q.base)
    {
        printf("队列分配内存失败\n");
        exit(EXIT_FAILURE);
    }
    Q.rear = Q.front = 0;
    return Q;
}

Que inQue(Que Q, char elem) // 入队
{
    if ((Q.rear + 1) % MAX == Q.front)
    {
        printf("队满\n");
        exit(EXIT_FAILURE);
    }
    Q.base[Q.rear] = elem;
    Q.rear = (Q.rear + 1) % MAX;
    return Q;
}
Que outQue(Que Q, char *elem) // 出队
{
    if (Q.rear == Q.front)
    {
        printf("队空\n");
        exit(EXIT_FAILURE);
    }
    *elem = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX;
    return Q;
}
Stack initStack(Stack S) // 初始化栈
{
    S.base = (char *)malloc(sizeof(char) * MAX);
    if (!S.base)
    {
        printf("栈分配内存失败\n");
        exit(EXIT_FAILURE);
    }
    S.top = S.base;
    S.stacksize = MAX;
    return S;
}
Stack Push(Stack S, char elem) // 压栈
{
    if (S.top - S.base == S.stacksize)
    {
        printf("栈满！\n");
        exit(EXIT_FAILURE);
    }
    *(S.top) = elem;
    S.top++;
    return S;
}
Stack Pop(Stack S, char *elem) // 弹栈
{
    if (S.top == S.base)
    {
        printf("栈空！\n");
        exit(EXIT_FAILURE);
    }
    S.top--;
    *elem = *(S.top);
    return S;
}
int Judge(Stack S, Que Q, int *length) // 判断是否为回文数
{
    char st_num, Qu_num;
    for (int i = 0; i < *length / 2; i++)
    {
        S = Pop(S, &st_num);
        Q = outQue(Q, &Qu_num);
        st_num = tolower(st_num);
        Qu_num = tolower(Qu_num);
        if (st_num != Qu_num)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    Stack S_str;
    Que Q_str;
    Q_str = initQue(Q_str);
    S_str = initStack(S_str);
    char inp[MAX] = {0};
    int length = 0, eql = 0;
    scanf("%[^\n]", inp); // 接受除回车外的所有字符
    re_SpChars(inp);
    length = strlen(inp) - 1; // 除去#号
    for (int i = 0; inp[i] != '\0'; i++)
    {
        if (inp[i] == '#')
        {
            break; // 当遇到 # 字符时退出循环
        }
        S_str = Push(S_str, inp[i]);
    }
    for (int i = 0; inp[i] != '\0'; i++)
    {
        if (inp[i] == '#')
        {
            break; // 当遇到 # 字符时退出循环
        }
        Q_str = inQue(Q_str, inp[i]);
    }
    if (Judge(S_str, Q_str, &length))
    {
        printf("是回文数！\n");
    }
    else
    {
        printf("不是回文数！\n");
    }
    free(Q_str.base); // 释放堆空间
    free(S_str.base);
    return 0;
}