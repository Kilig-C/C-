#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int QElemType; //QElemType���͸���ʵ���������
typedef int Status; //Status���͸���ʵ���������
//�����д洢�ṹ
typedef struct QNode //���ṹ
{
	QElemType data; //������
	struct QNode *next; //ָ����
}QNode, *QueuePtr;

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