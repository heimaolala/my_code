#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// 定义有向图的数据结构，使用邻接表表示
struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int V; // 顶点数
    struct Node **adjList;//数组
};

// 创建一个新节点
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 添加边到有向图
void addEdge(struct Graph *graph, int src, int dest)
{
    // 添加边从src到dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];//置next为NULL，graph->adjList[src]=NULL
    graph->adjList[src] = newNode;
}

// 深度优先搜索（DFS）来计算从顶点v出发可以到达的顶点数量
void DFS(struct Graph *graph, int v, bool visited[])
{
    visited[v] = true;

    struct Node *temp = graph->adjList[v];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// 计算从顶点v出发可以到达的顶点数量
int countrn(struct Graph *graph, int v)
{
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; ++i)
    {
        visited[i] = false;
    }

    int count = 0;
    DFS(graph, v, visited);

    for (int i = 0; i < graph->V; ++i)
    {
        if (visited[i])
        {
            count++;
        }
    }

    free(visited);
    return count;
}

int main()
{
    int V, E;
    printf("请输入顶点数（V）：");
    scanf("%d", &V);
    printf("请输入边数（E）：");
    scanf("%d", &E);
    // 创建有向图
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node **)malloc(V * sizeof(struct Node *));
    for (int i = 0; i < V; i++)
    {
        graph->adjList[i] = NULL;
    }
    // 随机生成有向图的边
    srand(time(0));
    for (int i = 0; i < E; ++i)
    {
        // 生成随机边
        int src = rand() % V;
        int dest = rand() % V;
        // 添加边到有向图
        addEdge(graph, src, dest);
    }
    // 选择一个随机顶点
    int randv = rand() % V;
    // 计算从随机顶点出发可以到达的顶点数量的平均值
    int trn = 0;
    for (int i = 0; i < V; ++i)
    {
        int rn = countrn(graph, i);
        trn += rn;
    }
    double arn = (double)trn / V;
    printf("从一个随机顶点出发可到达的顶点数量的平均值为：%f\n", arn);
    return 0;
}
