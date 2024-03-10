#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<graphics.h>

#define ROW_MAX 100
#define COL_MAX 100

enum Difficulty
{
    BEGINNER,
    INTERMEDIATE,
    ADVANCED,
    CUSTOM
};

void GameInit(int ROW, int COL, int num, char map[][COL_MAX], char upmap[][COL_MAX]) // 地图初始化
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < ROW + 2; i++) // 初始化游戏区和辅助区
    {
        for (int j = 0; j < COL + 2; j++)
        {
            map[i][j] = '0';
            upmap[i][j] = '0';
        }
    }
    int n = 0;
    while (n < num) // 添加地雷
    {
        int r = rand() % ROW + 1;
        int c = rand() % COL + 1;
        if (map[r][c] != '*')
        {
            map[r][c] = '*';
            n++;
        }
    }
    // 补充数字
    for (int i = 1; i <= ROW; i++) // 遍历雷区
    {
        for (int j = 1; j <= COL; j++)
        {
            upmap[i][j] = '.';
            if (map[i][j] != '*') // 找到非雷区
            {
                for (int m = i - 1; m <= i + 1; m++)
                {
                    for (int n = j - 1; n <= j + 1; n++)
                    {
                        if (map[m][n] == '*')
                        {
                            map[i][j]++; // 打上数字标记
                        }
                    }
                }
            }
        }
    }
}

void PrintMap(int ROW, int COL, char map[][COL_MAX]) // 打印内地图
{
    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 1; j <= COL; j++)
        {
            printf("%c", map[i][j]);
            if (j == COL)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
}

void PrintUpmap(int ROW, int COL, char upmap[][COL_MAX]) // 打印外地图
{
    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 1; j <= COL; j++)
        {
            printf("%c", upmap[i][j]);
            if (j == COL)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
}

void PrintLosemap(int ROW, int COL, char map[][COL_MAX], char upmap[][COL_MAX]) // 打印失败地图
{
    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 1; j <= COL; j++)
        {
            if (map[i][j] == '*')
            {
                upmap[i][j] = map[i][j];
                printf("%c", upmap[i][j]);
            }
            else
            {
                printf("%c", upmap[i][j]);
            }
            if (j == COL)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
}

void OpenZero(int *count, int x, int y, int ROW, int COL, char map[][COL_MAX], char upmap[][COL_MAX], int visited[][COL_MAX]) // 0的爆炸展开
{
    if (visited[x][y] == 1 || (upmap[x][y] != '.' && upmap[x][y] != '?')) // 已经展开过的格子或非展开状态的格子，不进行递归展开
    {
        return;
    }
    visited[x][y] = 1;
    upmap[x][y] = map[x][y];
    (*count)++;

    if (map[x][y] == '0')
    {
        for (int m = x - 1; m <= x + 1; m++)
        {
            for (int n = y - 1; n <= y + 1; n++)
            {
                if (m >= 1 && m <= ROW && n >= 1 && n <= COL)
                {
                    OpenZero(count, m, n, ROW, COL, map, upmap, visited);
                }
            }
        }
    }
}

void DouClick(int *count, int x, int y, int ROW, int COL, char map[][COL_MAX], char upmap[][COL_MAX]) // 实现双击操作
{
    int k = 0;
    for (int m = x - 1; m <= x + 1; m++)
    {
        for (int n = y - 1; n <= y + 1; n++)
        {
            if (m >= 1 && m <= ROW && n >= 1 && n <= COL)
            {
                if (map[m][n] == '*' && upmap[m][n] == '!') // 判断雷是否被标记
                {
                    k++;
                }
                else if (map[m][n] != '*' && upmap[m][n] == '!')
                {
                    upmap[0][0] = '@';
                    k += 20;
                    break;
                }
            }
        }
    }
    if (map[x][y] == k + 48) // 符合双击打开的情况
    {
        for (int m = x - 1; m <= x + 1; m++)
        {
            for (int n = y - 1; n <= y + 1; n++)
            {
                if (m >= 1 && m <= ROW && n >= 1 && n <= COL)
                {
                    if (map[m][n] >= '0' && map[m][n] <= '8' && (upmap[m][n] == '.' || upmap[m][n] == '?'))
                    {
                        if (map[m][n] == '0')
                        {
                            int visited[ROW_MAX][COL_MAX] = {0};
                            OpenZero(count, m, n, ROW, COL, map, upmap, visited);
                        }
                        else
                        {
                            upmap[m][n] = map[m][n];
                            (*count)++;
                        }
                    }
                }
            }
        }
    }
}

void PlayGame(int *count, int *step, int *mineCount, int ROW, int COL, char map[][COL_MAX], char upmap[][COL_MAX])
{
    int x, y, kind; // 横坐标，纵坐标，操作种类 1.左键 2.右标雷 3.右标问 4.右取消 9.双击
    scanf("%d%d%d", &kind, &x, &y);
    if (!(x >= 1 && x <= ROW && y >= 1 && y <= COL))
    {
        kind = 0;
    }
    *step += 1;
    switch (kind)
    {
    case 1: // 左键
    {
        if (map[x][y] >= '0' && map[x][y] <= '8' && (upmap[x][y] == '.' || upmap[x][y] == '?') && upmap[x][y] != '!')
        {
            if (map[x][y] == '0') // 点到0
            {
                int visited[ROW_MAX][COL_MAX] = {0};
                OpenZero(count, x, y, ROW, COL, map, upmap, visited);
            }
            else
            {
                upmap[x][y] = map[x][y];
                (*count)++;
            }
        }
        else if (map[x][y] == '*' && upmap[x][y] != '!') // 点到雷
        {
            upmap[0][0] = '@';
        }
        break;
    }
    case 2: // 右标雷
    {
        if (upmap[x][y] != '!')
        {
            *mineCount -= 1;
        }
        upmap[x][y] = '!';
        break;
    }
    case 3: // 右标问
    {
        if (upmap[x][y] == '!')
        {
            *mineCount += 1;
        }
        upmap[x][y] = '?';
        break;
    }
    case 4: // 右取消
    {
        if (upmap[x][y] == '!')
        {
            *mineCount += 1;
        }
        upmap[x][y] = '.';
        break;
    }
    case 9: // 双击  待完善
    {
        if(upmap[x][y] >= '1' && upmap[x][y] <= '8')
        {
            DouClick(count, x, y, ROW, COL, map, upmap);
        }
        break;
    }
    default:
    {
    }
    }
}

int main()
{
    int step = 0, count = 0;
    char upmap[ROW_MAX][COL_MAX];
    char map[ROW_MAX][COL_MAX]; // 根据游戏规则，最大为24*30，可以把最大值都设置为100
    int row = 0, col = 0, mineCount = 0;
    enum Difficulty modeSel;

    printf("选择游戏难度(1.初级 2.中级 3.高级 4.自定义)\n");
    scanf("%d", (int *)&modeSel);

    switch (modeSel - 1) // 枚举变量，第一个为0，故要减一
    {
    case BEGINNER:
        row = 9;
        col = 9;
        mineCount = 10;
        break;
    case INTERMEDIATE:
        row = 16;
        col = 16;
        mineCount = 40;
        break;
    case ADVANCED:
        row = 16;
        col = 30;
        mineCount = 99;
        break;
    case CUSTOM:
        while (1)
        {
            printf("输入行数，列数，雷数\n");
            scanf("%d%d%d", &row, &col, &mineCount);
            if (mineCount <= row * col * 0.56)
            {
                break;
            }
            else
            {
                printf("雷数过多，请重新设置（不超过格数的56%%）\n");
                /*
                经过游戏实测，如果雷数大于格数的56%，则会出现无解的情况
                也就是说，输赢并不取决于玩家，而是取决于运气的情况。
                所以我们摒弃了老师提出的，雷数小于90%的要求，注重游戏体验
                */
            }
        }
        break;
    default:
        printf("模式不存在\n");
        return 0;
    }
    int MineCount = mineCount;
    GameInit(row, col, mineCount, map, upmap);
    PrintMap(row, col, map);
    PrintUpmap(row, col, upmap);
    while (1)
    {
        if (step >= 1 && row * col == MineCount + count) // 胜利
        {
            printf("Game over, you win\n");
            printf("%d %d\n", step, mineCount);
            PrintMap(row, col, map); // 打印内地图
            break;
        }
        if (step >= 1 && row * col != MineCount + count && upmap[0][0] != '@') // 继续
        {
            printf("Game in progress\n");
            printf("%d %d\n", step, mineCount);
            PrintMap(row, col, map);
            PrintUpmap(row, col, upmap); // 打印外地图
        }
        if (upmap[0][0] == '@') // 失败
        {
            printf("Hit mine, you lose\n");
            printf("%d %d\n", step, mineCount);
            PrintLosemap(row, col, map, upmap);
            break;
        }
        else
        {
            PlayGame(&count, &step, &mineCount, row, col, map, upmap);
        }
    }
    return 0;
}
