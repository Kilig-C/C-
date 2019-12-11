/*
#include<cstdio>
#include<cstdlib>

#define OK    1
#define ERROR 0
#define MAXSIZE 1024
typedef int Status;
typedef int SElemType;	//SElemtype 类型根据实际情况而定，这里假设为int

typedef struct 
{
	SElemType data[MAXSIZE];
	int top;		//用于栈顶指针
}SqStack;
/*
//=========================
#define OK    1
#define ERROR 0
typedef int Status;
#define MAXSIZE 1024
typedef int SElemType;
//两栈共享空间结构
typedef struct
{
	SElemType data[MAXSIZE];
	int top1; //栈1栈顶指针
	int top2; //栈2栈顶指针
}SqDoubleStack;
//插入元素e为新的栈顶元素
Status Push(SqDoubleStack *S, int e,int StackNumber)
{
	if (S->top1 + 1 == S->top2) //栈已满，不能再push新元素了
	{
		return ERROR;
	}
	if (StackNumber == 1)//栈1有元素进栈
	{
		S->data[++S->top1] = e; //若栈1则先top1+1后给数组元素赋值
	}
	if (StackNumber == 2) //栈2有元素进栈
	{
		S->data[--S->top2] = e; //若栈2则先top2-1后给数组元素赋值
	}
	return OK;
}
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
Status Pop(SqDoubleStack *S, SElemType *e, int StackNumber)
{
	if (StackNumber == 1)
	{
		if (S->top1 == -1)
		{
			return ERROR; //说明栈1已经是空栈，溢出
		}
		*e = S->data[S->top1--]; //将栈1的栈顶元素出栈
	}
	else if (StackNumber == 2)
	{
		if (S->top2 == MAXSIZE)
		{
			return ERROR; //说明栈2已经是空栈，溢出
		}
		*e = S->data[S->top2++]; //将栈2的栈顶元素出栈
	}
	return OK;
}

//=============================

//初始化栈
void InitStack(SqStack **S)
{
	*S = (SqStack *)malloc(sizeof(SqStack));
	if (S == NULL) //判断申请内存空间是否成功 失败值为NULL 成功反之
	{
		printf("申请内存空间失败，初始化失败！\n");
	}
	else
	{
		(*S)->top = -1;//将顺序栈的栈顶设为-1，表示栈为空栈
		printf("初始化成功！\n");
	}
}
//创建栈
void CreateStack(SqStack *S)
{
	printf("请输入元素（输入最后一个元素后，请直接换行）：");
	for (int i = S->top+1; i < MAXSIZE; ++i)//i值小于数组最大长度MAXSIZE
	{
		scanf("%d", &S->data[i]);
		S->top++;
		if (getchar() == '\n')//条件成立说明元素都已经录入完毕，跳出循环，结束输入
		{
			break;
		}
	}
	printf("创建完毕！\n");
}
//输出栈的元素个数
void LengthStack(SqStack *S)
{
	if (S->top == -1)
	{
		printf("栈为空栈，元素个数为0\n");
	}
	else
	{
		printf("栈的元素个数为：%d\n", S->top + 1);
	}
}
//输出栈顶元素
void OutTop(SqStack *S)
{
	if (S->top == -1)
	{
		printf("栈为空栈，没有栈顶元素！\n");
	}
	else
	{
		printf("栈顶元素为：%d\n", S->data[S->top]);
	}
}
//入栈操作
//插入元素e到栈顶
Status Push(SqStack *S, SElemType e)
{
	if (S->top >= MAXSIZE - 1)
	{
		printf("栈已满,插入元素失败！\n");
		return ERROR;
	}
	else
	{
		S->top++;
		S->data[S->top] = e;
		printf("插入元素成功！\n");
		return OK;
	}
}
//出栈操作pop
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
	{
		printf("栈为空栈，没有栈顶元素可删除！\n");
		return ERROR;
	}
	*e = S->data[S -> top];	//将要删除的栈顶元素赋值给e
	S->top--;	//栈顶指针减一
	return OK;
}
//输出顺序栈各个元素
void OutValue(SqStack *S)
{
	if (S->top != -1)
	{
		printf("栈中的各个元素为：");
		for (int i = 0; i < S->top + 1; ++i)//从栈底元素开始输出
		{
			printf("%d ", S->data[i]);
		}
		printf("\n其中%d为栈顶元素\n", S->data[S->top]);
	}
	else
	{
		printf("栈为空栈，没有元素！\n");
	}
}
	
//清空顺序栈
void ClearStack(SqStack *S)
{
	if (S->top == -1)
	{
		printf("栈为空栈，请勿重复执行此操作！\n");
	}
	else
	{
		S->top = -1;
		printf("清空栈成功！\n");
	}
}
//顺序栈是否为空
bool StackEmpty(SqStack *S)
{
	if (S->top == -1)
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
	printf("\t\t-------------------欢迎使用顺序栈的基本操作----------------------\n");
	printf("\t\t|\t\t 1  初始化顺序栈                   \t\t|\n");
	printf("\t\t|\t\t 2  建立顺序栈                     \t\t|\n");
	printf("\t\t|\t\t 3  输出顺序栈的元素个数           \t\t|\n");
	printf("\t\t|\t\t 4  输出顺序栈栈顶元素             \t\t|\n");
	printf("\t\t|\t\t 5  插入指定元素到栈顶             \t\t|\n");
	printf("\t\t|\t\t 6  删除栈顶元素                   \t\t|\n");
	printf("\t\t|\t\t 7  输出顺序栈各个元素             \t\t|\n");
	printf("\t\t|\t\t 8  清空顺序栈                     \t\t|\n");
	printf("\t\t|\t\t 9  顺序栈是否为空                 \t\t|\n");
	printf("\t\t|\t\t 10 退出系统                       \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t请选择(1-10):");
}
int main()
{
	SqStack *S;
	int quit = 0;
	int select;
	SElemType e;
	while (1)
	{
		Menu(); //调用菜单函数
		scanf("%d", &select);
		switch (select)
		{
		case 1: InitStack(&S); break; //初始化顺序栈
		case 2: CreateStack(S); break; //建立顺序栈
		case 3: LengthStack(S); break; //输出顺序栈的元素个数
		case 4: OutTop(S); break; //输出顺序栈栈顶元素
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
		case 7: OutValue(S); break; //输出顺序栈各个元素
		case 8: ClearStack(S); break; //清空顺序栈
		case 9: //顺序栈是否为空
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