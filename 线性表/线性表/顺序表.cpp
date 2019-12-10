//之前的版本
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 1024
typedef int elemtype;
typedef struct sequlist
{
	elemtype data[maxsize];   //定义顺序表为一维数组
	int last;   //last为最后一个数据元素的下标位置
}SequenList;

//1 初始化字符型顺序表L
SequenList * lnit_SequenList()
{
	SequenList *L;//定义顺序表指针变量
	L = (SequenList *)malloc(sizeof(SequenList));/*申请分配内存空间*/
	if (L != NULL)         /*申请分配内存空间成功*/
	{
		L->last = -1;      /*设置顺序表的长度last为-1；表示顺序表为空*/
		printf("初始化成功！\n");
	}
	else
	{
		printf("申请顺序表内存空间失败，程序结束！\n");
		return 0;
	}
	return L;       //返回顺序表的首地址
}

/*2 建立顺序表L */
SequenList *indata_SeqList(SequenList *L)
{
	elemtype x;
	printf("请输入元素(终止输入请输入0即可)：");
	scanf("%d", &x);
	while (x != 0)
	{
		L->last += 1;
		L->data[L->last] = x;
		scanf("%d", &x);
	}
	printf("顺序表建立成功！\n");
	return L;
}

/*3 输出顺序表L的长度*/
int SequenList_Length(SequenList *L)
{
	printf("顺序表的长度为：%d\n", L->last + 1);
	return 0;
}

/* 4 输出顺序表L的第i个元素*/
int input_SequenList(SequenList *L)
{
	int i, j = 0;
	int key;
	printf("要输出的元素为第几个？\n");
	scanf("%d", &key);
	if ((key - 1) <= L->last && (key - 1) >= 0)
	{
		for (i = 0; i <= L->last; i++)
		{
			if (i == (key - 1))
			{
				printf("%d\n", L->data[i]);
				j = 1;
				break;
			}
		}
	}
	else
	{
		printf("你所输入的元素位置不合法！\n");
	}
	return 0;
}
/* 5 输出给定元素的位置  */
int Search_SequenList(SequenList *L)
{
	int i, j = 0;
	int key;
	printf("请输入元素：");
	scanf("%d", &key);
	for (i = 0; i <= L->last; i++)
	{
		if (L->data[i] == key)
		{
			printf("元素位置为：%d\n", i + 1);
			j = 1;
			//return (i + 1);
		}
		/*else
		{
		printf("查找失败");
		}*/
	}
	if (j == 0)
	{
		printf("查找失败");
	}
	return 0;
}

/* 6 在第i个元素前插入给定元素*/
int lnsert_SequenList(SequenList *L)
/*在顺序表L中第i个数据元素之前插入一个元素x,插入前表长n=L->last+1,
i的合法取值范围是 1<=i<=L->last+2*/
{
	int j;
	int i, x;
	printf("在在第几个元素前插入元素？\n");
	scanf("%d", &i);
	printf("插入的元素为：");
	scanf("%d", &x);
	if (L->last >= maxsize - 1)
	{
		printf("表已满无法插入!\n");
		return 0;
	}
	if ((i<1) || (i>L->last + 2))
	{
		printf("插入位置i值不合法!\n");
		return -1;
	}
	/*为插入元素而移动位置*/
	for (j = L->last; j >= i - 1; j--)
	{
		L->data[j + 1] = L->data[j];
	}
	L->data[i - 1] = x;     /*第i个元素下标为i-1*/
	L->last = L->last + 1;
	printf("插入成功！\n");
	return 0;
}

/*7 删除顺序表的第i个元素*/
int Delete_SequenList(SequenList *L)
/*在顺序表中删除第i个元素，并用指针参数e返回其值，
i的合法取值范围为1<=i<=L.last+1*/
{
	int k;
	int i;
	printf("要删除第几个元素？");
	scanf("%d", &i);
	if ((i<1) || (i>L->last + 1))
	{
		printf("删除位置不合法");
	}
	else
	{
		for (k = i; k <= L->last; k++)
		{
			L->data[k - 1] = L->data[k];//结点前移
		}
		L->last--;//表长减一
		printf("删除成功!\n");
	}
	return 0;
}
void show(SequenList *L)
{
	for (int i = 0; i <= L->last; i++)
	{
		printf("%d\n", L->data[i]);
	}

}
//菜单
void menu()
{
	system("cls");
	printf("\n");
	printf("\t\t---------------欢迎使用顺序表的基本操作------------------\n");
	printf("\t\t|\t\t a 初始化顺序表               \t\t|\n");
	printf("\t\t|\t\t b 建立顺序表                 \t\t|\n");
	printf("\t\t|\t\t c 输出顺序表的长度           \t\t|\n");
	printf("\t\t|\t\t d 输出顺序表第i个元素        \t\t|\n");
	printf("\t\t|\t\t e 输出给定元素的位置         \t\t|\n");
	printf("\t\t|\t\t f 在第i个元素前插入给定的元素\t\t|\n");
	printf("\t\t|\t\t g 删除顺序表第i个元素        \t\t|\n");
	printf("\t\t|\t\t h 输出顺序表各个元素         \t\t|\n");
	printf("\t\t|\t\t i 退出系统                   \t\t|\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t请选择(a-g):");
}

int main1()
{
	SequenList *L;
	int  quit = 0;
	elemtype *e = 0;
	char select;
	while (1)
	{
		menu();            //调用子函数
		scanf("%c", &select);
		switch (select)
		{
		case 'a': L = lnit_SequenList(); break;
		case 'b': *indata_SeqList(L); break;
		case 'c': SequenList_Length(L); break;
		case 'd': input_SequenList(L); break;
		case 'e': Search_SequenList(L); break;
		case 'f': lnsert_SequenList(L); break;
		case 'g': Delete_SequenList(L); break;
		case 'h': show(L); break;
		case 'i': quit = 1; break;
		default:printf("请输入a~i之间的数字\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("按任意键返回主菜单！\n");
		getchar();                //提取到缓冲区中的回车键
		getchar();                //起到暂停的作用
		printf("程序结束！\n");
	}
	return 0;
}