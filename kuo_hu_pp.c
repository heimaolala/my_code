#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct Stack
{
    char *top;
    char *base;
    int stacksize;
} Stack;
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
int main()
{
    Stack num, str, comb;
    char inp[100], mid, l_par = '(';
    scanf("%s", inp);
    num = initStack(num); // 初始化栈
    str = initStack(str);
    comb = initStack(comb);

    for (int i = 0; inp[i] != '\0'; i++) // 读取数组
    {
        if (inp[i] != ')') // 未识别出右括号，开始装填
        {
            if (inp[i] >= '0' && inp[i] <= '9') // 填入数字栈
            {
                num = Push(num, inp[i]);
            }
            else // 填入字符栈
            {
                str = Push(str, inp[i]);
            }
        }
        if (inp[i] == ')') // 识别出右括号，开始组装
        {
            comb = Push(comb, inp[i]); // 先把右括号压入组装栈中
            num = Pop(num, &mid);      // 从数子栈中取出一个元素
            if (mid == ')')            // 如果拿出的数字是括号,即存在组合式
            {
                comb = Push(comb, mid);
                for (int r_par = 1; r_par != 0;)
                {
                    num = Pop(num, &mid);
                    if (mid == ')')
                    {
                        r_par++;
                    }
                    if (mid == '(')
                    {
                        r_par--;
                    }
                    comb = Push(comb, mid);
                }
                str = Pop(str, &mid);
                comb = Push(comb, mid);
                // 取出符号
                num = Pop(num, &mid);
                if (mid == ')') // 判断下一个数字是不是组合式
                {
                    comb = Push(comb, mid);
                    for (int r_par = 1; r_par != 0;)
                    {
                        num = Pop(num, &mid);
                        if (mid == ')')
                        {
                            r_par++;
                        }
                        if (mid == '(')
                        {
                            r_par--;
                        }
                        comb = Push(comb, mid);
                    }
                }
                else
                {
                    comb = Push(comb, mid);
                }
                comb = Push(comb, l_par); // 压入左括号，完成组装
                // 组装完成
                while (comb.top != comb.base)
                {
                    comb = Pop(comb, &mid);
                    num = Push(num, mid);
                } // 回填
            }
            else // 如果不是组合式
            {
                comb = Push(comb, mid);
                // 取出数字，压入组装
                str = Pop(str, &mid);
                comb = Push(comb, mid);
                // 取出计算符，压入组装
                num = Pop(num, &mid);
                if (mid == ')') // 判断下一个数字是不是组合式
                {
                    comb = Push(comb, mid);
                    for (int r_par = 1; r_par != 0;)
                    {
                        num = Pop(num, &mid);
                        if (mid == ')')
                        {
                            r_par++;
                        }
                        if (mid == '(')
                        {
                            r_par--;
                        }
                        comb = Push(comb, mid);
                    }
                }
                else
                {
                    comb = Push(comb, mid);
                }
                // 取出数字，压入组装
                comb = Push(comb, l_par);
                // 压入左括号，完成组装
                while (comb.top != comb.base)
                {
                    comb = Pop(comb, &mid);
                    num = Push(num, mid);
                } // 回填
            }
        }
    }
    while (num.top != num.base) // 对num栈中的结果逆置
    {
        num = Pop(num, &mid);
        comb = Push(comb, mid);
    }
    while (comb.top != comb.base) // 输出
    {
        comb = Pop(comb, &mid);
        printf("%c", mid);
    }
    printf("\n");
    return 0;
}