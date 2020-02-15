#define OK 1
#define ERROR 0
/* ���������� GL �޻�·������������������в����� OK ,���л�·���� ERROR */
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0; /*����ջָ���±�*/
	int count = 0; /*����ͳ���������ĸ���*/
	int *stack; /* ��ջ�洢���Ϊ 0 �Ķ��� */
	stack = (int *)malloc(GL->numVertexes * sizeof (int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (GL->adjList[i].in = 0)
		{

			stack[++top] = i;	/* �����Ϊ 0 �Ķ�����ջ */
		}
	}
	while (top != 0)
	{
		gettop = stack[top--];	/* ��ջ */
		printf("%d -> ", GL->adjList[gettop].data);	/* ��ӡ�˶��� */
		count++; /* ͳ����������� */
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			/* �Դ˶��㻡����� */
			k = e->adjvex;
			if (!(--GL->adjList[k].in))/*�� k �Ŷ����ڽӵ����ȼ� 1 */
			{
				stack[++top] = k;	/*��Ϊ 0 ����ջ���Ա����´�ѭ�����*/
			}
		}
	}
	if (count < GL->numVertexes) /* ��� count С�ڶ�������˵�����ڻ� */
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

typedef struct EdgeNode	/* �߱��� */
{
	int adjvex;	/* �ڽӵ��򣬴���ö����Ӧ���±� */
	int weight;	/* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����ָ����һ���ڽӵ� */
}EdgeNode;

typedef struct VertexNode /* ������� */
{
	int in;	/* ������� */
	int data;	/* �����򣬴洢������Ϣ */
	EdgeNode *firstedge;	/*	�߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;	/* ͼ�е�ǰ�������ͱ��� */
}graphAdjList, *GraphAdjList;
