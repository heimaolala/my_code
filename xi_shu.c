#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Tri // 定义三元组
{
    int row; // 行
    int col; // 列
    int num; // 数
} Tri;

bool check_out(int row, int col, int i, Tri *Triple)
{
    return (Triple[i].row > row || Triple[i].col > col);
}

int check_same(int i, Tri *Triple)
{
    for (int k = 1; k < i; k++)
    {
        if (Triple[i].row == Triple[i - k].row && Triple[i].col == Triple[i - k].col)
        {
            return i - k;
        }
    }
    return 0;
}

void InitTri(int row, int col, int num, Tri *Triple)
{
    Triple[0].row = row;
    Triple[0].col = col;
    Triple[0].num = num;
    for (int i = 1; i <= num; i++)
    {
        printf("输入第 %d/%d 个数\n", i, num);
        printf("行 列 值\n");
        scanf("%d%d%d", &Triple[i].row, &Triple[i].col, &Triple[i].num);
        while (check_same(i, Triple) || check_out(row, col, i, Triple) || Triple[i].num == 0)
        {
            Triple[i].row = 0;
            Triple[i].col = 0;
            Triple[i].num = 0;
            printf("输入有 重复 “0” 或者 超出矩阵限制 ！请重新输入\n");
            printf("输入第 %d/%d 个数\n", i, num);
            printf("行 列 值\n");
            scanf("%d%d%d", &Triple[i].row, &Triple[i].col, &Triple[i].num);
        }
    }
    printf("稀疏矩阵三元表录入完毕！\n");
}

void Tri_add(Tri *Tri_A, Tri *Tri_B, Tri *Tri_C)
{
    int c = 1;
    for (int i = 1; i <= Tri_A[0].num; i++)
    {
        for (int j = 1; j <= Tri_B[0].num; j++)
        {
            if (Tri_A[i].col == Tri_B[j].col && Tri_A[i].row == Tri_B[j].row && Tri_B[j].num != 0)
            {
                Tri_C[c].row = Tri_A[i].row;
                Tri_C[c].col = Tri_A[i].col;
                Tri_C[c].num = Tri_A[i].num + Tri_B[j].num;
                if (Tri_C[c].num != 0)
                {
                    c++;
                }
                Tri_B[j].num = 0;
                break;
            }
        }
        if (c == i && Tri_C[c].num != 0)
        {
            Tri_C[c].row = Tri_A[i].row;
            Tri_C[c].col = Tri_A[i].col;
            Tri_C[c].num = Tri_A[i].num;
            c++;
        }
    }
    for (int i = 1; i <= Tri_B[0].num; i++)
    {
        if (Tri_B[i].num != 0)
        {
            Tri_C[c].row = Tri_B[i].row;
            Tri_C[c].col = Tri_B[i].col;
            Tri_C[c].num = Tri_B[i].num;
            c++;
        }
    }
    Tri_C[0].num = c - 1;
}

void Tri_pro(Tri *Tri_A, Tri *Tri_B, Tri *Tri_C)
{
    int c = 1;
    for (int i = 1; i <= Tri_A[0].num; i++)
    {
        for (int j = 1; j <= Tri_B[0].num; j++)
        {
            if (Tri_A[i].col == Tri_B[j].row)
            {
                Tri_C[c].row = Tri_A[i].row;
                Tri_C[c].col = Tri_B[j].col;
                if (check_same(c, Tri_C))
                {
                    int t = check_same(c, Tri_C);
                    Tri_C[t].num = Tri_C[t].num + Tri_A[i].num * Tri_B[j].num;
                }
                else
                {
                    Tri_C[c].num = Tri_A[i].num * Tri_B[j].num;
                    c++;
                }
            }
        }
    }
    Tri_C[0].num = c - 1;
}

void PrintTri(Tri *Triple)
{
    int numElements = Triple[0].num;
    printf("行 列 值\n");
    for (int k = 0; k <= numElements; k++)
    {
        printf("%d  %d  %d\n", Triple[k].row, Triple[k].col, Triple[k].num);
    }
}
int main()
{
    int row, col, num;
    printf("输入稀疏矩阵A的\n行数 列数 以及 非零元个数\n");
    scanf("%d%d%d", &row, &col, &num);
    Tri Tri_A[num + 1];
    InitTri(row, col, num, Tri_A);
    // PrintTri(Tri_A);

    printf("输入稀疏矩阵B的\n行数 列数 以及 非零元个数\n");
    scanf("%d%d%d", &row, &col, &num);
    Tri Tri_B[num + 1];
    InitTri(row, col, num, Tri_B);
    // PrintTri(Tri_B);
    printf("\n进行矩阵乘法...\n");
    int C_sp = Tri_A[0].num + Tri_B[0].num;
    Tri Tri_C[C_sp + 1];
    if (Tri_A[0].col == Tri_B[0].row)
    {
        // int C_sp = Tri_A[0].num + Tri_B[0].num;
        // Tri Tri_C[C_sp + 1];
        Tri_C[0].row = Tri_A[0].row;
        Tri_C[0].col = Tri_B[0].col;
        Tri_pro(Tri_A, Tri_B, Tri_C);
        printf("矩阵乘法结果：\n");
        PrintTri(Tri_C);
    }
    else
    {
        printf("\nA矩阵和B矩阵无法相乘\n原因: A的列数不等于B的行数\n");
    }
    printf("\n进行矩阵加法...\n");

    if (Tri_A[0].col == Tri_B[0].col && Tri_A[0].row == Tri_B[0].row)
    {
        Tri_C[0].row = Tri_A[0].row;
        Tri_C[0].col = Tri_A[0].col;
        Tri_add(Tri_A, Tri_B, Tri_C);
        printf("矩阵加法结果：\n");
        PrintTri(Tri_C);
    }
    else
    {
        printf("\nA矩阵和B矩阵无法相加\n原因: 二者维度不同\n");
    }
    return 0;
}