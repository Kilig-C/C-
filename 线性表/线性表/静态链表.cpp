//#include<cstdio>
//#include<cstdlib>
/*
对数组第一个和最后一个元素作为特殊元素处理，不存数据。
我们通常把未被使用的数组元素称为备用链表。而数组第一个元素，
即下标为0的元素的 cur 就存放备用链表的第一个结点的下标；
而数组的最后一个元素的cur则存放第一个有数值的元素的下标，
相当于静态链表中的头结点作用，当整个链表为空时，则为0。
*/
/*
#define MAXSIZE 1024 //假设链表的最大长度是1024
#define OK 1
#define ERROR 0
typedef int ElemType; //也就相当于给int起别名  这样做是为了方便修改创建的静态链表的元素类型
typedef int Status; //创建子函数返回类型 
//线性表的静态链表存储结构 
typedef struct
{
	ElemType data; //用来存储数据元素 
	int cur; //用来存放下一个元素的下标，相当于静态链表中指针的作用 
}Component, StaticLinkList[MAXSIZE];

//静态链表初始化
//将一维数组space中各分量，链成一备用链表
//space[0].cur为头指针，"0"表示为空指针 
Status InitList(StaticLinkList space)
{
	int i;
	for (int i = 0; i<MAXSIZE - 1; ++i)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 2].cur = -1;
	space[MAXSIZE - 1].cur = -1;//目前静态链表为空，最后一个元素的cur存放第一个带插入元素的下标，此时为0
	return OK;
}
//输出链表长度
int ListLenght(StaticLinkList L)
{
	int i = L[MAXSIZE - 1].cur;//最后一个元素相当于链表的头指针，不存数据
	int j = -1;//用来记录已使用的数组长度
	while (i != -1)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
//模拟malloc函数
//若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SLL(StaticLinkList space)
{
	//当前数组第一个元素的cur存的值，就是要返回的备用空闲元素的下标
	int i = space[0].cur;
	if (space[0].cur != -1)
	{
		space[0].cur = space[i].cur;
		space[i].cur = -1;
		//由于要把space[i]这个分量使用了，所以space[i].cur也就是下一个分量成为第一个备用元素
		return i;
	}
	else
	{
		return ERROR;
	}
}
//模拟free函数
//将删除不使用的空闲结点回收到备用链表
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;//把第一个空闲元素的cur赋值给要删除的元素的cur
	space[0].cur = k;//把要删除的分量的下标赋值给数组第一个元素的cur
	//相当于将不使用的结点插入到备用链表的第一个元素的前面，而其data不用处理，使用时新的数值会覆盖它
}
//头插和尾插法 创建链表
Status ListInsertHT(StaticLinkList L)
{
	int i, j, t, n = 0;
	Status e;//暂时保存要插入的元素的值
	printf("采用头插法创建链表请输入1，采用尾插法创建链表请输入2：");
	scanf("%d", &t);
	if (t != 1 && t != 2)
	{
		printf("输入的数字不符合要求！\n");
		return ERROR;
	}
	fflush(stdin);
	printf("请输入要插入的元素(输入最后一个元素之后请直接换行)：");
	while (1)
	{
		scanf("%d", &e);
		i = Malloc_SLL(L);
		if (i)//i为0的话说明已经没有空闲分量了
		{
			L[i].data = e;//将要插入的数据赋值给此分量的data
			if (t == 1)//头插
			{
				L[i].cur = L[MAXSIZE - 1].cur;
				L[MAXSIZE - 1].cur = i;
			}
			else //尾插
			{
				if (n == 0)
				{
					n = 1;
					for (j = MAXSIZE - 1; L[j].cur != -1; j = L[j].cur);//链表最后一个结点的cur为-1
				}
				//此时j为最后一个结点的下标
				L[j].cur = i;
				j = i;
			}
			if (getchar() == '\n')
			{
				break;
			}
		}
		else
		{
			printf("内存已满！\n");
			return ERROR;
		}
	}
	printf("插入完毕！\n");
	return OK;
}
//插入操作
//在L中第n个元素前插入新的元素e
Status ListInsert(StaticLinkList L)
{
	int n, e;
	int j, k;
	k = MAXSIZE - 1;//注意k首先是最后一个元素的下标
	printf("想要在第几个元素前插入元素？\n");
	scanf("%d", &n);
	if (n<1 || n>ListLenght(L) + 1)
	{
		printf("输入的位置不合法！\n");
		return ERROR;
	}
	printf("请输入要插入的元素的值：");
	scanf("%d", &e);
	j = Malloc_SLL(L);//获取空闲分量的下标
	if (j)//j为0的话说明已经没有空闲分量了
	{
		L[j].data = e;//将要插入的数据赋值给此分量的data
		//k从第一个元素的下标到要插入元素的前一个元素 
		for (int i = 1; i <= n - 1; ++i)
		{
			k = L[k].cur;
		}
		//如果在第n个元素前插入元素，此时k的值为在第n-1个元素的下标
		L[j].cur = L[k].cur;//把第n个元素的下标赋值给新的元素的cur
		//此时新插入的元素指向第n个元素
		L[k].cur = j;//把新元素的下标赋值给原本第n元素前的元素的cur
		return OK;
	}
	printf("内存已分配满，无法插入新元素！\n");
	return ERROR;
}
//删除操作
//删除在L中的第n个元素e
Status ListDelete(StaticLinkList L)
{
	int n;//删除元素的位置
	int k, t;
	printf("想要删除第几个元素？\n");
	scanf("%d", &n);
	if (n<1 || n>ListLenght(L));
	{
		printf("输入的位置不合法！\n");
		return ERROR;
	}
	k = MAXSIZE - 1;//此时k为头结点的位置
	for (int i = 1; i <= n - 1; ++i)
	{
		k = L[k].cur;
	}
	//此时k为要删除元素的前一个元素的位置
	t = L[k].cur;//t为要删除元素的下标
	L[k].cur = L[t].cur; //把要删除元素的cur中的值赋值给要删除元素前一个元素的cur
	Free_SLL(L, k);//将删除的结点回收到备用链表
	return OK;
}
//输出指定位置的元素
Status GetElem(StaticLinkList L, int n, int *e)
{
	int k = L[MAXSIZE - 1].cur;//此时k在头结点位置
	for (int i = 0; i < n-1; ++i)
	{
		k = L[k].cur;
	}
	*e = L[k].data;
	return OK;
}
//输出给定元素的位置
Status LocateElem(StaticLinkList L, int e)
{
	int k = L[MAXSIZE - 1].cur;
	bool b = true;
	if (ListLenght(L) < 0)
	{
		printf("静态链表为空链表，元素%d不存在！\n", e);
		return ERROR;
	}
	for (int i = 0; i < ListLenght(L)+1; ++i)
	{
		if (L[k].data == e)
		{
			printf("元素%d在链表的位置为：%d\n", e, i + 1);
			b = false;
		}
		k = L[k].cur;
	}
	if (b)
	{
		printf("元素%d不存在！\n", e);
	}
	return OK;
}
//在第i个元素前插入给定的元素
Status InsertValue(StaticLinkList L)
{
	int t, n, e;
	int k = MAXSIZE - 1;
	printf("想在第几个元素前插入元素？\n");
	scanf("%d", &n);
	if (n < 1 || n > ListLenght(L) + 1)
	{
		printf("输入的位置不合法！\n");
		return ERROR;
	}
	printf("插入的元素的值为：");
	scanf("%d", &e);
	t = Malloc_SLL(L);
	if (t == 0)
	{
		printf("为新元素申请内存空间失败，插入失败！\n");
		return ERROR;
	}
	L[t].data = e;
	for (int i = 0; i < n - 1; ++i)
	{
		k = L[k].cur;
	}
	//此时k为指定位置的前一个位置
	L[t].cur = L[k].cur;
	L[k].cur = t;
	printf("插入成功！\n");
	return OK;
}
//删除单链表第i个元素
Status DeleteValue(StaticLinkList L)
{
	int k = MAXSIZE - 1;
	int n, e, t;
	printf("想要删除第几个元素？\n");
	scanf("%d", &n);
	if (n <= 0 || n > ListLenght(L) + 1)
	{
		printf("删除的位置不合法！\n");
		return ERROR;
	}
	for (int i = 1; i < n - 1; ++i)
	{
		k = L[k].cur;
	}
	//此时k为要删除元素的前一个元素的位置
	t = L[k].cur;//t为要删除的位置
	L[k].cur = L[t].cur;
	e = L[t].data;
	Free_SLL(L, t);//释放t所占用的空间 
	return e;
}
//输出单链表各个元素
Status Output(StaticLinkList L)
{
	int p = L[MAXSIZE - 1].cur;
	if (ListLenght(L) == -1)
	{
		printf("单链表为空链表，没有元素可输出！\n");
		return ERROR;
	}
	for (int i = 1; i <= ListLenght(L) + 1; ++i)
	{
		printf("第%d个元素的值为：%d\n", i, L[p].data);
		p = L[p].cur;
	}
	printf("单链表所有元素输出完毕！\n");
	return OK;
}
//菜单界面
void Menu()
{
	system("cls");//清空屏幕
	printf("\n");
	printf("\t\t-------------------欢迎使用静态链表的基本操作----------------------\n");
	printf("\t\t|\t\t 1  初始化静态链表                   \t\t|\n");
	printf("\t\t|\t\t 2  建立静态链表                     \t\t|\n");
	printf("\t\t|\t\t 3  输出静态链表的长度               \t\t|\n");
	printf("\t\t|\t\t 4  输出静态链表第i个元素            \t\t|\n");
	printf("\t\t|\t\t 5  输出给定元素的位置               \t\t|\n");
	printf("\t\t|\t\t 6  在第i个元素前插入给定的元素      \t\t|\n");
	printf("\t\t|\t\t 7  删除静态链表第i个元素            \t\t|\n");
	printf("\t\t|\t\t 8  输出静态链表各个元素             \t\t|\n");
	printf("\t\t|\t\t 9  清空静态链表                     \t\t|\n");
	printf("\t\t|\t\t 10 静态链表是否为空                 \t\t|\n");
	printf("\t\t|\t\t 11 退出系统                         \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t请选择(1-11):");
}
int main()
{
	StaticLinkList L;
	int  quit = 0;
	ElemType e = 0;
	int select;
	int n;
	while (1)
	{
		Menu();            //调用子函数 
		scanf("%d", &select);
		switch (select)
		{
		case 1: InitList(L); 
				printf("初始化成功！\n");
				break;
		case 2: ListInsertHT(L);break;
		case 3: printf("链表长度为：%d\n", ListLenght(L) + 1);
				break;
		case 4: printf("输出第几个元素？\n");
				scanf("%d", &n);
				if (n<1 || n>ListLenght(L) + 1)
				{
					printf("输入的元素的位置不合法！\n");
					break;
				}
				if (GetElem(L, n, &e))
				{
					printf("第%d个元素的值为：%d\n", n, e);
				}
				break;
		case 5: printf("想输出哪个元素的位置？\n");
				scanf("%d", &e);
				LocateElem(L, e);
				break;
		case 6: InsertValue(L); break;
		case 7: e = DeleteValue(L);
				if (e)
				{
					printf("删除成功，删除的元素的值为：%d\n", e);
				}
				break;
		case 8: Output(L); break;
		case 9: InitList(L); 
				printf("清空链表成功！\n");
				break;
		case 10:if (ListLenght(L) + 1)
				{
					printf("静态链表不为空！\n");
				}
				else
				{
					printf("静态链表为空！\n");
				}
				break;
		case 11: quit = 1; break;
		default:printf("请输入1~11之间的数字\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("按任意键返回主菜单！\n");
		if (select != 2)
		{
			getchar();                //提取到缓冲区中的回车键
		}
		getchar();                //起到暂停的作用
	}
	printf("程序结束！\n");
	return 0;
}
*/
/*
ADT 栈（stack）
Data
同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系。
Operation
InitStack(*S) : 初始化操作，建立一个空栈S。
DestoryStack(*S) : 若栈存在，则销毁它。
ClearStack(*S) : 将栈清空。
StackEmpty(S) : 若栈为空，返回true，否则返回false。
GetTop(S, *e) : 若栈存在且非空，用e返回S的栈顶元素。
Push(*S, e) : 若栈S存在，插入新元素e到栈S中并成为栈顶元素。
Pop(*S, *e) : 删除栈S中的栈顶元素，并用e返回其值。
StackLength(S) : 返回栈S的元素个数。
endADT
*/
#include<cstdio>
#include<cstdlib>

#define OK    1
#define ERROR 0
#define MAXSIZE 1024
typedef int Status;
typedef int SElemType;	//SElemtype 类型根据实际情况而定，这里假设为int

typedef struct SqStack
{
	SElemType data[MAXSIZE];
	int top;		//用于栈顶指针
}SqStack;
//初始化栈
void InitStack(SqStack *S)
{
	S = (SqStack *)malloc(sizeof(SqStack));
	if (S == NULL) //判断申请内存空间是否成功 失败值为NULL 成功反之
	{
		printf("申请内存空间失败，初始化失败！\n");
	}
	else
	{
		S->top = -1;//将顺序栈的栈顶设为-1，表示栈为空栈
		printf("初始化成功！\n");
	}
}
//创建栈
void CreateStack(SqStack *S)
{
	printf("请输入元素（输入最后一个元素后，请直接换行）：");
	for (int i = S->top + 1; i < MAXSIZE; ++i)//i值小于数组最大长度MAXSIZE
	{
		scanf("%d", &S->data[i]);
		if (getchar() == '\n')//条件成立说明元素都已经录入完毕，跳出循环，结束输入
		{
			break;
		}
		S->top++;
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
	*e = S->data[S->top];	//将要删除的栈顶元素赋值给e
	S->top--;	//栈顶指针减一
	return OK;
}
//输出顺序栈各个元素
void OutValue(SqStack *S)
{
	printf("栈中的各个元素为：");
	for (int i = 0; i < S->top + 1; ++i)//从栈底元素开始输出
	{
		printf("%d ", S->data[i]);
	}
	printf("\n其中%d为栈顶元素\n", S->data[S->top]);
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
		S->top == -1;
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
		case 1: InitStack(S); break; //初始化顺序栈
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
				printf("删除成功！删除的栈顶元素的值为：%d", e);
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
