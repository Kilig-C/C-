#define MAXVEX 9 
#define INFINITY 65535
typedef int Pathmatirx[MAXVEX];		/* 用于存储最短路径下标的数组 */
typedef int ShortPathTable[MAXVEX];	/* 用于存储到各点最短路径的权值和 */
/* Dijkstra 算法，求有向网 G 的 v0 顶点到其余顶点 v 最短路径P[v] ，及带权长度 D[v] */
/* P[v] 的值为前驱顶点下标，D[v] 表示 v0 到 v 的最短路径长度和。 */
void ShortestPath__Dijkstra(MGraph G, int v0, Pathmatirx *P, ShortPathTable *D)
{
	int v, w, k, min;
	int final[MAXVEX];		/* final [w]=l表示求得顶点v。至vw的最短路径*/
	for (v = 0; v < G.numVertexes; v++)		/* 初始化数据 */
	{
		final[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
		(*D)[v] = G.matirx[v0][v];		/* 将与 v0 点有连线的顶点加上权值 */
		(*P)[v] = 0;			/* 初始化路径数组 P 为 0 */
	}
	(*D)[v0] = 0;		/*	v0 至 v0 路径为	0	*/
	final[v0] = 1;		/* v0 至 v0 不需要求路径 */
	/* 开始主循环，每次求得 v0 到某个 v 顶点的最短路径 */
	for (v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;		/* 当前所知离 v0 顶点的最近距离 */
		for (w = 0; w < G.numVertexes; w++)	/* 寻找离 v0 最近的顶点 */
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w]; /* w 顶点离 v0 顶点更近 */
			}
		}
		final[k] = 1;	/* 将目前找到的最近的顶点置为 1 */
		for (w = 0; w < G.numVertexes; w++)	/*修正当前最短路径及距离*/
		{
			/* 如果经过 v 顶点的路径比现在这条路径的长度短的话 */
			if (!final[w] && (min + G.matirx[k][w] < (*D)[w]))
			{
				/* 说明找到了更短的路径，修改 D[w] 和 P[w] */
				(*D)[w] = min + G.matirx[k][w];	/* 修改当前路径长度 */
				(*P)[w] = k;
			}
		}
	}
}
