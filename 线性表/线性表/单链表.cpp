/*
#include<cstdio>
#include<ctime>
#include<cstdlib>

#define OK    1
#define ERROR 0
typedef int ElemType;
typedef int Status;
//���Ա�ĵ�����洢�ṹ
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; //����LinkList
//������ĳ�ʼ��
LinkList InitList()
{
	Node *Head;
	Head = (LinkList)malloc(sizeof(Node)); //����ͷ���
	if (Head == NULL)
	{
		printf("��ʼ�������ڴ�ռ�ʧ�ܣ�\n");
		return ERROR;
	}
	Head->data = -1;	//ͷ�������������������洢������ ��ʼ��Ϊ-1
	Head->next = NULL;
	printf("��ʼ���ɹ���\n");
	return Head;
}
//������Ĳ���(ͷ�巨)
Status ListInsertHead(LinkList Head)
{
	LinkList p, h; //h����ͷ����ĵ�һ�����
	ElemType value;
	h = Head->next;
	printf("���������ݣ��������һ�����ݺ���ֱ�ӻ��У�");
	while (1)
	{
		scanf("%d", &value);
		p = (LinkList)malloc(sizeof(Node));//�����½��
		if (p == NULL)
		{
			printf("�½�������ڴ�ռ�ʧ�ܣ��޷�������������\n");
			return -1;
		}
		else
		{
			p->data = value;
			p->next = h;
			Head->next = p;
			h = p;
			Head->data++;//�����ȼ�һ
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	printf("���������ɹ���\n");
	return 0;
}
//������Ĳ���(β�巨)
Status ListInsertTail(LinkList Head)
{
	LinkList p, tail;//tail����β���
	ElemType value;
	if (Head->data != -1)//ȷ�������Ƿ�Ϊ������
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
	printf("���������ݣ��������һ�����ݺ���ֱ�ӻ��У�");
	while (1)
	{
		scanf("%d", &value);
		p = (LinkList)malloc(sizeof(Node));
		if (p == NULL)
		{
			printf("�½�������ڴ�ռ�ʧ�ܣ��޷���������������\n");
			return -1;
		}
		else
		{
			p->data = value;
			p->next = tail->next;
			tail->next = p;
			tail = p;
			Head->data++;//������Ϊ��һ
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	printf("���������ɹ���\n");
	return 0;
}
//�������������(ͷ�巨) 
//�������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�Head
Status CreateListHead(LinkList Head, int n)
{
	LinkList p;
	srand(time(0));		//��ʼ�����������
	for (int i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Node));		//�����½��
		if (p == NULL)
		{
			printf("�����ڴ�ռ�ʧ�ܣ�\n");
			return ERROR;
		}
		p->data = rand() % 100 + 1;//�������100���ڵ�����
		p->next = Head->next;
		Head->next = p;	//���²����Ľ����뵽��ͷ
		Head->data++;//����һ
	}
	printf("�������ɹ���\n");
	return OK;
}
//�������������(β�巨) 
//�������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�Head
Status CreateListTail(LinkList Head, int n)
{
	LinkList p, tail;//tail����ָ��β���
	srand(time(0));
	if (Head->data != -1)//ȷ�������Ƿ�Ϊ������
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
		p = (LinkList)malloc(sizeof(Node));//�����½��
		if (p == NULL)
		{
			printf("�����ڴ�ռ�ʧ�ܣ�\n");
			return ERROR;
		}
		p->data = rand() % 100 + 1;//�������100���ڵ���
		tail->next = p;//����β�ն˽���ָ��ָ���½��
		tail = p;//����ǰ���½�㶨��Ϊ��β�ն˽�� 
		Head->data++;//����һ
	}
	tail->next = NULL;//��ʾ��ǰ�������
	printf("�������ɹ���\n");
	return OK;
}
//���������ĳ���
void OutLength(LinkList Head)
{
	if (Head->data == -1)
	{
		printf("������Ϊ����������Ϊ0\n");
	}
	else
	{
		printf("��������Ϊ��%d\n", Head->data+1);
	}
}
//��ȡ��i��Ԫ�ص�����
Status GetElem(LinkList Head, int i, ElemType *e)
{
	LinkList p;		//����һ���p����ָ�������һ�����
	p = Head->next;	//�ý��pָ�������һ�����
	if (Head->data == -1 || i > Head->data + 1 || i < 1)
	{
		printf("��%d��Ԫ�ز����ڣ�\n",i);
		return ERROR;
	}
	for (int j = 0;j < i-1; ++j)
	{
		p = p->next;
	}
	*e = p->data;		//ȡ��i��Ԫ�ص�����
	return OK;
}
//�������Ԫ�ص�λ��
Status LocateElem(LinkList Head, int e)
{
	LinkList p;
	bool b = true;
	p = Head->next;	//�ý��pָ�������һ�����
	if (Head->data == -1)
	{
		printf("������Ϊ������Ԫ��%d�����ڣ�\n",e);
		return ERROR;
	}
	for (int i = 0; i < Head->data + 1; ++i)
	{
		if (p->data == e)
		{
			printf("Ԫ��%d�������λ��Ϊ��%d\n", e, i + 1);
			b = false;
		}
		p = p->next;
	}
	if (b)
	{
		printf("Ԫ��%d�����ڣ�\n", e);
	}
	return OK;
}
//�ڵ�i��Ԫ��ǰ�����������Ԫ��
Status InsertValue(LinkList Head)
{
	int t,n,e;
	LinkList p,k;
	p = Head;//�ý��pָ������ĵ�һ�����
	printf("����Ԫ��ǰ������һ��Ԫ��������1������Ԫ�غ������һ��Ԫ��������2��");
	scanf("%d", &t);
	if (t == 1)
	{
		printf("���ڵڼ���Ԫ��ǰ����Ԫ�أ�\n");
	}
	else if (t == 2)
	{
		printf("���ڵڼ���Ԫ�غ����Ԫ�أ�\n");
	}
	else
	{
		printf("��������ֲ�����Ҫ��\n");
		return ERROR;
	}
	fflush(stdin);
	scanf("%d", &n);
	if (n < 1 || n > Head->data + 1)
	{
		printf("�����λ�ò��Ϸ���\n");
		return ERROR;
	}
	fflush(stdin);
	printf("�����Ԫ�ص�ֵΪ��");
	scanf("%d", &e);
	k = (LinkList)malloc(sizeof(Node));
	if (k == NULL)
	{
		printf("Ϊ��Ԫ�������ڴ�ռ�ʧ�ܣ�����ʧ�ܣ�\n");
		return ERROR;
	}
	k->data = e;
	for (int i = 0; i < n - 1; ++i)
	{
		p = p->next;
	}
	//��ʱpΪָ��λ�õ�ǰһ��λ��
	if (t == 2)//Ϊ���ʱ pָ����һ�� Ҳ����ָ����λ��
	{
		p = p->next;
	}
	k->next = p->next;
	p->next = k;
	Head->data++;
	printf("����ɹ���\n");
	return OK;
}
//ɾ���������i��Ԫ��
Status DeleteValue(LinkList Head)
{
	LinkList p,k;
	int n,e;
	p = Head->next;
	printf("��Ҫɾ���ڼ���Ԫ�أ�\n");
	scanf("%d", &n);
	if (n <= 0 || n > Head->data + 1)
	{
		printf("ɾ����λ�ò��Ϸ���\n");
		return ERROR;
	}
	for (int i = 1; i < n - 1; ++i)
	{
		p = p->next;
	}
	//��ʱpΪҪɾ��Ԫ�ص�ǰһ��Ԫ�ص�λ��
	k = p->next;//kΪҪɾ����λ��
	p->next = k->next;
	e = k->data;
	free(k);//�ͷ�k��ռ�õĿռ� 
	Head->data--;
	return e;
}
//������������Ԫ��
Status Output(LinkList Head)
{
	LinkList p;
	p = Head->next;
	if (Head->data == -1)
	{
		printf("������Ϊ������û��Ԫ�ؿ������\n");
		return ERROR;
	}
	for (int i = 1; i <= Head->data + 1;++i)
	{
		printf("��%d��Ԫ�ص�ֵΪ��%d\n",i,p->data);
		p = p->next;
	}
	printf("����������Ԫ�������ϣ�\n");
	return OK;
}
//��յ�����
void ClearList(LinkList Head)
{
	LinkList p,k;
	p = Head->next;
	for (int i = 0; i < Head->data + 1; ++i)
	{
		Head->next = p->next;
		free(p);//�ͷ�p��ָ����ڴ�ռ�
		p = Head->next;
	}
	Head->next = NULL;
	Head->data = -1;
	printf("��������ճɹ���\n");
}
//�������Ƿ�Ϊ��
bool ListEmpty(LinkList Head)
{
	if (Head->next == NULL)
	{
		return false;
	}
	return true;
}
//�˵�����
void Menu()
{
	system("cls");//�����Ļ
	printf("\n");
	printf("\t\t-------------------��ӭʹ�õ�����Ļ�������----------------------\n");
	printf("\t\t|\t\t 1  ��ʼ��������                   \t\t|\n");
	printf("\t\t|\t\t 2  �������������               \t\t|\n");
	printf("\t\t|\t\t 3  ����������                     \t\t|\n");
	printf("\t\t|\t\t 4  ���������ĳ���               \t\t|\n");
	printf("\t\t|\t\t 5  ����������i��Ԫ��            \t\t|\n");
	printf("\t\t|\t\t 6  �������Ԫ�ص�λ��             \t\t|\n");
	printf("\t\t|\t\t 7  �ڵ�i��Ԫ��ǰ�����������Ԫ��\t\t|\n");
	printf("\t\t|\t\t 8  ɾ���������i��Ԫ��            \t\t|\n");
	printf("\t\t|\t\t 9  ������������Ԫ��             \t\t|\n");
	printf("\t\t|\t\t 10 ��յ�����                     \t\t|\n");
	printf("\t\t|\t\t 11 �������Ƿ�Ϊ��                 \t\t|\n");
	printf("\t\t|\t\t 12 �˳�ϵͳ                       \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t��ѡ��(1-12):");
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
		Menu();            //�����Ӻ��� 
		scanf("%d", &select);
		switch (select)
		{
		case 1: Head = InitList(); break;
		case 2: printf("����ͷ�巨ʵ��������������1������β�巨ʵ��������������2��");
				scanf("%d", &e);
				if (e != 1 && e != 2)
				{
					printf("��������ֲ�����Ҫ��\n");
				}
				else 
				{
					printf("Ҫ������Ԫ�صĸ���Ϊ��");
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
		case 3: printf("����ͷ�巨����������������1������β�巨����������������2��");
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
						printf("��������ֲ�����Ҫ��\n");
					}
				break;
		case 4: OutLength(Head); break;
		case 5: printf("����ڼ���Ԫ�أ�\n");
				scanf("%d", &n);
				if (GetElem(Head, n, &e))
				{
					printf("��%d��Ԫ�ص�ֵΪ��%d\n", n, e);
				}
				break;
		case 6: printf("������ĸ�Ԫ�ص�λ�ã�\n");
				scanf("%d", &e);
				LocateElem(Head, e);
				break;
		case 7: InsertValue(Head); break;
		case 8: e = DeleteValue(Head);
				if (e)
				{
					printf("ɾ���ɹ���ɾ����Ԫ�ص�ֵΪ��%d\n",e);
				}
				break;
		case 9: Output(Head); break;
		case 10: ClearList(Head); break;
		case 11:if (ListEmpty(Head))
				{
					printf("������Ϊ�գ�\n");
				}
				else
				{
					printf("������Ϊ�գ�\n");
				}
				break;
		case 12: quit = 1; break;
		default:printf("������1~12֮�������\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("��������������˵���\n");
		if (select != 3)
		{
			getchar();                //��ȡ���������еĻس���
		}
		getchar();                //����ͣ������
	}
	printf("���������\n");
	free(Head);
	return 0;
}
*/