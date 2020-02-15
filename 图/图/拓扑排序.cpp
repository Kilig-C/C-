#define OK 1
#define ERROR 0
/* 拓扑排序，若 GL 无回路，则输出拓扑排序序列并返回 OK ,若有回路返回 ERROR */
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0; /*用于栈指针下标*/
	int count = 0; /*用于统计输出顶点的个数*/
	int *stack; /* 建栈存储入度为 0 的顶点 */
	stack = (int *)malloc(GL->numVertexes * sizeof (int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (GL->adjList[i].in = 0)
		{

			stack[++top] = i;	/* 将入度为 0 的顶点入栈 */
		}
	}
	while (top != 0)
	{
		gettop = stack[top--];	/* 出栈 */
		printf("%d -> ", GL->adjList[gettop].data);	/* 打印此顶点 */
		count++; /* 统计输出顶点数 */
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			/* 对此顶点弧表遍历 */
			k = e->adjvex;
			if (!(--GL->adjList[k].in))/*将 k 号顶点邻接点的入度减 1 */
			{
				stack[++top] = k;	/*若为 0 则入栈，以便于下次循环输出*/
			}
		}
	}
	if (count < GL->numVertexes) /* 如果 count 小于顶点数，说明存在环 */
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}



#include<stdio.h>

#define MAXVEX 9 

typedef struct EdgeNode	/* 边表结点 */
{
	int adjvex;	/* 邻接点域，存你该顶点对应的下标 */
	int weight;	/* 用于存储权值，对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域，指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
	int in;	/* 顶点入度 */
	int data;	/* 顶点域，存储顶点信息 */
	EdgeNode *firstedge;	/*	边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;	/* 图中当前顶点数和边数 */
}graphAdjList, *GraphAdjList;
