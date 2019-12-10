//顺序表—数组
/*
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define MAXSIZE 1024 //设置数组最大长度
typedef int Elemtype; //设置数组元素类型

//结构体定义
typedef struct
{
	Elemtype Data[MAXSIZE];		//定义顺序表为一维数组
	int Last;					//Last为最后一个数据元素的位置
}SqList;

//初始化操作，建立一个空的线性表L
SqList *InitList()
{
	SqList *L;
	L = (SqList *)malloc(sizeof(SqList));//申请分配内存空间
	if (L != NULL)//申请分配内存空间成功
	{
		L->Last = -1;//设置顺序表的长度Last为-1，表示顺序表为空
		printf("初始化成功！\n");//输出提示语
	}
	else
	{
		printf("申请内存空间失败！\n");//输出提示语
	}
	return L;
}
//创建顺序表
void CreateList(SqList *L)
{
	printf("请输入元素（换行结束输入，最后一个元素后面请不要打空格）：");
	for (int i = L->Last + 1; i < MAXSIZE; ++i)
	{
		scanf("%d", &L->Data[i]);
		L->Last++;
		if (getchar() == '\n')
		{
			break;
		}
	}
	printf("顺序表创建成功！\n");//输出提示语
}
//输出顺序表长度
void ListLength(SqList *L)
{
	printf("顺序表长度为 %d\n", L->Last+1);//数组实际长度为Last长度加1
}
//输出顺序表各个元素
void Output(SqList *L)
{
	for (int i = 0; i < L->Last+1; ++i)
	{
		printf("Data[%d] = %d\n", i, L->Data[i]);
	}
}
//将顺序表L中的第 i 个位置元素值返回给e
int GetElem(SqList *L, int i, int *e)
{
	if (0>i || i > L->Last + 1)
	{
		printf("输入的位置不合法！\n");
		return -1;
	}
	else
	{
		*e = L->Data[i-1];
		return i;
	}
}
// 在顺序表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功；否则，返回0表示失敗。
int LocateElem(SqList *L, int e)
{
	int i = 0;
	while (L->Data[i] != e && i < L->Last + 1)
	{
		i++;
	}
	if (i>L->Last)
	{
		return 0;
	}
	return i;
}
//在顺序表L中的第i个位置插入新元素e
void Listlnsert(SqList *L, int i, int e)
{
	if (i < 1 || i > L->Last+2)
	{
		printf("插入位置不合法！\n");
	}
	else if (L->Last >= MAXSIZE-1)
	{
		printf("顺序表已满，无法插入！\n");
	}
	else
	{
		for (int j = L->Last; j >= i-1; --j)
		{
			L->Data[j + 1] = L->Data[j];
		}
		L->Data[i-1] = e;
		L->Last++;
		printf("插入成功！\n");
	}
}
//删除顺序表L中第i个位置元素，并用e返回其值。
int ListDelete(SqList *L, int i, int *e)
{
	if (i <= 0 || i > L->Last + 1)
	{
		printf("输入的位置不合法！\n");
		return 0;
	}
	else
	{
		*e = L->Data[i - 1];
		for (int j = i-1; j < L->Last+1; ++j)
		{
			L->Data[j] = L->Data[j + 1];
		}
		L->Last--;
		return 1;
	}
}
//将顺序表清空
void ClearList(SqList *L)
{
	if (L->Last >=0)
	{
		memset(L->Data, NULL, L->Last);//将数组指定位置的元素更改为指定的值
		L->Last = -1;
		printf("顺序表清空成功！\n");
	}
	else
	{
		printf("顺序表已经清空成功！请不要重复清空！\n");
	}

}
//若顺序表为空，返回true，否则返回false
bool ListEmpty(SqList *L)
{
	if (L->Last >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//菜单界面
void Menu()
{
	system("cls");//清空屏幕
	printf("\n");
	printf("\t\t---------------欢迎使用顺序表的基本操作------------------\n");
	printf("\t\t|\t\t 1  初始化顺序表               \t\t|\n");
	printf("\t\t|\t\t 2  建立顺序表                 \t\t|\n");
	printf("\t\t|\t\t 3  输出顺序表的长度           \t\t|\n");
	printf("\t\t|\t\t 4  输出顺序表第i个元素        \t\t|\n");
	printf("\t\t|\t\t 5  输出给定元素的位置         \t\t|\n");
	printf("\t\t|\t\t 6  在第i个元素前插入给定的元素\t\t|\n");
	printf("\t\t|\t\t 7  删除顺序表第i个元素        \t\t|\n");
	printf("\t\t|\t\t 8  输出顺序表各个元素         \t\t|\n");
	printf("\t\t|\t\t 9  清空顺序表                 \t\t|\n");
	printf("\t\t|\t\t 10 顺序表是否为空             \t\t|\n");
	printf("\t\t|\t\t 11 退出系统                   \t\t|\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t请选择(1-9):");
}
int main2()
{
	SqList *L;
	int  quit = 0;
	Elemtype e = 0;
	int select;
	int n;
	while (1)
	{
		Menu();            //调用子函数 
		scanf("%d", &select);
		switch (select)
		{
		case 1: L = InitList(); break;
		case 2: CreateList(L); break;
		case 3: ListLength(L); break;
		case 4: printf("输出第几个元素？\n");
				scanf("%d", &n);
				n = GetElem(L, n, &e);
				if (n != -1)
				{
					printf("第%d个元素的值为：%d\n", n, e);
				}
				break;
		case 5: printf("输出那个元素的位置？\n");
				scanf("%d", &e);
				n = LocateElem(L, e);
				if (n != 0)
				{
					printf("该元素的位置为：%d\n", n+1);
				}
				else
				{
					printf("此数组中没有该元素！\n");
				}
				break;
		case 6: printf("插入的元素为：");
				scanf("%d", &e);
				printf("插入元素的位置为：");
				scanf("%d", &n);
				Listlnsert(L,n,e); break;
		case 7: printf("要删除的的元素的位置为：");
				scanf("%d", &n);
				if (ListDelete(L, n, &e))
				{
					printf("删除成功，删除的元素的值为：%d\n", e);
				}
				 break;
		case 8: Output(L); break;		
		case 9: ClearList(L); break;
		case 10:if (ListEmpty(L))
				{
					printf("顺序表不为空！\n");
				}
				else
				{
					printf("顺序表为空！\n");
				}
				break;
		case 11: quit = 1; break;
		default:printf("请输入1~9之间的数字\n"); break;
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