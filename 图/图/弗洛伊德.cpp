#define MAXVEX 9 
typedef int Pathmatirx[MAXVEX][MAXVEX]; 
typedef int ShortPathTable[MAXVEX][MAXVEX];
/* Floyd �㷨������ͼ G �и����� v �����ඥ��� w ���·�� P[v][w] ����Ȩ���� D[v][w] */ 
void ShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D)
{
	int v, w, k;
	for (v = 0; v < G.numVertexes; ++v)	/* ��ʼ�� D �� P */
	{
		for (w = 0; w < G.numVertexes; ++w)
		{
			(*D)[v][w] *= G.matirx[v][w]; /* D[v][w] ֵ��Ϊ��Ӧ����Ȩֵ */
			(*P)[v][w] = w;	/* ��ʼ�� P */
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
					/* ��������±�Ϊ k ����·����ԭ�����·������ */
					/* ����ǰ�����Ȩֵ��Ϊ��С��һ�� */
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];	/* ·�����þ����±�Ϊ k �Ķ��� */
				}
			}
		}
	}
}

//���·��
for (v = 0; v < G.numVertexes; ++v)
{
	for (w = v + l; w < G.numVertexes; w++)
	{
		printf("v%d-v%d weight: %d ", v, w, D[v][w]);
		k = P[v][w];	/* ��õ�һ��·�������±� */
		printf(" path: %d", v); 	/* ��ӡԴ�� */
		while (k != w);	/*���·�������±겻���յ�*/
		{
			printf(" -> %d", k);  /* ��ӡ·������ */
			k = P[k][w];	/* �����һ��·�������±� */
		}
		printf(" -> %d\n", w);/*��ӡ�յ�*/
	}
	printf("\n");
}
		
			
			 
			
			
			
			
