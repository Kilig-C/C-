#include<stdio.h>

typedef int VertexType;	//顶点的类型
typedef int EdgeType;	//边的权值类型
#define MaxVex 100 //定义最大定点数
#define Infinity (~(1<<(sizeof(int)*8-1)))
/*
表示1左移4*8-1位 然后取反,
int（int为四字节时，int在有的电脑上不是四字节）的最大值，
当两点之间不邻接时，将两点之间的权值设为int的最大值，
在输出时，用“∞”表示。
*/

//邻接矩阵定义
typedef struct
{
	VertexType Vexs[MaxVex];	//顶点数组，顶点表
	EdgeType   Edge[MaxVex][MaxVex]; //边的权值信息数组，边表
	int numV;	//当前的顶点数
	int numE;	//当前的边数
}MGraph;

//创建无向图的邻接矩阵
void CreateMGraph(MGraph *G)
{
	int vi, vj, e;//vi,vj用来存储顶点，
	printf("请输入图的顶点数和边数(顶点数 边数)：");
	scanf("%d %d", &G->numV, &G->numE);//顶点个数与边数的输入
	for (int i = 0; i < G->numV; i++)//矩阵的初始化
	{
		for (int j = 0; j < G->numV; j++)
		{
			if (i == j)
			{
				G->Edge[i][j] = 0;//将顶点与自身的权值初始化为0
			}
			else
			{
				G->Edge[i][j] = Infinity;//将顶点与其他顶点的权值初始化为Infinity
			}
		}
	}
	for (int i = 0; i < G->numV; i++)//将顶点信息按照输入顺序存入到顶点数组中
	{
		printf("请输入第%d个顶点的值：", i + 1);
		scanf("%d", &G->Vexs[i]);
	}
	printf("\n");

	for (int k = 0; k < G->numE; ++k)
	{
		int i, j;
		printf("请输入边的信息（顶点 顶点 权值）:");
		scanf("%d%d%d", &vi, &vj, &e);
		/*
		若为不带权值的图，输入时e输入1，
		若为带权值的图，则e输入对应的权值
		*/
		for (i = 0; i < G->numV; i++)
		{
			if (G->Vexs[i] == vi)
			{
				break;//找出顶点的在数组中的位置
			}
		}
		for (j = 0; j < G->numV; j++)
		{
			if (G->Vexs[j] == vj)
			{
				break;//找出顶点的在数组中的位置
			}
		}
		G->Edge[i][j] = e;
		G->Edge[j][i] = e;
		//无向图的邻接矩阵具有对称性，也就是两点边的权值是一样的
		//有向图不具备此性质，只需要执行第一步，第二步不需要执行
	}
}

//输出无向图的邻接矩阵
void ShowpGraph(MGraph G)
{
	printf("\n邻接矩阵为：\n");
	printf("\t");
	for (int i = 0; i < G.numV; ++i)
	{
		printf("%6d", G.Vexs[i]);
		//显示每个顶点的值
	}
	printf("\n");
	for (int i = 0; i < G.numV; ++i)
	{
		printf("\n%8d", G.Vexs[i]);
		for (int j = 0; j < G.numV; ++j)
		{
			if (G.Edge[i][j] == Infinity)
			{
				//两点之间无连接时输出“∞”
				printf("%6s", "∞");
			}
			else
			{
				//两点之间有连接时，输出边的权值
				printf("%6d", G.Edge[i][j]);
			}
		}
		printf("\n");
	}
}

int main()
{
	MGraph G;
	CreateMGraph(&G);//创建无向图的邻接矩阵
	ShowpGraph(G);//输出无向图的邻接矩阵
	return 0;
}