#include<stdio.h>
typedef int TElemType; //�������������ͣ��˴���λ����

//�������Ķ��������洢�ṹ����
//Link==0 ��ʾָ�����Һ���ָ��
//Thread==1 ��ʾָ��ǰ�����ߺ�̵�����
typedef enum{ Link, Thread } PointerTag;

typedef struct BiThrNode //���������洢��ṹ
{
	TElemType data;     //�������
	struct BiThrNode *lchild, *rchild;   //���Һ���ָ��
	PointerTag LTag;  //���־
	PointerTag RTag;  //�ұ�־
}BiThrNode,*BiThrTree;

BiThrTree pre;  //ȫ�ֱ�����ʼ��ָ��ոշ��ʹ����յ�
//���������������������
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);  //�ݹ�������������
		if (!p->lchild)  //û������
		{
			p->LTag = Thread;  //ǰ������
			p->lchild = pre;   //����ָ��ָ��ǰ��
		}
		if (!pre->rchild) //ǰ��û���Һ���
		{
			pre->RTag = Thread;  //�������
			pre->rchild = p;  //ǰ���Һ���ָ��ָ���̣���ǰ���p��
		}
		pre = p;  //����preָ��p��ǰ��
		InThreading(p->rchild);  //�ݹ�������������
	}
}

#define OK 1
#define ERROR 0
typedef int ElemType; //Ҳ���൱�ڸ�int�����  
typedef int Status; //�����Ӻ����������� 

/*
 T ָ��ͷ��㣬ͷ������� lchild ָ�����㣬ͷ����Ҽ� rchild ָ��
������������һ����㡣����������������������ʾ�Ķ����� T 
*/
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild; // p ָ������
	while (p != T)
	{
		while (p->LTag == Link) //�� LTag==0 ʱѭ�����������е�һ�����
		{
			p = p->lchild;
		}
		printf("%c", p->data); //��ʾ������ݣ����Ը���Ϊ�����Խ�����
		while (p->RTag == Thread&&p->rchild != T)
		{
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild; // p ��������������
	}
	return OK;
}
