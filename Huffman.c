#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define ARRAY_SIZE 512
#define MAX_FILENAME_LENGTH 100

typedef struct node
{
    int num;
    int weigh;
    int lch;
    int rch;
    int par;
} node; // 结构体数组初始化

int judge(node *arr) // 判断哈夫曼树是否完成
{
    int k = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr[i].par == 0 && arr[i].weigh > 0)
        {
            k++;
        }
    }
    if (k == 1)
    {
        return 0;
    }
    return 1;
}
int find_root(node *arr) // 找哈夫曼树的根
{
    int k = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr[i].par == 0 && arr[i].weigh > 0)
        {
            return i;
        }
    }
}
void countCharacterFrequency(const char *filename, node *arr) // 计算权重
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("打不开文件，或文件不存在\n");
        return;
    }

    int ch; // 接受ASCII值
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch >= 0 && ch <= 255)
        {
            arr[ch].weigh++;
        }
    }

    fclose(file);
}

void findTwoMinIndexes(node *arr, int size, int *index1, int *index2) // 找到最小的两个值
{
    *index1 = *index2 = -1; // 初始化为无效的下标 -1

    for (int i = 0; i < size; ++i)
    {
        if ((arr[i].par == 0 && arr[i].weigh > 0) && (*index1 == -1 || arr[i].weigh < arr[*index1].weigh))
        {
            *index2 = *index1;
            *index1 = i;
        }
        else if ((arr[i].par == 0 && arr[i].weigh > 0) && (*index2 == -1 || arr[i].weigh < arr[*index2].weigh))
        {
            *index2 = i;
        }
    }
}

void CreatHuffman(node *arr) // 建立哈夫曼树
{
    int index1, index2;
    for (int range = 256; judge(arr) && range < ARRAY_SIZE; range++)
    {
        findTwoMinIndexes(arr, range, &index1, &index2);
        arr[range].weigh = arr[index1].weigh + arr[index2].weigh;
        arr[range].lch = arr[index1].num;
        arr[range].rch = arr[index2].num;
        arr[index1].par = range;
        arr[index2].par = range;
    }
}
void encode(const char *filename, const char *ec_filename, node *arr) // 编码
{
    FILE *file = fopen(filename, "r");
    FILE *ec_file = fopen(ec_filename, "w");
    if (file == NULL)
    {
        printf("打不开源文件，或文件不存在\n");
        return;
    }
    if (ec_file == NULL)
    {
        printf("创建文件失败，或无法打开文件\n");
        return;
    }
    int ch, put[8];                   // 接受ASCII值
    while ((ch = fgetc(file)) != EOF) // 读取源文件中的字符
    {
        int k = 0;
        for (; arr[ch].par != 0; k++)
        {
            if (arr[arr[ch].par].lch == ch) // 判断是否是根节点的左子树
            {
                put[k] = 0;
            }
            if (arr[arr[ch].par].rch == ch) // 判断是否是根节点的右子树
            {
                put[k] = 1;
            }
            ch = arr[ch].par;
        }
        k--;
        for (; k >= 0; k--) // 倒序输出
        {
            fprintf(ec_file, "%d", put[k]);
        }
    }
    fclose(file);
    fclose(ec_file);
}
void decode(const char *ec_filename, const char *dc_filename, node *arr) // 译码
{
    FILE *ec_file = fopen(ec_filename, "r");
    FILE *dc_file = fopen(dc_filename, "w");
    if (ec_file == NULL)
    {
        printf("打不开源文件，或文件不存在\n");
        return;
    }
    if (dc_file == NULL)
    {
        printf("创建文件失败，或无法打开文件\n");
        return;
    }
    int ch;
    int root = find_root(arr); // 找到根节点
    int index = root;
    while ((ch = fgetc(ec_file)) != EOF) // 读取文件中的二进制字符串
    {
        if (ch - '0' == 0) // 左子树
        {
            index = arr[index].lch;
        }
        if (ch - '0' == 1) // 右子树
        {
            index = arr[index].rch;
        }
        if (arr[index].lch == 0) // 找到叶子节点
        {
            fprintf(dc_file, "%c", index); // 输出叶子节点
            index = root;                  // 将下标置于根节点
        }
    }
    fclose(dc_file);
    fclose(ec_file);
}

int main()
{
    int change = 0;
    node arr[ARRAY_SIZE];
    char filename[MAX_FILENAME_LENGTH];
    char ec_filename[MAX_FILENAME_LENGTH];
    char dc_filename[MAX_FILENAME_LENGTH];
    for (int i = 0; i < ARRAY_SIZE; i++) // 结构体数组初始化
    {
        arr[i].num = i;
        arr[i].weigh = 0;
        arr[i].lch = 0;
        arr[i].rch = 0;
        arr[i].par = 0;
    }
    printf("输入源文件名 (斜杠用“/”表示): ");
    scanf("%s", filename);
    countCharacterFrequency(filename, arr); // 计算权重
    CreatHuffman(arr);
    while (1)
    {
        printf("选择你的操作：\n");
        printf("(1)编码\t(2)译码\t(3)退出\n");
        scanf("%d", &change);

        if (change == 1) // 开始编码
        {
            printf("输入生成文件名 (斜杠用“/”表示): ");
            scanf("%s", ec_filename);
            encode(filename, ec_filename, arr); // 编码
            printf("编码完成！\n");
        }
        else if (change == 2) // 译码
        {
            printf("输入生成文件名 (斜杠用“/”表示): ");
            scanf("%s", dc_filename);
            decode(ec_filename, dc_filename, arr);
            printf("译码完成！\n");
        }
        else if (change == 3)
        {
            printf("已退出！");
            break;
        }
        else
        {
            printf("无效操作！");
        }
    }
    return 0;
}