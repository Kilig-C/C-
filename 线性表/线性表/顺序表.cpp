//֮ǰ�İ汾
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 1024
typedef int elemtype;
typedef struct sequlist
{
	elemtype data[maxsize];   //����˳���Ϊһά����
	int last;   //lastΪ���һ������Ԫ�ص��±�λ��
}SequenList;

//1 ��ʼ���ַ���˳���L
SequenList * lnit_SequenList()
{
	SequenList *L;//����˳���ָ�����
	L = (SequenList *)malloc(sizeof(SequenList));/*��������ڴ�ռ�*/
	if (L != NULL)         /*��������ڴ�ռ�ɹ�*/
	{
		L->last = -1;      /*����˳���ĳ���lastΪ-1����ʾ˳���Ϊ��*/
		printf("��ʼ���ɹ���\n");
	}
	else
	{
		printf("����˳����ڴ�ռ�ʧ�ܣ����������\n");
		return 0;
	}
	return L;       //����˳�����׵�ַ
}

/*2 ����˳���L */
SequenList *indata_SeqList(SequenList *L)
{
	elemtype x;
	printf("������Ԫ��(��ֹ����������0����)��");
	scanf("%d", &x);
	while (x != 0)
	{
		L->last += 1;
		L->data[L->last] = x;
		scanf("%d", &x);
	}
	printf("˳������ɹ���\n");
	return L;
}

/*3 ���˳���L�ĳ���*/
int SequenList_Length(SequenList *L)
{
	printf("˳���ĳ���Ϊ��%d\n", L->last + 1);
	return 0;
}

/* 4 ���˳���L�ĵ�i��Ԫ��*/
int input_SequenList(SequenList *L)
{
	int i, j = 0;
	int key;
	printf("Ҫ�����Ԫ��Ϊ�ڼ�����\n");
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
		printf("���������Ԫ��λ�ò��Ϸ���\n");
	}
	return 0;
}
/* 5 �������Ԫ�ص�λ��  */
int Search_SequenList(SequenList *L)
{
	int i, j = 0;
	int key;
	printf("������Ԫ�أ�");
	scanf("%d", &key);
	for (i = 0; i <= L->last; i++)
	{
		if (L->data[i] == key)
		{
			printf("Ԫ��λ��Ϊ��%d\n", i + 1);
			j = 1;
			//return (i + 1);
		}
		/*else
		{
		printf("����ʧ��");
		}*/
	}
	if (j == 0)
	{
		printf("����ʧ��");
	}
	return 0;
}

/* 6 �ڵ�i��Ԫ��ǰ�������Ԫ��*/
int lnsert_SequenList(SequenList *L)
/*��˳���L�е�i������Ԫ��֮ǰ����һ��Ԫ��x,����ǰ��n=L->last+1,
i�ĺϷ�ȡֵ��Χ�� 1<=i<=L->last+2*/
{
	int j;
	int i, x;
	printf("���ڵڼ���Ԫ��ǰ����Ԫ�أ�\n");
	scanf("%d", &i);
	printf("�����Ԫ��Ϊ��");
	scanf("%d", &x);
	if (L->last >= maxsize - 1)
	{
		printf("�������޷�����!\n");
		return 0;
	}
	if ((i<1) || (i>L->last + 2))
	{
		printf("����λ��iֵ���Ϸ�!\n");
		return -1;
	}
	/*Ϊ����Ԫ�ض��ƶ�λ��*/
	for (j = L->last; j >= i - 1; j--)
	{
		L->data[j + 1] = L->data[j];
	}
	L->data[i - 1] = x;     /*��i��Ԫ���±�Ϊi-1*/
	L->last = L->last + 1;
	printf("����ɹ���\n");
	return 0;
}

/*7 ɾ��˳���ĵ�i��Ԫ��*/
int Delete_SequenList(SequenList *L)
/*��˳�����ɾ����i��Ԫ�أ�����ָ�����e������ֵ��
i�ĺϷ�ȡֵ��ΧΪ1<=i<=L.last+1*/
{
	int k;
	int i;
	printf("Ҫɾ���ڼ���Ԫ�أ�");
	scanf("%d", &i);
	if ((i<1) || (i>L->last + 1))
	{
		printf("ɾ��λ�ò��Ϸ�");
	}
	else
	{
		for (k = i; k <= L->last; k++)
		{
			L->data[k - 1] = L->data[k];//���ǰ��
		}
		L->last--;//����һ
		printf("ɾ���ɹ�!\n");
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
//�˵�
void menu()
{
	system("cls");
	printf("\n");
	printf("\t\t---------------��ӭʹ��˳���Ļ�������------------------\n");
	printf("\t\t|\t\t a ��ʼ��˳���               \t\t|\n");
	printf("\t\t|\t\t b ����˳���                 \t\t|\n");
	printf("\t\t|\t\t c ���˳���ĳ���           \t\t|\n");
	printf("\t\t|\t\t d ���˳����i��Ԫ��        \t\t|\n");
	printf("\t\t|\t\t e �������Ԫ�ص�λ��         \t\t|\n");
	printf("\t\t|\t\t f �ڵ�i��Ԫ��ǰ���������Ԫ��\t\t|\n");
	printf("\t\t|\t\t g ɾ��˳����i��Ԫ��        \t\t|\n");
	printf("\t\t|\t\t h ���˳������Ԫ��         \t\t|\n");
	printf("\t\t|\t\t i �˳�ϵͳ                   \t\t|\n");
	printf("\t\t---------------------------------------------------------\n");
	printf("\t\t��ѡ��(a-g):");
}

int main1()
{
	SequenList *L;
	int  quit = 0;
	elemtype *e = 0;
	char select;
	while (1)
	{
		menu();            //�����Ӻ���
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
		default:printf("������a~i֮�������\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("��������������˵���\n");
		getchar();                //��ȡ���������еĻس���
		getchar();                //����ͣ������
		printf("���������\n");
	}
	return 0;
}