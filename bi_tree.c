#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50
typedef struct BiNode
{
    char data;
    int num;
    struct BiNode *lch, *rch;
} BiNode, *BiTree;
typedef struct arr
{
    char data;
    int num;
} arr;

arr ink[1025]; // 新建结构体数组，储存输出的数据和编号

typedef struct Que // 新建队列
{
    BiTree base[MAX];
    int front;
    int rear;
} Que;
int power(int base, int exponent) // 求2的次方
{
    int result = 1;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}
int Log(int num) // 取2的对数
{
    int i = 0;
    for (; num != 0; i++)
    {
        num = num / 2;
    }
    return i;
}
int search(int a, arr *b) // 在结构体数组中寻找也没有编号为a的节点
{
    for (int i = 0; b[i].num != 0; i++)
    {
        if (a == b[i].num)
        {
            return 1;
        }
    }
    return 0;
}
int Depth(BiTree T) // 求树的深度
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int m = Depth(T->lch);
        int n = Depth(T->rch);
        if (m > n)
        {
            return m + 1;
        }
        else
        {
            return n + 1;
        }
    }
}
Que initQue() // 初始化队列
{
    Que Q;
    Q.rear = Q.front = 0;
    return Q;
}

void inQue(Que *Q, BiTree elem) // 入队
{
    if ((Q->rear + 1) % MAX == Q->front)
    {
        printf("队满\n");
        exit(EXIT_FAILURE);
    }
    Q->base[Q->rear] = elem;
    Q->rear = (Q->rear + 1) % MAX;
}

BiTree outQue(Que *Q) // 出队
{
    if (Q->rear == Q->front)
    {
        printf("队空\n");
        exit(EXIT_FAILURE);
    }
    BiTree elem = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAX;
    return elem;
}

BiTree CreatBiTree(BiTree T) // 先序构造二叉树
{
    char ch;
    scanf("%c", &ch);
    if (ch == '*')
    {
        T = NULL;
    }
    else
    {
        if (!(T = (BiTree)malloc(sizeof(BiNode))))
        {
            exit(EXIT_FAILURE);
        }
        T->data = ch;
        T->lch = CreatBiTree(T->lch);
        T->rch = CreatBiTree(T->rch);
    }
    return T;
}
void DrawBiTree(arr *ink, int dep) // 画出二叉树的结构
{
    for (int i = 0, k = 0; ink[k].num != 0; i++)
    {
        for (int j = 1; 1; j++) // 打印有效行
        {
            if (j != power(2, dep - Log(ink[k].num)) + (ink[k].num - power(2, Log(ink[k].num) - 1)) * power(2, dep - Log(ink[k].num) + 1))
            {
                printf(" ");
            }
            else
            {
                printf("%c", ink[k].data);
                k++;
                if (Log(ink[k - 1].num) != Log(ink[k].num) || ink[k].num == 0)
                {
                    break;
                }
            }
        }
        printf("\n");
        if (ink[k].num == 0)
        {
            break;
        }
        for (int n = 1; n <= power(2, dep - Log(ink[k].num)); n++) // 打印无关部分
        {
            int m = power(2, Log(ink[k].num) - 2);
            for (int j = 1; m <= power(2, Log(ink[k].num) - 1) - 1; m++)
            {
                if (search(m, ink))
                {
                    if (search(2 * m, ink)) // 是否有左子树
                    {
                        for (; 1; j++)
                        {
                            if (j == power(2, dep - Log(m)) + (m - power(2, Log(m) - 1)) * power(2, dep - Log(m) + 1) - n)
                            {
                                printf("/");
                                j++;
                                break;
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                    }
                    if (search(2 * m + 1, ink)) // 是否有右子树
                    {
                        for (; 1; j++)
                        {
                            if (j == power(2, dep - Log(m)) + (m - power(2, Log(m) - 1)) * power(2, dep - Log(m) + 1) + n)
                            {
                                printf("\\");
                                j++;
                                break;
                            }
                            else
                            {
                                printf(" ");
                            }
                        }
                    }
                }
            }
            printf("\n");
        }
    }
}
void printBiTree(BiTree T, arr *ink) // 将二叉树打印到结构体数组中
{
    if (T == NULL)
    {
        printf("树为空\n");
        return;
    }
    T->num = 1;
    Que Q = initQue();
    inQue(&Q, T);
    int k = 0;
    for (int i = 1; Q.rear != Q.front; k++)
    {
        BiTree p = outQue(&Q);
        // printf("%c %d ", p->data, p->num);
        ink[k].data = p->data;
        ink[k].num = p->num;
        if (p->lch != NULL)
        {
            p->lch->num = p->num * 2;
            inQue(&Q, p->lch);
        }
        if (p->rch != NULL)
        {
            p->rch->num = p->num * 2 + 1;
            inQue(&Q, p->rch);
        }
    }
    ink[k].num = 0;
}

int main()
{
    printf("请输入二叉树的先序序列（以 * 表示空节点）:\n");

    BiTree tree = CreatBiTree(tree);
    int dep = Depth(tree);
    printf("二叉树的结构图为：\n");
    printBiTree(tree, ink);
    DrawBiTree(ink, dep);
    return 0;
}
