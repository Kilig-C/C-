#include<stdio.h>
#include<stdlib.h>
/*
ADT 图（Graph）

Data

定点的有穷非空集合和边的集合。

Operation

CreateGraph(*G,V,VR)：按照顶点集 V 和边弧集 VR 的定义构造图 G。

DestoryGraph(*G)：图 G 存在则销毁。

LocateVex(G,v)：若图 G 中存在顶点 u ，则返回图中的位置。

GetVex(G,v)：返回图 G 中顶点 v 的值。

PutVex(G, v, value)：返回图 G 中顶点 v 赋值 value 。

FirstAdjVex(G,*v)：返回顶点 v 的一个邻接顶点，
若顶点在 G 中无邻接顶点返回空。

NextAdjVex(G,v,*w)：返回顶点 v 相对于顶点 w 的下一个邻接顶点，
若 w 是 v 的最后一个邻接点则返回“空”。

InsertVex(*G,v)：在图 G 中增添新顶点 v 。

DeleteVex(*G,v)：删除图 G 中顶点 v 及其相关的弧。

InsertArc(*G,v,w)：在图 G 中增添 <v,w> ，若 G 是无向图，
还需要增添对称弧 <w,v> 。

DeleteArc(*G,v,w)：在图 G 中删除 <v,w> ，若 G 是无向图，
则还删除对称弧 <w,v> 。

DFSTraverse(G)：对图 G 中进行深度优先遍历，在遍历过程对每个顶点调用。

HFSTraverse(G)：对图 G 中进行广度优先遍历，在遍历过程对每个顶点调用。

endADT
*/

typedef char VertexType;	/*顶点类型应由用户定义*/
typedef int EdgeType;		/*边上的权值类型应由用户定义*/
#define MAXVEX 100			/*最大顶点数，应由用户定义*/
#define INFINITY 65535		/*用65535来代表∞ */
typedef struct
{
	VertexType vexs[MAXVEX];		/*顶点表*/
	EdgeType arc[MAXVEX][MAXVEX];	/*邻接矩阵，可看作边表*/
	int numVertexes, numEdges;		/*图中当前的顶点数和边数*/
}MGraph;

/* 建立无向网图的邻接矩阵表示 */
void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("输入顶点树数和边数：\n");
	scanf("%d, %d", &G->numVertexes, &G->numEdges);/*输入顶点数和边数 */
	for (i = 0; i < G->numVertexes; i++) /* 读入顶点信息，建立顶点表 */
	{
		scanf(&G->vexs[i]);
	}
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY; /* 邻接矩阵初始化 */
		}
	}
	for (k = 0; k < G->numEdges; k++) /*读入 numEdges 条边，建立邻接矩阵 */
	{
		printf("输入边（vi,vj )上的下标i,下标j和权w：\n");
		scanf("%d，*d, %d", &i, &j, &w); /* 输入边（vi,vj)上的权w */
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j]; /* 因为是无向图，矩阵对称 */
	}
}

typedef char VertexType;	/*顶点类型应由用户定义*/
typedef int EdgeType;		/*边上的权值类型应由用户定义*/
#define MAXVEX 100			/*最大顶点数，应由用户定义*/

typedef struct EdgeNode		/* 边表结点 */
{
	int adjvex;				/*邻接点域，存储该顶点对应的下标*/
	EdgeType weight;		/*用于存储权值，对于非网图可以不需要*/
	struct EdgeNode *next;	/*链域，指向下一个邻接点*/
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
	VertexType data;		/*顶点域，存储顶点信息*/
	EdgeNode *firstedge;	/*边表头指针*/
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /*图中当前顶点数和边数*/
}GraphAdjList;

/*建立图的邻接表结构*/
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);	/* 输入顶点数和边数 */
	for (i = 0; i < G->numVertexes; i++)	/*读入顶点信息，建立顶点表 */
	{
		scanf(&G->adjList[i].data);			/*输入顶点信息 */
		G->adjList[i].firstedge = NULL;		/*将边表置为空表*/
	}
	for (k = 0; k < G->numEdges; k++)	/* 建立边表 */
	{
		printf("输入边（vi, vj)上的顶点序号：\n");
		scanf("%d,%d", &i, &j);		/* 输入边（Vi,Vj)上的顶点序号 */
		/*下列代码应用了头插法---------*/
		e = (EdgeNode *)malloc(sizeof (EdgeNode));	/*向内存申请空间，生成边表结点*/
		e->adjvex = j;	/* 邻接序号为 j */
		e->next = G->adjList[i].firstedge;	/*将 e 指针指向当前顶点指向的结点*/
		G->adjList[i].firstedge = e; /* 将当前顶点的指针指向 e */
		e = (EdgeNode *)malloc(sizeof (EdgeNode)); /*向内存申请空间，生成边表结点*/
		e->adjvex = i;	/* 邻接序号为 i */
		e->next = G->adjList[j].firstedge;/*将 e 指针指向当前顶点指向的结点*/
		G->adjList[j].firstedge = e; /*将当前顶点的指针指向 e */
		/*------------------*/
	}
}

//邻接矩阵
#define MAX 100
#define TRUE  1
#define FALSE 0
typedef int Boolean;	/* Boolean 是布尔类型，其值是 TRUE 或 FALSE */
Boolean visited[MAX];	/* 访问标志的数组 */
/* 邻接矩阵的深度优先递归算法 */
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", G.vexs[i]); /* 打印頂点，也可以其他操作 */
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])
		{
			DFS(G, j);	/*对为访问的邻接顶点递归调用*/
		}
	}

}
/*邻接矩阵的深度遍历操作*/
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
	{
		visited[i] = FALSE;	/*初始所有顶点状态都是未访问过状态*/
	}
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i]) /* 对未访问过的顶点调用 DFS , 若是连通图，只会执行一次*/
		{
			DFS(G, i);
		}
	}

}


/*邻接表的深度优先递归算法*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
	visited[i] = TRUE;
	printf("％c ", GL.adjList[i].data); /* 打印顶点，也可以其他操作 */
	p = GL.adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(GL, p->adjvex); /*对为访问的邻接頂点递归调用*/
		}
		p = p->next;
	}
}
/* 邻接表的深度遍历操作 */
void DFSTraverse(GraphAdjList GL)
{
	int i;
	for (i = 0; i < GL.numVertexes; i++)
	{
		visited[i] = FALSE; /*初始所有顶点狀态都是未访问过狀态*/
	}
	for (i = 0; i < GL.numVertexes; i++)
	{
		if (!visited[i]) /*对未访问过的顶点调用DFS,若是连通图，只会执行一次*/
		{
			DFS(GL, i);
		}
	}
}

/*邻接矩阵的广度遍历算法*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexes; i++)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);	/*初始化一辅助用的队列*/
	for (i = 0; i < G.numVertexes; i++)	/* 对每一个顶点做循环 */
	{
		if (!visited[i])	/*若是未访问过就处理*/
		{
			visited[i] = TRUE;	/*设置当前顶点访问过*/
			printf("%c ", G.vexs[i]); /*打印顶点，也可以其他操作*/
			EnQueue(&Q, i);	/*将此顶点入队列*/
			while (!QueueEmpty(Q))/* 若当前队列不为空 */
			{
				DeQueue(&Q, &i);	/*将队中元素出队列，赋值给 i */
				for (j = 0; j < G.numVertexes; j++)
				{
					/*判断其他顶点若与当前顶点存在边且未访问过*/
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE; /*将找到的此顶点标记为已访问*/
						printf("%c ", G.vexs[j]);	/* 打印頂点*/
						EnQueue(&Q, j);	/*将找到的此顶点入队列*/
					}
				}
			}
		}
	}
}

/* 邻接表的广度遍历算法 */
void BFSTraverse(GraphAdjList *GL)
{
	int i;
	EdgeNode *p;
	Queue Q;
	for (i = 0; i < GL->numVertexes; i++)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("nc ", GL->adjList[i].data); /* 打印顶点，也可以其他操作 */
			EnQueue(&Q, i);
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = GL->adjList[i].firstedge;/* 找到当前顶点边表链表头指针 */
				while (p)
				{
					if (!visited[p->adjvex])	/* 若此顶点未被访问 */
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", GL->adjList[p->adjvex].data);
						EnQueue(&Q, p->adjvex); /* 将此顶点入队列 */
					}
					p = p->next;	/* 指针指向下一个邻接点 */
				}
			}
		}
	}
}

/* Prim 算法生成最小生成树 */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];	/*保存相关顶点下标*/
	int lowcost[MAXVEX]; /*保存相关顶点间边的权值*/
	lowcost[0] = 0;	/*初始化第一个权值为 0 ,即 v0 加入生成树*/
	/* lowcost 的值为 0 , 在这里就是此下标的顶点已经加入生成树 */
	adjvex[0] = 0;	/* 初始化第一个顶点下标为 0 */
	for (i = 1; i < G.numVertexes; i++) /* 循环除下标为 0 外的全部顶点 */
	{
		lowcost[i] = G.arc[0][i];/*将 v0 顶点与之有边的权值存入数组 */
		adjvex[i] = 0;	/* 初始化都为 v0 的下标 */ 
	}
	for (i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY; /* 初始化最小权值为 ∞ , */
		/* 通常设置为不可能的大数字如 32767、65535 等 */
		j = l; k = 0;
		while (j < G.numVertexes)	/* 循环全部顶点 */
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				/* 如果权值不为0且权值小于min */
				min = lowcost[j];
				/* 则让当前权值成为最小值*/
				k = j;	/*将当前最小值的下标存入k */
			}
			j++;
		}
		printf(" (%d,*d) ", adjvex[k], k);/*打印当前顶点边中权值最小边*/
		lowcost[k] = 0;/*将当前顶点的权值设置为 0 ,表示此顶点已经完成任务*/
		for (j = 1; j < G.numVertexes; j++) /* 循环所有顶点 */
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				/*若下标为 k 顶点各边权值小于此前这些顶点未被加入生成树权值*/
				lowcost[j] = G.arc[k][j]; /* 将较小权值存入 lowcost */
				adjvex[j] = k;	/* 将下标为 k 的顶点存入adjvex */
			}
		}
	}
}


//克鲁斯卡算法

/* 对边集数组Edge结构的定义 */
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;