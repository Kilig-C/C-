//#include<cstdio>
//#include<cstdlib>
/*
�������һ�������һ��Ԫ����Ϊ����Ԫ�ش����������ݡ�
����ͨ����δ��ʹ�õ�����Ԫ�س�Ϊ���������������һ��Ԫ�أ�
���±�Ϊ0��Ԫ�ص� cur �ʹ�ű�������ĵ�һ�������±ꣻ
����������һ��Ԫ�ص�cur���ŵ�һ������ֵ��Ԫ�ص��±꣬
�൱�ھ�̬�����е�ͷ������ã�����������Ϊ��ʱ����Ϊ0��
*/
/*
#define MAXSIZE 1024 //�����������󳤶���1024
#define OK 1
#define ERROR 0
typedef int ElemType; //Ҳ���൱�ڸ�int�����  ��������Ϊ�˷����޸Ĵ����ľ�̬�����Ԫ������
typedef int Status; //�����Ӻ����������� 
//���Ա�ľ�̬����洢�ṹ 
typedef struct
{
	ElemType data; //�����洢����Ԫ�� 
	int cur; //���������һ��Ԫ�ص��±꣬�൱�ھ�̬������ָ������� 
}Component, StaticLinkList[MAXSIZE];

//��̬�����ʼ��
//��һά����space�и�����������һ��������
//space[0].curΪͷָ�룬"0"��ʾΪ��ָ�� 
Status InitList(StaticLinkList space)
{
	int i;
	for (int i = 0; i<MAXSIZE - 1; ++i)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 2].cur = -1;
	space[MAXSIZE - 1].cur = -1;//Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�cur��ŵ�һ��������Ԫ�ص��±꣬��ʱΪ0
	return OK;
}
//���������
int ListLenght(StaticLinkList L)
{
	int i = L[MAXSIZE - 1].cur;//���һ��Ԫ���൱�������ͷָ�룬��������
	int j = -1;//������¼��ʹ�õ����鳤��
	while (i != -1)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
//ģ��malloc����
//�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
int Malloc_SLL(StaticLinkList space)
{
	//��ǰ�����һ��Ԫ�ص�cur���ֵ������Ҫ���صı��ÿ���Ԫ�ص��±�
	int i = space[0].cur;
	if (space[0].cur != -1)
	{
		space[0].cur = space[i].cur;
		space[i].cur = -1;
		//����Ҫ��space[i]�������ʹ���ˣ�����space[i].curҲ������һ��������Ϊ��һ������Ԫ��
		return i;
	}
	else
	{
		return ERROR;
	}
}
//ģ��free����
//��ɾ����ʹ�õĿ��н����յ���������
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;//�ѵ�һ������Ԫ�ص�cur��ֵ��Ҫɾ����Ԫ�ص�cur
	space[0].cur = k;//��Ҫɾ���ķ������±긳ֵ�������һ��Ԫ�ص�cur
	//�൱�ڽ���ʹ�õĽ����뵽��������ĵ�һ��Ԫ�ص�ǰ�棬����data���ô���ʹ��ʱ�µ���ֵ�Ḳ����
}
//ͷ���β�巨 ��������
Status ListInsertHT(StaticLinkList L)
{
	int i, j, t, n = 0;
	Status e;//��ʱ����Ҫ�����Ԫ�ص�ֵ
	printf("����ͷ�巨��������������1������β�巨��������������2��");
	scanf("%d", &t);
	if (t != 1 && t != 2)
	{
		printf("��������ֲ�����Ҫ��\n");
		return ERROR;
	}
	fflush(stdin);
	printf("������Ҫ�����Ԫ��(�������һ��Ԫ��֮����ֱ�ӻ���)��");
	while (1)
	{
		scanf("%d", &e);
		i = Malloc_SLL(L);
		if (i)//iΪ0�Ļ�˵���Ѿ�û�п��з�����
		{
			L[i].data = e;//��Ҫ��������ݸ�ֵ���˷�����data
			if (t == 1)//ͷ��
			{
				L[i].cur = L[MAXSIZE - 1].cur;
				L[MAXSIZE - 1].cur = i;
			}
			else //β��
			{
				if (n == 0)
				{
					n = 1;
					for (j = MAXSIZE - 1; L[j].cur != -1; j = L[j].cur);//�������һ������curΪ-1
				}
				//��ʱjΪ���һ�������±�
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
			printf("�ڴ�������\n");
			return ERROR;
		}
	}
	printf("������ϣ�\n");
	return OK;
}
//�������
//��L�е�n��Ԫ��ǰ�����µ�Ԫ��e
Status ListInsert(StaticLinkList L)
{
	int n, e;
	int j, k;
	k = MAXSIZE - 1;//ע��k���������һ��Ԫ�ص��±�
	printf("��Ҫ�ڵڼ���Ԫ��ǰ����Ԫ�أ�\n");
	scanf("%d", &n);
	if (n<1 || n>ListLenght(L) + 1)
	{
		printf("�����λ�ò��Ϸ���\n");
		return ERROR;
	}
	printf("������Ҫ�����Ԫ�ص�ֵ��");
	scanf("%d", &e);
	j = Malloc_SLL(L);//��ȡ���з������±�
	if (j)//jΪ0�Ļ�˵���Ѿ�û�п��з�����
	{
		L[j].data = e;//��Ҫ��������ݸ�ֵ���˷�����data
		//k�ӵ�һ��Ԫ�ص��±굽Ҫ����Ԫ�ص�ǰһ��Ԫ�� 
		for (int i = 1; i <= n - 1; ++i)
		{
			k = L[k].cur;
		}
		//����ڵ�n��Ԫ��ǰ����Ԫ�أ���ʱk��ֵΪ�ڵ�n-1��Ԫ�ص��±�
		L[j].cur = L[k].cur;//�ѵ�n��Ԫ�ص��±긳ֵ���µ�Ԫ�ص�cur
		//��ʱ�²����Ԫ��ָ���n��Ԫ��
		L[k].cur = j;//����Ԫ�ص��±긳ֵ��ԭ����nԪ��ǰ��Ԫ�ص�cur
		return OK;
	}
	printf("�ڴ��ѷ��������޷�������Ԫ�أ�\n");
	return ERROR;
}
//ɾ������
//ɾ����L�еĵ�n��Ԫ��e
Status ListDelete(StaticLinkList L)
{
	int n;//ɾ��Ԫ�ص�λ��
	int k, t;
	printf("��Ҫɾ���ڼ���Ԫ�أ�\n");
	scanf("%d", &n);
	if (n<1 || n>ListLenght(L));
	{
		printf("�����λ�ò��Ϸ���\n");
		return ERROR;
	}
	k = MAXSIZE - 1;//��ʱkΪͷ����λ��
	for (int i = 1; i <= n - 1; ++i)
	{
		k = L[k].cur;
	}
	//��ʱkΪҪɾ��Ԫ�ص�ǰһ��Ԫ�ص�λ��
	t = L[k].cur;//tΪҪɾ��Ԫ�ص��±�
	L[k].cur = L[t].cur; //��Ҫɾ��Ԫ�ص�cur�е�ֵ��ֵ��Ҫɾ��Ԫ��ǰһ��Ԫ�ص�cur
	Free_SLL(L, k);//��ɾ���Ľ����յ���������
	return OK;
}
//���ָ��λ�õ�Ԫ��
Status GetElem(StaticLinkList L, int n, int *e)
{
	int k = L[MAXSIZE - 1].cur;//��ʱk��ͷ���λ��
	for (int i = 0; i < n-1; ++i)
	{
		k = L[k].cur;
	}
	*e = L[k].data;
	return OK;
}
//�������Ԫ�ص�λ��
Status LocateElem(StaticLinkList L, int e)
{
	int k = L[MAXSIZE - 1].cur;
	bool b = true;
	if (ListLenght(L) < 0)
	{
		printf("��̬����Ϊ������Ԫ��%d�����ڣ�\n", e);
		return ERROR;
	}
	for (int i = 0; i < ListLenght(L)+1; ++i)
	{
		if (L[k].data == e)
		{
			printf("Ԫ��%d�������λ��Ϊ��%d\n", e, i + 1);
			b = false;
		}
		k = L[k].cur;
	}
	if (b)
	{
		printf("Ԫ��%d�����ڣ�\n", e);
	}
	return OK;
}
//�ڵ�i��Ԫ��ǰ���������Ԫ��
Status InsertValue(StaticLinkList L)
{
	int t, n, e;
	int k = MAXSIZE - 1;
	printf("���ڵڼ���Ԫ��ǰ����Ԫ�أ�\n");
	scanf("%d", &n);
	if (n < 1 || n > ListLenght(L) + 1)
	{
		printf("�����λ�ò��Ϸ���\n");
		return ERROR;
	}
	printf("�����Ԫ�ص�ֵΪ��");
	scanf("%d", &e);
	t = Malloc_SLL(L);
	if (t == 0)
	{
		printf("Ϊ��Ԫ�������ڴ�ռ�ʧ�ܣ�����ʧ�ܣ�\n");
		return ERROR;
	}
	L[t].data = e;
	for (int i = 0; i < n - 1; ++i)
	{
		k = L[k].cur;
	}
	//��ʱkΪָ��λ�õ�ǰһ��λ��
	L[t].cur = L[k].cur;
	L[k].cur = t;
	printf("����ɹ���\n");
	return OK;
}
//ɾ���������i��Ԫ��
Status DeleteValue(StaticLinkList L)
{
	int k = MAXSIZE - 1;
	int n, e, t;
	printf("��Ҫɾ���ڼ���Ԫ�أ�\n");
	scanf("%d", &n);
	if (n <= 0 || n > ListLenght(L) + 1)
	{
		printf("ɾ����λ�ò��Ϸ���\n");
		return ERROR;
	}
	for (int i = 1; i < n - 1; ++i)
	{
		k = L[k].cur;
	}
	//��ʱkΪҪɾ��Ԫ�ص�ǰһ��Ԫ�ص�λ��
	t = L[k].cur;//tΪҪɾ����λ��
	L[k].cur = L[t].cur;
	e = L[t].data;
	Free_SLL(L, t);//�ͷ�t��ռ�õĿռ� 
	return e;
}
//������������Ԫ��
Status Output(StaticLinkList L)
{
	int p = L[MAXSIZE - 1].cur;
	if (ListLenght(L) == -1)
	{
		printf("������Ϊ������û��Ԫ�ؿ������\n");
		return ERROR;
	}
	for (int i = 1; i <= ListLenght(L) + 1; ++i)
	{
		printf("��%d��Ԫ�ص�ֵΪ��%d\n", i, L[p].data);
		p = L[p].cur;
	}
	printf("����������Ԫ�������ϣ�\n");
	return OK;
}
//�˵�����
void Menu()
{
	system("cls");//�����Ļ
	printf("\n");
	printf("\t\t-------------------��ӭʹ�þ�̬����Ļ�������----------------------\n");
	printf("\t\t|\t\t 1  ��ʼ����̬����                   \t\t|\n");
	printf("\t\t|\t\t 2  ������̬����                     \t\t|\n");
	printf("\t\t|\t\t 3  �����̬����ĳ���               \t\t|\n");
	printf("\t\t|\t\t 4  �����̬�����i��Ԫ��            \t\t|\n");
	printf("\t\t|\t\t 5  �������Ԫ�ص�λ��               \t\t|\n");
	printf("\t\t|\t\t 6  �ڵ�i��Ԫ��ǰ���������Ԫ��      \t\t|\n");
	printf("\t\t|\t\t 7  ɾ����̬�����i��Ԫ��            \t\t|\n");
	printf("\t\t|\t\t 8  �����̬�������Ԫ��             \t\t|\n");
	printf("\t\t|\t\t 9  ��վ�̬����                     \t\t|\n");
	printf("\t\t|\t\t 10 ��̬�����Ƿ�Ϊ��                 \t\t|\n");
	printf("\t\t|\t\t 11 �˳�ϵͳ                         \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t��ѡ��(1-11):");
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
		Menu();            //�����Ӻ��� 
		scanf("%d", &select);
		switch (select)
		{
		case 1: InitList(L); 
				printf("��ʼ���ɹ���\n");
				break;
		case 2: ListInsertHT(L);break;
		case 3: printf("������Ϊ��%d\n", ListLenght(L) + 1);
				break;
		case 4: printf("����ڼ���Ԫ�أ�\n");
				scanf("%d", &n);
				if (n<1 || n>ListLenght(L) + 1)
				{
					printf("�����Ԫ�ص�λ�ò��Ϸ���\n");
					break;
				}
				if (GetElem(L, n, &e))
				{
					printf("��%d��Ԫ�ص�ֵΪ��%d\n", n, e);
				}
				break;
		case 5: printf("������ĸ�Ԫ�ص�λ�ã�\n");
				scanf("%d", &e);
				LocateElem(L, e);
				break;
		case 6: InsertValue(L); break;
		case 7: e = DeleteValue(L);
				if (e)
				{
					printf("ɾ���ɹ���ɾ����Ԫ�ص�ֵΪ��%d\n", e);
				}
				break;
		case 8: Output(L); break;
		case 9: InitList(L); 
				printf("�������ɹ���\n");
				break;
		case 10:if (ListLenght(L) + 1)
				{
					printf("��̬����Ϊ�գ�\n");
				}
				else
				{
					printf("��̬����Ϊ�գ�\n");
				}
				break;
		case 11: quit = 1; break;
		default:printf("������1~11֮�������\n"); break;
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
/*
ADT ջ��stack��
Data
ͬ���Ա�Ԫ�ؾ�����ͬ�����ͣ�����Ԫ�ؾ���ǰ���ͺ�̹�ϵ��
Operation
InitStack(*S) : ��ʼ������������һ����ջS��
DestoryStack(*S) : ��ջ���ڣ�����������
ClearStack(*S) : ��ջ��ա�
StackEmpty(S) : ��ջΪ�գ�����true�����򷵻�false��
GetTop(S, *e) : ��ջ�����ҷǿգ���e����S��ջ��Ԫ�ء�
Push(*S, e) : ��ջS���ڣ�������Ԫ��e��ջS�в���Ϊջ��Ԫ�ء�
Pop(*S, *e) : ɾ��ջS�е�ջ��Ԫ�أ�����e������ֵ��
StackLength(S) : ����ջS��Ԫ�ظ�����
endADT
*/
#include<cstdio>
#include<cstdlib>

#define OK    1
#define ERROR 0
#define MAXSIZE 1024
typedef int Status;
typedef int SElemType;	//SElemtype ���͸���ʵ������������������Ϊint

typedef struct SqStack
{
	SElemType data[MAXSIZE];
	int top;		//����ջ��ָ��
}SqStack;
//��ʼ��ջ
void InitStack(SqStack *S)
{
	S = (SqStack *)malloc(sizeof(SqStack));
	if (S == NULL) //�ж������ڴ�ռ��Ƿ�ɹ� ʧ��ֵΪNULL �ɹ���֮
	{
		printf("�����ڴ�ռ�ʧ�ܣ���ʼ��ʧ�ܣ�\n");
	}
	else
	{
		S->top = -1;//��˳��ջ��ջ����Ϊ-1����ʾջΪ��ջ
		printf("��ʼ���ɹ���\n");
	}
}
//����ջ
void CreateStack(SqStack *S)
{
	printf("������Ԫ�أ��������һ��Ԫ�غ���ֱ�ӻ��У���");
	for (int i = S->top + 1; i < MAXSIZE; ++i)//iֵС��������󳤶�MAXSIZE
	{
		scanf("%d", &S->data[i]);
		if (getchar() == '\n')//��������˵��Ԫ�ض��Ѿ�¼����ϣ�����ѭ������������
		{
			break;
		}
		S->top++;
	}
	printf("������ϣ�\n");
}
//���ջ��Ԫ�ظ���
void LengthStack(SqStack *S)
{
	if (S->top == -1)
	{
		printf("ջΪ��ջ��Ԫ�ظ���Ϊ0\n");
	}
	else
	{
		printf("ջ��Ԫ�ظ���Ϊ��%d\n", S->top + 1);
	}
}
//���ջ��Ԫ��
void OutTop(SqStack *S)
{
	if (S->top == -1)
	{
		printf("ջΪ��ջ��û��ջ��Ԫ�أ�\n");
	}
	else
	{
		printf("ջ��Ԫ��Ϊ��%d\n", S->data[S->top]);
	}
}
//��ջ����
//����Ԫ��e��ջ��
Status Push(SqStack *S, SElemType e)
{
	if (S->top >= MAXSIZE - 1)
	{
		printf("ջ����,����Ԫ��ʧ�ܣ�\n");
		return ERROR;
	}
	else
	{
		S->top++;
		S->data[S->top] = e;
		printf("����Ԫ�سɹ���\n");
		return OK;
	}
}
//��ջ����pop
//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
	{
		printf("ջΪ��ջ��û��ջ��Ԫ�ؿ�ɾ����\n");
		return ERROR;
	}
	*e = S->data[S->top];	//��Ҫɾ����ջ��Ԫ�ظ�ֵ��e
	S->top--;	//ջ��ָ���һ
	return OK;
}
//���˳��ջ����Ԫ��
void OutValue(SqStack *S)
{
	printf("ջ�еĸ���Ԫ��Ϊ��");
	for (int i = 0; i < S->top + 1; ++i)//��ջ��Ԫ�ؿ�ʼ���
	{
		printf("%d ", S->data[i]);
	}
	printf("\n����%dΪջ��Ԫ��\n", S->data[S->top]);
}
//���˳��ջ
void ClearStack(SqStack *S)
{
	if (S->top == -1)
	{
		printf("ջΪ��ջ�������ظ�ִ�д˲�����\n");
	}
	else
	{
		S->top == -1;
		printf("���ջ�ɹ���\n");
	}
}
//˳��ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack *S)
{
	if (S->top == -1)
	{
		return true;
	}
	return false;

}
//�˵�����
void Menu()
{
	system("cls"); //�����Ļ
	printf("\n");
	printf("\t\t-------------------��ӭʹ��˳��ջ�Ļ�������----------------------\n");
	printf("\t\t|\t\t 1  ��ʼ��˳��ջ                   \t\t|\n");
	printf("\t\t|\t\t 2  ����˳��ջ                     \t\t|\n");
	printf("\t\t|\t\t 3  ���˳��ջ��Ԫ�ظ���           \t\t|\n");
	printf("\t\t|\t\t 4  ���˳��ջջ��Ԫ��             \t\t|\n");
	printf("\t\t|\t\t 5  ����ָ��Ԫ�ص�ջ��             \t\t|\n");
	printf("\t\t|\t\t 6  ɾ��ջ��Ԫ��                   \t\t|\n");
	printf("\t\t|\t\t 7  ���˳��ջ����Ԫ��             \t\t|\n");
	printf("\t\t|\t\t 8  ���˳��ջ                     \t\t|\n");
	printf("\t\t|\t\t 9  ˳��ջ�Ƿ�Ϊ��                 \t\t|\n");
	printf("\t\t|\t\t 10 �˳�ϵͳ                       \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t��ѡ��(1-10):");
}
int main()
{
	SqStack *S;
	int quit = 0;
	int select;
	SElemType e;
	while (1)
	{
		Menu(); //���ò˵�����
		scanf("%d", &select);
		switch (select)
		{
		case 1: InitStack(S); break; //��ʼ��˳��ջ
		case 2: CreateStack(S); break; //����˳��ջ
		case 3: LengthStack(S); break; //���˳��ջ��Ԫ�ظ���
		case 4: OutTop(S); break; //���˳��ջջ��Ԫ��
		case 5: //����ָ��Ԫ�ص�ջ��
			printf("Ҫ�����Ԫ�ص�ֵΪ��");
			scanf("%d", &e);
			Push(S, e);
			break;
		case 6: //ɾ��ջ��Ԫ��
			if (Pop(S, &e))
			{
				printf("ɾ���ɹ���ɾ����ջ��Ԫ�ص�ֵΪ��%d", e);
			}
			break;
		case 7: OutValue(S); break; //���˳��ջ����Ԫ��
		case 8: ClearStack(S); break; //���˳��ջ
		case 9: //˳��ջ�Ƿ�Ϊ��
			if (StackEmpty(S))
			{
				printf("ջΪ��ջ��\n");
			}
			else
			{
				printf("ջ��Ϊ�գ�\n");
			}
			break;
		case 10: quit = 1; break;//�˳�ϵͳ
		default:printf("������1-10֮�������\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("��������������˵���\n");
		if (select != 2)
		{
			getchar(); //��ȡ�������еĻس���
		}
		getchar(); //����ͣ������
	}
	free(S);//�ͷ�S
	printf("���������\n");
	return 0;
}
