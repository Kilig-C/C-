/* 求关键路径，GL 为有向网，输出 GL 的各项关键活动 */
void CriticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	int i, gettop, k, j;
	int ete, lte;	/* 声明活动最早发生时间和最迟发生时间变量 */
	TopologicalSort(GL);	/* 求拓扑序列，计算数组 etv 和 stack2 的值 */
	ltv = (int *)malloc(GL->numVertexes*sizeof(int));	/* 事件最晚发生时间 */
	for (i = 0; i < GL->numVertexes; i++)
	{
		ltv[i] = etv[GL->numVertexes - l];	/* 初始化 ltv */
	}
	while (top2 != 0)	/* 计算 ltv */
	{
		gettop = stack2[top2--];	/* 将拓扑序列出栈，后进先出 */
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			/* 求各顶点事件的最迟发生时间 ltv 值 */
			k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop])/* 求各顶点事件最晚发生时间 ltv */ 
			{
				ltv[gettop] = ltv[k] - e->weight;
			}
		}
	}
	for (j = 0; j < GL->numVertexes; j++) /* 求 ete, lte 和关键活动 */
	{
		for (e = GL->adjList[j].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j]; /* 活动最早发生时间 */
			lte = ltv[k] - e->weight;/* 活动最迟发生时间 */
			if (ete == lte)	/* 两者相等即在关键路径上 */
			{
				printf("<v%d，v%d> length: %d ,", GL->adjList[j].data, GL->adjList[k].data, e->weight);
			}
		}
	}
}


#define OK 1
#define ERROR 0
/* 拓扑排序，用于关键路径计算 */
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int	i, k, gettop;
	int	top = 0;	/* 用于栈指针下标 */
	int	count = 0;	/* 用于统计输出顶点的个数 */
	int *stack;	/* 建栈将入度为 0 的顶点入栈 */
	stack = (int *)malloc(GL->numVertexes * sizeof (int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (0 == GL->adjList[i].in)
		{
			stack[++top] = i;
		}
	}
	//----------------------增加代码----------------
	top2 = 0;	/* 初始化为 0 */
	etv = (int *)malloc(GL->numVertexes*sizeof(int));	/* 事件最早发生时间 */
	for (i = 0; i < GL->numVertexes; i++)
	{
		etv[i] = 0;	/* 初始化为 0 */
	}
	stack2 = (int *)malloc(GL->numVertexes*sizeof(int));	/* 初始化 */
	//-----------------------------------------------
	while (top != 0)
	{
		gettop = stack[top--];
		count++;
		stack2[++top2] = gettop;	/* 将弹出的顶点序号压入拓扑序列的栈——增加代码 */
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in))
			{
				stack[++top] = k;
			}
			//----------------------增加代码----------------
			if ((etv[gettop] + e->weight) > etv[k]) /* 求各顶点事件最早发生时间值 */
			{
				etv[k] = etv[gettop] + e->weight;
			}
			//----------------------------------------------
		}
	}
	if (count < GL->numVertexes)
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}


int *etv, *ltv; /* 事件最早发生时间和最迟发生时间数组 */
int *stack2;	/* 用于存储拓扑序列的栈 */
int top2;	/* 用于 stack2 的指针 */

