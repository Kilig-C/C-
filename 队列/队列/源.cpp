#include<iostream>
#include<cstdlib>
using namespace std;

#define MAXSIZE 1024
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;//QElemType类型根据实际情况而定
//循环队列的顺序存储结构 
typedef struct
{
	QElemType data[MAXSIZE];
	int front; //头指针
	int rear; //尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;
//初始化一个空队列
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
//返回队列长度
//返回Q的元素个数，也就是队列的当前长度
int QueueLenght(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
//入队列操作
//若队列未满，则插入元素e为Q新的队尾元素
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) //队列满的判断 
	{
		return ERROR;
	}
	Q->data[Q->rear] = e; //将元素e赋值给队尾 
	Q->rear = (Q->rear + 1) % MAXSIZE; //rear指针向后移一位置 
	//若到最后则转到数组头部
	return OK;
}
//出队列操作
//若队列不空，则删除Q中队头元素，用e返回其值
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear) //队列空的判断
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; //将队头元素赋值给e
	Q->front = (Q->front + 1) % MAXSIZE; //front指针向后移一位置，若到最后则转到数组头部
	return OK;
}
//链队列存储结构
typedef int QElemType; //QElemType类型根据实际情况而定

typedef struct QNode //结点结构
{
	QElemType data; //数据域
	struct QNode *next; //指针域
}QNode,*QueuePtr;

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