#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//����˫�ױ�ʾ�����ṹ����
#define MAX_TREE_SIZE 100  //�������Ĵ�С 
typedef int TElemType; //�������������ͣ��˴���λ����

//�������Ķ���������ṹ����
typedef struct BiTNode //���ṹ
{
	TElemType data; //�������
	struct BiTNode *lchild, *rchild; //���Һ���ָ��
}BiTNode,*BiTree;

//��������ǰ������ݹ��㷨
void PreOrderTraverse(BiTree T)
{
	if (T == NULL) //�ж����Ƿ�Ϊ��
	{
		return; //�����Ϊ�գ�ֱ�ӷ��أ���ִ�к�������
	}
	printf("%c", T->data); //��ʾ������ݣ����Ը���Ϊ�����Խ��Ĳ���
	PreOrderTraverse(T->lchild); //���������������
	PreOrderTraverse(T->rchild); //����������������
}

//����������������ݹ��㷨
void InOrderTraverse(BiTree T)
{
	if (T == NULL) //�ж����Ƿ�Ϊ��
	{
		return; //�����Ϊ�գ�ֱ�ӷ��أ���ִ�к�������
	}
	InOrderTraverse(T->lchild); //�������������
	printf("%c", T->data); //��ʾ������ݣ����Ը���Ϊ�����Խ��Ĳ���
	InOrderTraverse(T->rchild); //����������������
}

//�������ĺ�������ݹ��㷨
void PostOrderTraverse(BiTree T)
{
	if (T == NULL) //�ж����Ƿ�Ϊ��
	{
		return; //�����Ϊ�գ�ֱ�ӷ��أ���ִ�к�������
	}
	PostOrderTraverse(T->lchild); //�Ⱥ������������
	PostOrderTraverse(T->rchild); //�ٺ������������
	printf("%c", T->data); //��ʾ������ݣ�Ҳ���Ը���Ϊ�����Խ�����
}

//��ǰ������������н���ֵ��һ���ַ���
// # ��ʾ������������������ʾ������T
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
		{
			/*
				OVERFLOWΪmath.h�е�һ���궨�壬��ֵΪ3��
			����Ϊ��������г��������磬
			������������������������ܴ洢�ķ�Χ��
				exit(OVERFLOW)�ĺ�����ǣ��˳�����
			������OVERFLOW��ֵ���������̡����׼��ʹ�÷�ΧΪ:
			�����������������ʱ���˳����򲢱�����������̡� 
			*/
			exit(OVERFLOW);
		}
		(*T)->data = ch; //���ɸ����
		CreateBiTree(&(*T)->lchild); //����������
		CreateBiTree(&(*T)->rchild); //����������
	}
}



