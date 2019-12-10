//˳�������
/*
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define MAXSIZE 1024 //����������󳤶�
typedef int Elemtype; //��������Ԫ������

//�ṹ�嶨��
typedef struct
{
	Elemtype Data[MAXSIZE];		//����˳���Ϊһά����
	int Last;					//LastΪ���һ������Ԫ�ص�λ��
}SqList;

//��ʼ������������һ���յ����Ա�L
SqList *InitList()
{
	SqList *L;
	L = (SqList *)malloc(sizeof(SqList));//��������ڴ�ռ�
	if (L != NULL)//��������ڴ�ռ�ɹ�
	{
		L->Last = -1;//����˳���ĳ���LastΪ-1����ʾ˳���Ϊ��
		printf("��ʼ���ɹ���\n");//�����ʾ��
	}
	else
	{
		printf("�����ڴ�ռ�ʧ�ܣ�\n");//�����ʾ��
	}
	return L;
}
//����˳���
void CreateList(SqList *L)
{
	printf("������Ԫ�أ����н������룬���һ��Ԫ�غ����벻Ҫ��ո񣩣�");
	for (int i = L->Last + 1; i < MAXSIZE; ++i)
	{
		scanf("%d", &L->Data[i]);
		L->Last++;
		if (getchar() == '\n')
		{
			break;
		}
	}
	printf("˳������ɹ���\n");//�����ʾ��
}
//���˳�����
void ListLength(SqList *L)
{
	printf("˳�����Ϊ %d\n", L->Last+1);//����ʵ�ʳ���ΪLast���ȼ�1
}
//���˳������Ԫ��
void Output(SqList *L)
{
	for (int i = 0; i < L->Last+1; ++i)
	{
		printf("Data[%d] = %d\n", i, L->Data[i]);
	}
}
//��˳���L�еĵ� i ��λ��Ԫ��ֵ���ظ�e
int GetElem(SqList *L, int i, int *e)
{
	if (0>i || i > L->Last + 1)
	{
		printf("�����λ�ò��Ϸ���\n");
		return -1;
	}
	else
	{
		*e = L->Data[i-1];
		return i;
	}
}
// ��˳���L�в��������ֵe��ȵ�Ԫ�أ�������ҳɹ������ظ�Ԫ���ڱ�����ű�ʾ�ɹ������򣬷���0��ʾʧ����
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
//��˳���L�еĵ�i��λ�ò�����Ԫ��e
void Listlnsert(SqList *L, int i, int e)
{
	if (i < 1 || i > L->Last+2)
	{
		printf("����λ�ò��Ϸ���\n");
	}
	else if (L->Last >= MAXSIZE-1)
	{
		printf("˳����������޷����룡\n");
	}
	else
	{
		for (int j = L->Last; j >= i-1; --j)
		{
			L->Data[j + 1] = L->Data[j];
		}
		L->Data[i-1] = e;
		L->Last++;
		printf("����ɹ���\n");
	}
}
//ɾ��˳���L�е�i��λ��Ԫ�أ�����e������ֵ��
int ListDelete(SqList *L, int i, int *e)
{
	if (i <= 0 || i > L->Last + 1)
	{
		printf("�����λ�ò��Ϸ���\n");
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
//��˳������
void ClearList(SqList *L)
{
	if (L->Last >=0)
	{
		memset(L->Data, NULL, L->Last);//������ָ��λ�õ�Ԫ�ظ���Ϊָ����ֵ
		L->Last = -1;
		printf("˳�����ճɹ���\n");
	}
	else
	{
		printf("˳����Ѿ���ճɹ����벻Ҫ�ظ���գ�\n");
	}

}
//��˳���Ϊ�գ�����true�����򷵻�false
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
//�˵�����
void Menu()
{
	system("cls");//�����Ļ
	printf("\n");
	printf("\t\t---------------��ӭʹ��˳���Ļ�������------------------\n");
	printf("\t\t|\t\t 1  ��ʼ��˳���               \t\t|\n");
	printf("\t\t|\t\t 2  ����˳���                 \t\t|\n");
	printf("\t\t|\t\t 3  ���˳���ĳ���           \t\t|\n");
	printf("\t\t|\t\t 4  ���˳����i��Ԫ��        \t\t|\n");
	printf("\t\t|\t\t 5  �������Ԫ�ص�λ��         \t\t|\n");
	printf("\t\t|\t\t 6  �ڵ�i��Ԫ��ǰ���������Ԫ��\t\t|\n");
	printf("\t\t|\t\t 7  ɾ��˳����i��Ԫ��        \t\t|\n");
	printf("\t\t|\t\t 8  ���˳������Ԫ��         \t\t|\n");
	printf("\t\t|\t\t 9  ���˳���                 \t\t|\n");
	printf("\t\t|\t\t 10 ˳����Ƿ�Ϊ��             \t\t|\n");
	printf("\t\t|\t\t 11 �˳�ϵͳ                   \t\t|\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t��ѡ��(1-9):");
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
		Menu();            //�����Ӻ��� 
		scanf("%d", &select);
		switch (select)
		{
		case 1: L = InitList(); break;
		case 2: CreateList(L); break;
		case 3: ListLength(L); break;
		case 4: printf("����ڼ���Ԫ�أ�\n");
				scanf("%d", &n);
				n = GetElem(L, n, &e);
				if (n != -1)
				{
					printf("��%d��Ԫ�ص�ֵΪ��%d\n", n, e);
				}
				break;
		case 5: printf("����Ǹ�Ԫ�ص�λ�ã�\n");
				scanf("%d", &e);
				n = LocateElem(L, e);
				if (n != 0)
				{
					printf("��Ԫ�ص�λ��Ϊ��%d\n", n+1);
				}
				else
				{
					printf("��������û�и�Ԫ�أ�\n");
				}
				break;
		case 6: printf("�����Ԫ��Ϊ��");
				scanf("%d", &e);
				printf("����Ԫ�ص�λ��Ϊ��");
				scanf("%d", &n);
				Listlnsert(L,n,e); break;
		case 7: printf("Ҫɾ���ĵ�Ԫ�ص�λ��Ϊ��");
				scanf("%d", &n);
				if (ListDelete(L, n, &e))
				{
					printf("ɾ���ɹ���ɾ����Ԫ�ص�ֵΪ��%d\n", e);
				}
				 break;
		case 8: Output(L); break;		
		case 9: ClearList(L); break;
		case 10:if (ListEmpty(L))
				{
					printf("˳���Ϊ�գ�\n");
				}
				else
				{
					printf("˳���Ϊ�գ�\n");
				}
				break;
		case 11: quit = 1; break;
		default:printf("������1~9֮�������\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("��������������˵���\n");
		if (select != 2)
		{
			getchar();                //��ȡ���������еĻس���
		}
		getchar();                //����ͣ������
	}
	printf("���������\n");
	return 0;
}

*/