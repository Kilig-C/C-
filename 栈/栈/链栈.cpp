/*
#include<cstdio>
#include<cstdlib>

#define OK 1
#define ERROR 0
typedef int SElemType; //根据实际情况而定
typedef int Status; //根据实际情况而定
//链栈结点结构
typedef struct StackNode
{
	SElemType data; //结点数据域
	struct StackNode *next; //结点指针域指向下一个结点
}StackNode,*LinkStackPtr;
//链栈栈顶结构
typedef struct 
{
	LinkStackPtr top; //指向链栈栈顶元素
	int count; //记录链栈的长度
}LinkStack;

//初始化链栈
Status InitLinkStack(LinkStack **S)
{
	*S = (LinkStack*)malloc(sizeof(LinkStack)); //申请内存空间
	if ((*S) == NULL) //判断申请内存空间是否成功
	{
		printf("申请内存空间失败，初始化失败！\n"); //输出提示语
		return ERROR;
	}
	(*S)->top = NULL; //栈为空时，为NULL,这样最后一个结点的指针域为NULL
	(*S)->count = -1; //链栈为空时，赋值为-1
	printf("初始化成功！\n"); //输出提示语
	return OK;
}
//建立链栈
Status CreateLinkStack(LinkStack *S)
{
	int i = 0;
	SElemType e;
	StackNode *N;
	printf("请输入元素(每个元素之间空格分开，最后一个元素输入后直接换行)：");
	do
	{
		scanf("%d", &e);
		N = (StackNode*)malloc(sizeof(StackNode)); //创建结点申请内存空间
		if (N == NULL) //判断申请内存空间是否成功
		{
			printf("申请内存空间失败，无法继续创建结点！"); //输出提示语
			return ERROR;
		}
		N->data = e; //将e的值赋值给结点N的数据域
		N->next = S->top; //由于链栈的栈顶在链头，所以入栈操作，插入的新结点的指针域要指向原来的栈顶
		S->top = N; //将N结点成为栈顶
		S->count++; //链栈长度加一
	} while(getchar()!='\n'); //判断为换行时 输入结束
	printf("所有元素入栈成功！\n");
	return OK;
}
//输出链栈的元素个数
Status LengthLinkStack(LinkStack *S)
{
	if (S->count == -1) //判断链栈是否为空栈
	{
		printf("链栈为空栈，元素个数为零！\n"); //输出提示语
		return ERROR;
	}
	printf("链栈的元素个数为：%d\n", S->count + 1); //输出链栈元素个数
	return OK;
}
//输出栈顶元素
Status OutTop(LinkStack *S)
{
	if (S->count == -1) //判断链栈是否为空栈
	{
		printf("链栈为空栈，没有栈顶元素！\n"); //输出提示语
		return ERROR;
	}
	printf("链栈的栈顶元素为：%d\n", S->top->data); //输出链栈栈顶元素的值
	return OK;
}
//入栈操作
//插入元素e为新的栈顶元素
Status Push(LinkStack *S, SElemType e)
{
	StackNode *N;
	N = (StackNode*)malloc(sizeof(StackNode)); //申请内存空间，若失败会返回NULL，成功返回地址
	if (N == NULL) //判断申请内存空间是否成功
	{
		printf("申请内存空间失败，无法插入新的栈顶元素！\n"); //输出提示语
		return ERROR;
	}
	N->data = e; //将e的值赋值给N的数据域
	N->next = S->top; //将原来的栈顶作为N的next
	S->top = N; //将N的地址赋值给S 的top最为新的栈顶元素
	S->count++; //栈的长度加一
	printf("入栈成功！\n"); //输出提示语
	return OK;
}
//出栈操作
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
Status Pop(LinkStack *S, SElemType *e)
{
	StackNode *p;
	if (S->count == -1) //判断链栈是否为空栈
	{
		printf("链栈为空栈，没有元素可以出栈！\n"); //输出提示语
		return ERROR;
	}
	p = S->top; //将栈顶元素的指针赋值给p
	*e = p->data; //将栈顶元素数据域的值赋给e
	S->top = p->next; //将栈顶元素的指针域的值赋值给S栈顶指针
	S->count--; //链栈长度减一
	free(p); //释放p所指向的内存空间 此步一定要有，不然会造成内存无法释放，造成内存碎片
	return OK;
}
//输出链栈各个元素
Status OutValue(LinkStack *S)
{
	StackNode *N;
	int i = 1;
	if (S->count == -1) //判断是否为空栈
	{
		printf("链栈为空栈，没有元素可输出！\n"); //输出提示语
		return ERROR;
	}
	N = S->top; //将栈顶指针赋值给N
	do
	{
		printf("第%d个元素为：%d\n", i++, N->data);
		N = N->next; //N指向下一个结点
	} while (N != NULL);
	printf("所有元素按照从栈顶到栈底的顺序完毕！\n"); //输出提示语
	return OK;
}
//清空链栈
Status ClearStack(LinkStack *S)
{
	StackNode *N;
	if (S->count == -1) //判断链栈是否为空栈
	{
		printf("链栈为空栈，不用清空，请勿重复执行次功能！\n"); //输出提示语
		return ERROR;
	}
	do
	{
		N = S->top; //将栈顶指针赋值给N
		S->top = N->next; //栈顶指针指向N结点的下一个结点 
		free(N); //释放N所指向的内存空间
	} while (S->top != NULL); //最后一个结点的指针域指向NULL
	free(S->top); //释放最后一个结点
	S->count = -1; //链栈长度置为-1
	printf("链栈清空成功！\n"); //输出提示语
	return OK;
}
//判断栈是否为空
bool StackEmpty(LinkStack *S)
{
	if (S->count == -1) //判断是否为空栈
	{
		return true;
	}
	return false;
}
//菜单界面
void Menu()
{
	system("cls"); //清空屏幕
	printf("\n");
	printf("\t\t-------------------欢迎使用链栈的基本操作----------------------\n");
	printf("\t\t|\t\t 1  初始化链栈                   \t\t|\n");
	printf("\t\t|\t\t 2  建立链栈                     \t\t|\n");
	printf("\t\t|\t\t 3  输出链栈的元素个数           \t\t|\n");
	printf("\t\t|\t\t 4  输出链栈栈顶元素             \t\t|\n");
	printf("\t\t|\t\t 5  插入指定元素到栈顶             \t\t|\n");
	printf("\t\t|\t\t 6  删除栈顶元素                   \t\t|\n");
	printf("\t\t|\t\t 7  输出链栈各个元素             \t\t|\n");
	printf("\t\t|\t\t 8  清空链栈                     \t\t|\n");
	printf("\t\t|\t\t 9  链栈是否为空                 \t\t|\n");
	printf("\t\t|\t\t 10 退出系统                       \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t请选择(1-10):");
}
int main()
{
	LinkStack *S;
	int quit = 0;
	int select;
	SElemType e;
	while (1)
	{
		Menu(); //调用菜单函数
		scanf("%d", &select);
		switch (select)
		{
		case 1: InitLinkStack(&S); break; //初始化链栈
		case 2: CreateLinkStack(S); break; //建立链栈
		case 3: LengthLinkStack(S); break; //输出链栈的元素个数
		case 4: OutTop(S); break; //输出链栈栈顶元素
		case 5: //插入指定元素到栈顶
			printf("要插入的元素的值为：");
			scanf("%d", &e);
			Push(S, e);
			break;
		case 6: //删除栈顶元素
			if (Pop(S, &e))
			{
				printf("删除成功！\n删除的栈顶元素的值为：%d\n", e);
			}
			break;
		case 7: OutValue(S); break; //输出链栈各个元素
		case 8: ClearStack(S); break; //清空链栈
		case 9: //链栈是否为空
			if (StackEmpty(S))
			{
				printf("栈为空栈！\n");
			}
			else
			{
				printf("栈不为空！\n");
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
	free(S);//释放S
	printf("程序结束！\n");
	return 0;
}
*/