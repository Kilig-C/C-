#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int QElemType; //QElemType类型根据实际情况而定
typedef int Status; //Status类型根据实际情况而定
//链队列存储结构
typedef struct QNode //结点结构
{
	QElemType data; //数据域
	struct QNode *next; //指针域
}QNode, *QueuePtr;

typedef struct //队列的链表结构
{
	QueuePtr front, rear; //队头、队尾指针
}LinkQueue;
//入队操作
//插入元素e为Q的新的队尾元素
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode)); //为新结点申请内存空间
	if (s == NULL) //内存分配失败
	{
		exit(OVERFLOW);//// 直接退出进程,返回错误代码OVERFLOW 给操作系统
	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s; //把拥有元素e的结点s赋值给原队尾结点的后继，如上图操作 1 所示
	Q->rear = s; //把当前的s设置为队尾结点，rear指向s，如上图操作 2 
	return OK;
}
//出队操作
//若队列不为空，删除Q的队头元素。用e返回其值，并返回OK,否则返回ERROR
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear) //判断是否为空队列
	{
		return ERROR;
	}
	p = Q->front->next; //欲将删除的队头结点暂存给p，如上图操作 1
	*e = p->data; //欲将删除的队头结点的值赋值给e
	Q->front->next = p->next; //将原队头结点后继p->next赋值给头结点后继，如上图操作 2 
	if (Q->rear == p) //若队头是队尾，则删除后将rear指向头结点，如上图操作 3
	{
		Q->rear = Q->front;
	}
	free(p); //释放结点p所指向的内存空间
	return OK;
}