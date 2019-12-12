//顺序队列之循环队列
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
Status InitQueue(SqQueue **Q)
{

	//初始化时，队列的对头指针front和队尾指针rear都指向下标0
	(*Q)->front = 0;
	(*Q)->rear = 0;
	return OK;
}
//建立顺序队列
Status CreateQueue(SqQueue *Q)
{
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

//若队列Q存在且非空，用e返回队列Q的队头元素
Status GetHead(SqQueue *Q, QElemType*e)
{
	return OK;
}
//输出顺序队列各个元素
Status OutValue(SqQueue *Q)
{
	return OK;
}
//清空顺序队列
Status ClearQueue(SqQueue *Q)
{
	return OK;
}
//顺序队列是否为空 空返回true 不为空返回false
Status QueueEmpty(SqQueue *Q)
{
	return OK;
}
//菜单界面
void Menu()
{
	system("cls"); //清空屏幕
	printf("\n");
	printf("\t\t-------------------欢迎使用顺序队列的基本操作----------------------\n");
	printf("\t\t|\t\t 1  初始化顺序队列                   \t\t|\n");
	printf("\t\t|\t\t 2  建立顺序队列                     \t\t|\n");
	printf("\t\t|\t\t 3  输出顺序队列的元素个数           \t\t|\n");
	printf("\t\t|\t\t 4  输出顺序队列队头元素             \t\t|\n");
	printf("\t\t|\t\t 5  插入指定元素到队尾             \t\t|\n");
	printf("\t\t|\t\t 6  删除队头元素                   \t\t|\n");
	printf("\t\t|\t\t 7  输出顺序队列各个元素             \t\t|\n");
	printf("\t\t|\t\t 8  清空顺序队列                     \t\t|\n");
	printf("\t\t|\t\t 9  顺序队列是否为空                 \t\t|\n");
	printf("\t\t|\t\t 10 退出系统                       \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t请选择(1-10):");
}
int main()
{
	SqQueue *Q;
	int quit = 0;
	int select;
	QElemType e;
	while (1)
	{
		Menu(); //调用菜单函数
		scanf("%d", &select);
		switch (select)
		{
		case 1: InitQueue(&Q); break; //初始化顺序队列
		case 2: CreateQueue(Q); break; //建立顺序队列
		case 3: QueueLenght(*Q); break; //输出顺序队列的元素个数
		case 4: GetHead(Q,&e); break; //输出顺序队列队头元素
		case 5: //插入指定元素到队尾
			printf("要插入的元素的值为：");
			scanf("%d", &e);
			EnQueue(Q, e);
			break;
		case 6: //删除队列队头元素
			if (DeQueue(Q, &e))
			{
				printf("删除成功！\n删除的队列队头元素的值为：%d\n", e);
			}
			break;
		case 7: OutValue(Q); break; //输出顺序队列各个元素
		case 8: ClearQueue(Q); break; //清空顺序队列
		case 9: //顺序队列是否为空
			if (QueueEmpty(Q))
			{
				printf("队列为空队列！\n");
			}
			else
			{
				printf("队列不为空！\n");
			}
			break;
		case 10: quit = 1; break;//退出系统
		default:printf("请输入1-10之间的数字\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("按任意键返回主菜单！\n");
		if (select != 2)
		{
			getchar(); //提取缓冲区中的回车键
		}
		getchar(); //起到暂停的作用
	}
	free(Q);//释放Q
	printf("程序结束！\n");
	return 0;
}