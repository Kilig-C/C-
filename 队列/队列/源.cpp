#include<iostream>
#include<cstdlib>
using namespace std;

#define MAXSIZE 1024
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;//QElemType���͸���ʵ���������
//ѭ�����е�˳��洢�ṹ 
typedef struct
{
	QElemType data[MAXSIZE];
	int front; //ͷָ��
	int rear; //βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
} SqQueue;
//��ʼ��һ���ն���
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
//���ض��г���
//����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ����
int QueueLenght(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
//����в���
//������δ���������Ԫ��eΪQ�µĶ�βԪ��
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) //���������ж� 
	{
		return ERROR;
	}
	Q->data[Q->rear] = e; //��Ԫ��e��ֵ����β 
	Q->rear = (Q->rear + 1) % MAXSIZE; //rearָ�������һλ�� 
	//���������ת������ͷ��
	return OK;
}
//�����в���
//�����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear) //���пյ��ж�
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; //����ͷԪ�ظ�ֵ��e
	Q->front = (Q->front + 1) % MAXSIZE; //frontָ�������һλ�ã����������ת������ͷ��
	return OK;
}
//�����д洢�ṹ
typedef int QElemType; //QElemType���͸���ʵ���������

typedef struct QNode //���ṹ
{
	QElemType data; //������
	struct QNode *next; //ָ����
}QNode,*QueuePtr;

typedef struct //���е�����ṹ
{
	QueuePtr front, rear; //��ͷ����βָ��
}LinkQueue;
//��Ӳ���
//����Ԫ��eΪQ���µĶ�βԪ��
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode)); //Ϊ�½�������ڴ�ռ�
	if (s == NULL) //�ڴ����ʧ��
	{
		exit(OVERFLOW);//// ֱ���˳�����,���ش������OVERFLOW ������ϵͳ
	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s; //��ӵ��Ԫ��e�Ľ��s��ֵ��ԭ��β���ĺ�̣�����ͼ���� 1 ��ʾ
	Q->rear = s; //�ѵ�ǰ��s����Ϊ��β��㣬rearָ��s������ͼ���� 2 
	return OK;
}
//���Ӳ���
//�����в�Ϊ�գ�ɾ��Q�Ķ�ͷԪ�ء���e������ֵ��������OK,���򷵻�ERROR
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear) //�ж��Ƿ�Ϊ�ն���
	{
		return ERROR;
	}
	p = Q->front->next; //����ɾ���Ķ�ͷ����ݴ��p������ͼ���� 1
	*e = p->data; //����ɾ���Ķ�ͷ����ֵ��ֵ��e
	Q->front->next = p->next; //��ԭ��ͷ�����p->next��ֵ��ͷ����̣�����ͼ���� 2 
	if (Q->rear == p) //����ͷ�Ƕ�β����ɾ����rearָ��ͷ��㣬����ͼ���� 3
	{
		Q->rear = Q->front;
	}
	free(p); //�ͷŽ��p��ָ����ڴ�ռ�
	return OK;
}