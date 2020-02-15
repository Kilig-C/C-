#define MAXVEX 9 
typedef int Pathmatirx[MAXVEX][MAXVEX]; 
typedef int ShortPathTable[MAXVEX][MAXVEX];
/* Floyd 算法，求网图 G 中各顶点 v 到其余顶点点 w 最短路径 P[v][w] 及带权长度 D[v][w] */ 
void ShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D)
{
	int v, w, k;
	for (v = 0; v < G.numVertexes; ++v)	/* 初始化 D 与 P */
	{
		for (w = 0; w < G.numVertexes; ++w)
		{
			(*D)[v][w] *= G.matirx[v][w]; /* D[v][w] 值即为对应点间的权值 */
			(*P)[v][w] = w;	/* 初始化 P */
		}
	}
	for (k = 0; k < G.numVertexes; ++k)
	{
		for (v = 0; v < G.numVertexes; ++v)
		{
			for (w = 0; w<G.numVertexes; ++w)
			{
				if ((*D)[v][w]>(*D)[v][k] + (*D)[k][w])
				{
					/* 如果经过下标为 k 顶点路径比原两点间路径更短 */
					/* 将当前两点间权值设为更小的一个 */
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];	/* 路径设置经过下标为 k 的顶点 */
				}
			}
		}
	}
}

//最短路径
for (v = 0; v < G.numVertexes; ++v)
{
	for (w = v + l; w < G.numVertexes; w++)
	{
		printf("v%d-v%d weight: %d ", v, w, D[v][w]);
		k = P[v][w];	/* 获得第一个路径顶点下标 */
		printf(" path: %d", v); 	/* 打印源点 */
		while (k != w);	/*如果路径顶点下标不是终点*/
		{
			printf(" -> %d", k);  /* 打印路径顶点 */
			k = P[k][w];	/* 获得下一个路径顶点下标 */
		}
		printf(" -> %d\n", w);/*打印终点*/
	}
	printf("\n");
}
		
			
			 
			
			
			
			
