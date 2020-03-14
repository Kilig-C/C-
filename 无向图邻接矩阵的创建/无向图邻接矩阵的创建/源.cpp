#include<stdio.h>

typedef int VertexType;	//���������
typedef int EdgeType;	//�ߵ�Ȩֵ����
#define MaxVex 100 //������󶨵���
#define Infinity (~(1<<(sizeof(int)*8-1)))
/*
��ʾ1����4*8-1λ Ȼ��ȡ��,
int��intΪ���ֽ�ʱ��int���еĵ����ϲ������ֽڣ������ֵ��
������֮�䲻�ڽ�ʱ��������֮���Ȩֵ��Ϊint�����ֵ��
�����ʱ���á��ޡ���ʾ��
*/

//�ڽӾ�����
typedef struct
{
	VertexType Vexs[MaxVex];	//�������飬�����
	EdgeType   Edge[MaxVex][MaxVex]; //�ߵ�Ȩֵ��Ϣ���飬�߱�
	int numV;	//��ǰ�Ķ�����
	int numE;	//��ǰ�ı���
}MGraph;

//��������ͼ���ڽӾ���
void CreateMGraph(MGraph *G)
{
	int vi, vj, e;//vi,vj�����洢���㣬
	printf("������ͼ�Ķ������ͱ���(������ ����)��");
	scanf("%d %d", &G->numV, &G->numE);//������������������
	for (int i = 0; i < G->numV; i++)//����ĳ�ʼ��
	{
		for (int j = 0; j < G->numV; j++)
		{
			if (i == j)
			{
				G->Edge[i][j] = 0;//�������������Ȩֵ��ʼ��Ϊ0
			}
			else
			{
				G->Edge[i][j] = Infinity;//�����������������Ȩֵ��ʼ��ΪInfinity
			}
		}
	}
	for (int i = 0; i < G->numV; i++)//��������Ϣ��������˳����뵽����������
	{
		printf("�������%d�������ֵ��", i + 1);
		scanf("%d", &G->Vexs[i]);
	}
	printf("\n");

	for (int k = 0; k < G->numE; ++k)
	{
		int i, j;
		printf("������ߵ���Ϣ������ ���� Ȩֵ��:");
		scanf("%d%d%d", &vi, &vj, &e);
		/*
		��Ϊ����Ȩֵ��ͼ������ʱe����1��
		��Ϊ��Ȩֵ��ͼ����e�����Ӧ��Ȩֵ
		*/
		for (i = 0; i < G->numV; i++)
		{
			if (G->Vexs[i] == vi)
			{
				break;//�ҳ�������������е�λ��
			}
		}
		for (j = 0; j < G->numV; j++)
		{
			if (G->Vexs[j] == vj)
			{
				break;//�ҳ�������������е�λ��
			}
		}
		G->Edge[i][j] = e;
		G->Edge[j][i] = e;
		//����ͼ���ڽӾ�����жԳ��ԣ�Ҳ��������ߵ�Ȩֵ��һ����
		//����ͼ���߱������ʣ�ֻ��Ҫִ�е�һ�����ڶ�������Ҫִ��
	}
}

//�������ͼ���ڽӾ���
void ShowpGraph(MGraph G)
{
	printf("\n�ڽӾ���Ϊ��\n");
	printf("\t");
	for (int i = 0; i < G.numV; ++i)
	{
		printf("%6d", G.Vexs[i]);
		//��ʾÿ�������ֵ
	}
	printf("\n");
	for (int i = 0; i < G.numV; ++i)
	{
		printf("\n%8d", G.Vexs[i]);
		for (int j = 0; j < G.numV; ++j)
		{
			if (G.Edge[i][j] == Infinity)
			{
				//����֮��������ʱ������ޡ�
				printf("%6s", "��");
			}
			else
			{
				//����֮��������ʱ������ߵ�Ȩֵ
				printf("%6d", G.Edge[i][j]);
			}
		}
		printf("\n");
	}
}

int main()
{
	MGraph G;
	CreateMGraph(&G);//��������ͼ���ڽӾ���
	ShowpGraph(G);//�������ͼ���ڽӾ���
	return 0;
}