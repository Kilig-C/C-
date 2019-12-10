/*
#include<cstdio>
#include<ctime>
#include<cstdlib>

#define OK    1
#define ERROR 0
typedef int ElemType;
typedef int Status;
//线性表的单链表存储结构
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; //定义LinkList
//单链表的初始化
LinkList InitList()
{
	Node *Head;
	Head = (LinkList)malloc(sizeof(Node)); //创建头结点
	if (Head == NULL)
	{
		printf("初始化申请内存空间失败！\n");
		return ERROR;
	}
	Head->data = -1;	//头结点的数据域我们用来存储链表长度 初始化为-1
	Head->next = NULL;
	printf("初始化成功！\n");
	return Head;
}
//单链表的插入(头插法)
Status ListInsertHead(LinkList Head)
{
	LinkList p, h; //h代表头结点后的第一个结点
	ElemType value;
	h = Head->next;
	printf("请输入数据，输入最后一个数据后请直接换行：");
	while (1)
	{
		scanf("%d", &value);
		p = (LinkList)malloc(sizeof(Node));//创建新结点
		if (p == NULL)
		{
			printf("新结点申请内存空间失败，无法继续创建链表！\n");
			return -1;
		}
		else
		{
			p->data = value;
			p->next = h;
			Head->next = p;
			h = p;
			Head->data++;//链表长度加一
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	printf("单链表创建成功！\n");
	return 0;
}
//单链表的插入(尾插法)
Status ListInsertTail(LinkList Head)
{
	LinkList p, tail;//tail代表尾结点
	ElemType value;
	if (Head->data != -1)//确认链表是否为空链表
	{
		tail = Head->next;
		for (int i = 1; i <= Head->data; ++i)
		{
			tail = tail->next;
		}
	}
	else
	{
		tail = Head;
	}
	printf("请输入数据，输入最后一个数据后请直接换行：");
	while (1)
	{
		scanf("%d", &value);
		p = (LinkList)malloc(sizeof(Node));
		if (p == NULL)
		{
			printf("新结点申请内存空间失败，无法继续创建新链表！\n");
			return -1;
		}
		else
		{
			p->data = value;
			p->next = tail->next;
			tail->next = p;
			tail = p;
			Head->data++;//链表长度为加一
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	printf("单链表创建成功！\n");
	return 0;
}
//单链表的整表创建(头插法) 
//随机产生n个元素的值，建立带表头结点的单链线性表Head
Status CreateListHead(LinkList Head, int n)
{
	LinkList p;
	srand(time(0));		//初始化随机数种子
	for (int i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Node));		//生成新结点
		if (p == NULL)
		{
			printf("申请内存空间失败！\n");
			return ERROR;
		}
		p->data = rand() % 100 + 1;//随机生成100以内的数字
		p->next = Head->next;
		Head->next = p;	//将新产生的结点插入到表头
		Head->data++;//表长加一
	}
	printf("整表创建成功！\n");
	return OK;
}
//单链表的整表创建(尾插法) 
//随机产生n个元素的值，建立带表头结点的单链线性表Head
Status CreateListTail(LinkList Head, int n)
{
	LinkList p, tail;//tail用来指向尾结点
	srand(time(0));
	if (Head->data != -1)//确认链表是否为空链表
	{
		tail = Head->next;
		for (int i = 1; i <= Head->data; ++i)
		{
			tail = tail->next;
		}
	}
	else
	{
		tail = Head;
	}
	for (int i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Node));//生成新结点
		if (p == NULL)
		{
			printf("申请内存空间失败！\n");
			return ERROR;
		}
		p->data = rand() % 100 + 1;//随机生成100以内的数
		tail->next = p;//将表尾终端结点的指针指向新结点
		tail = p;//将当前的新结点定义为表尾终端结点 
		Head->data++;//表长加一
	}
	tail->next = NULL;//表示当前链表结束
	printf("整表创建成功！\n");
	return OK;
}
//输出单链表的长度
void OutLength(LinkList Head)
{
	if (Head->data == -1)
	{
		printf("单链表为空链表，长度为0\n");
	}
	else
	{
		printf("单链表长度为：%d\n", Head->data+1);
	}
}
//获取第i个元素的数据
Status GetElem(LinkList Head, int i, ElemType *e)
{
	LinkList p;		//声明一结点p用来指向链表第一个结点
	p = Head->next;	//让结点p指向链表的一个结点
	if (Head->data == -1 || i > Head->data + 1 || i < 1)
	{
		printf("第%d个元素不存在！\n",i);
		return ERROR;
	}
	for (int j = 0;j < i-1; ++j)
	{
		p = p->next;
	}
	*e = p->data;		//取第i个元素的数据
	return OK;
}
//输出给定元素的位置
Status LocateElem(LinkList Head, int e)
{
	LinkList p;
	bool b = true;
	p = Head->next;	//让结点p指向链表的一个结点
	if (Head->data == -1)
	{
		printf("单链表为空链表，元素%d不存在！\n",e);
		return ERROR;
	}
	for (int i = 0; i < Head->data + 1; ++i)
	{
		if (p->data == e)
		{
			printf("元素%d在链表的位置为：%d\n", e, i + 1);
			b = false;
		}
		p = p->next;
	}
	if (b)
	{
		printf("元素%d不存在！\n", e);
	}
	return OK;
}
//在第i个元素前或后插入给定的元素
Status InsertValue(LinkList Head)
{
	int t,n,e;
	LinkList p,k;
	p = Head;//让结点p指向链表的第一个结点
	printf("想在元素前插入另一个元素请输入1，想在元素后插入另一个元素请输入2：");
	scanf("%d", &t);
	if (t == 1)
	{
		printf("想在第几个元素前插入元素？\n");
	}
	else if (t == 2)
	{
		printf("想在第几个元素后插入元素？\n");
	}
	else
	{
		printf("输入的数字不符合要求！\n");
		return ERROR;
	}
	fflush(stdin);
	scanf("%d", &n);
	if (n < 1 || n > Head->data + 1)
	{
		printf("输入的位置不合法！\n");
		return ERROR;
	}
	fflush(stdin);
	printf("插入的元素的值为：");
	scanf("%d", &e);
	k = (LinkList)malloc(sizeof(Node));
	if (k == NULL)
	{
		printf("为新元素申请内存空间失败，插入失败！\n");
		return ERROR;
	}
	k->data = e;
	for (int i = 0; i < n - 1; ++i)
	{
		p = p->next;
	}
	//此时p为指定位置的前一个位置
	if (t == 2)//为后插时 p指向下一个 也就是指定的位置
	{
		p = p->next;
	}
	k->next = p->next;
	p->next = k;
	Head->data++;
	printf("插入成功！\n");
	return OK;
}
//删除单链表第i个元素
Status DeleteValue(LinkList Head)
{
	LinkList p,k;
	int n,e;
	p = Head->next;
	printf("想要删除第几个元素？\n");
	scanf("%d", &n);
	if (n <= 0 || n > Head->data + 1)
	{
		printf("删除的位置不合法！\n");
		return ERROR;
	}
	for (int i = 1; i < n - 1; ++i)
	{
		p = p->next;
	}
	//此时p为要删除元素的前一个元素的位置
	k = p->next;//k为要删除的位置
	p->next = k->next;
	e = k->data;
	free(k);//释放k所占用的空间 
	Head->data--;
	return e;
}
//输出单链表各个元素
Status Output(LinkList Head)
{
	LinkList p;
	p = Head->next;
	if (Head->data == -1)
	{
		printf("单链表为空链表，没有元素可输出！\n");
		return ERROR;
	}
	for (int i = 1; i <= Head->data + 1;++i)
	{
		printf("第%d个元素的值为：%d\n",i,p->data);
		p = p->next;
	}
	printf("单链表所有元素输出完毕！\n");
	return OK;
}
//清空单链表
void ClearList(LinkList Head)
{
	LinkList p,k;
	p = Head->next;
	for (int i = 0; i < Head->data + 1; ++i)
	{
		Head->next = p->next;
		free(p);//释放p所指向的内存空间
		p = Head->next;
	}
	Head->next = NULL;
	Head->data = -1;
	printf("单链表清空成功！\n");
}
//单链表是否为空
bool ListEmpty(LinkList Head)
{
	if (Head->next == NULL)
	{
		return false;
	}
	return true;
}
//菜单界面
void Menu()
{
	system("cls");//清空屏幕
	printf("\n");
	printf("\t\t-------------------欢迎使用单链表的基本操作----------------------\n");
	printf("\t\t|\t\t 1  初始化单链表                   \t\t|\n");
	printf("\t\t|\t\t 2  单链表的整表创建               \t\t|\n");
	printf("\t\t|\t\t 3  建立单链表                     \t\t|\n");
	printf("\t\t|\t\t 4  输出单链表的长度               \t\t|\n");
	printf("\t\t|\t\t 5  输出单链表第i个元素            \t\t|\n");
	printf("\t\t|\t\t 6  输出给定元素的位置             \t\t|\n");
	printf("\t\t|\t\t 7  在第i个元素前或后插入给定的元素\t\t|\n");
	printf("\t\t|\t\t 8  删除单链表第i个元素            \t\t|\n");
	printf("\t\t|\t\t 9  输出单链表各个元素             \t\t|\n");
	printf("\t\t|\t\t 10 清空单链表                     \t\t|\n");
	printf("\t\t|\t\t 11 单链表是否为空                 \t\t|\n");
	printf("\t\t|\t\t 12 退出系统                       \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t请选择(1-12):");
}
int main()
{
	LinkList Head;
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
		case 1: Head = InitList(); break;
		case 2: printf("采用头插法实现整表创建请输入1，采用尾插法实现整表创建请输入2：");
				scanf("%d", &e);
				if (e != 1 && e != 2)
				{
					printf("输入的数字不符合要求！\n");
				}
				else 
				{
					printf("要创建的元素的个数为：");
					scanf("%d", &n);
					if (e == 1)
					{
						CreateListHead(Head, n);
					}
					else if (e == 2)
					{
						CreateListTail(Head, n);
					}
				}
				break;
		case 3: printf("采用头插法建立单链表请输入1，采用尾插法建立单链表请输入2：");
				scanf("%d", &e);
				if (e == 1)
					{
						ListInsertHead(Head);
					}
					else if (e == 2)
					{
						ListInsertTail(Head);
					}
					else if (e != 1 && e != 2)
					{
						printf("输入的数字不符合要求！\n");
					}
				break;
		case 4: OutLength(Head); break;
		case 5: printf("输出第几个元素？\n");
				scanf("%d", &n);
				if (GetElem(Head, n, &e))
				{
					printf("第%d个元素的值为：%d\n", n, e);
				}
				break;
		case 6: printf("想输出哪个元素的位置？\n");
				scanf("%d", &e);
				LocateElem(Head, e);
				break;
		case 7: InsertValue(Head); break;
		case 8: e = DeleteValue(Head);
				if (e)
				{
					printf("删除成功，删除的元素的值为：%d\n",e);
				}
				break;
		case 9: Output(Head); break;
		case 10: ClearList(Head); break;
		case 11:if (ListEmpty(Head))
				{
					printf("单链表不为空！\n");
				}
				else
				{
					printf("单链表为空！\n");
				}
				break;
		case 12: quit = 1; break;
		default:printf("请输入1~12之间的数字\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("按任意键返回主菜单！\n");
		if (select != 3)
		{
			getchar();                //提取到缓冲区中的回车键
		}
		getchar();                //起到暂停的作用
	}
	printf("程序结束！\n");
	free(Head);
	return 0;
}
*/