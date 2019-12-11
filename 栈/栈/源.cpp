/*
#include<cstdio>
#include<cstdlib>

#define OK    1
#define ERROR 0
#define MAXSIZE 1024
typedef int Status;
typedef int SElemType;	//SElemtype ���͸���ʵ������������������Ϊint

typedef struct 
{
	SElemType data[MAXSIZE];
	int top;		//����ջ��ָ��
}SqStack;
/*
//=========================
#define OK    1
#define ERROR 0
typedef int Status;
#define MAXSIZE 1024
typedef int SElemType;
//��ջ����ռ�ṹ
typedef struct
{
	SElemType data[MAXSIZE];
	int top1; //ջ1ջ��ָ��
	int top2; //ջ2ջ��ָ��
}SqDoubleStack;
//����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqDoubleStack *S, int e,int StackNumber)
{
	if (S->top1 + 1 == S->top2) //ջ������������push��Ԫ����
	{
		return ERROR;
	}
	if (StackNumber == 1)//ջ1��Ԫ�ؽ�ջ
	{
		S->data[++S->top1] = e; //��ջ1����top1+1�������Ԫ�ظ�ֵ
	}
	if (StackNumber == 2) //ջ2��Ԫ�ؽ�ջ
	{
		S->data[--S->top2] = e; //��ջ2����top2-1�������Ԫ�ظ�ֵ
	}
	return OK;
}
//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status Pop(SqDoubleStack *S, SElemType *e, int StackNumber)
{
	if (StackNumber == 1)
	{
		if (S->top1 == -1)
		{
			return ERROR; //˵��ջ1�Ѿ��ǿ�ջ�����
		}
		*e = S->data[S->top1--]; //��ջ1��ջ��Ԫ�س�ջ
	}
	else if (StackNumber == 2)
	{
		if (S->top2 == MAXSIZE)
		{
			return ERROR; //˵��ջ2�Ѿ��ǿ�ջ�����
		}
		*e = S->data[S->top2++]; //��ջ2��ջ��Ԫ�س�ջ
	}
	return OK;
}

//=============================

//��ʼ��ջ
void InitStack(SqStack **S)
{
	*S = (SqStack *)malloc(sizeof(SqStack));
	if (S == NULL) //�ж������ڴ�ռ��Ƿ�ɹ� ʧ��ֵΪNULL �ɹ���֮
	{
		printf("�����ڴ�ռ�ʧ�ܣ���ʼ��ʧ�ܣ�\n");
	}
	else
	{
		(*S)->top = -1;//��˳��ջ��ջ����Ϊ-1����ʾջΪ��ջ
		printf("��ʼ���ɹ���\n");
	}
}
//����ջ
void CreateStack(SqStack *S)
{
	printf("������Ԫ�أ��������һ��Ԫ�غ���ֱ�ӻ��У���");
	for (int i = S->top+1; i < MAXSIZE; ++i)//iֵС��������󳤶�MAXSIZE
	{
		scanf("%d", &S->data[i]);
		S->top++;
		if (getchar() == '\n')//��������˵��Ԫ�ض��Ѿ�¼����ϣ�����ѭ������������
		{
			break;
		}
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
	*e = S->data[S -> top];	//��Ҫɾ����ջ��Ԫ�ظ�ֵ��e
	S->top--;	//ջ��ָ���һ
	return OK;
}
//���˳��ջ����Ԫ��
void OutValue(SqStack *S)
{
	if (S->top != -1)
	{
		printf("ջ�еĸ���Ԫ��Ϊ��");
		for (int i = 0; i < S->top + 1; ++i)//��ջ��Ԫ�ؿ�ʼ���
		{
			printf("%d ", S->data[i]);
		}
		printf("\n����%dΪջ��Ԫ��\n", S->data[S->top]);
	}
	else
	{
		printf("ջΪ��ջ��û��Ԫ�أ�\n");
	}
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
		S->top = -1;
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
		case 1: InitStack(&S); break; //��ʼ��˳��ջ
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
				printf("ɾ���ɹ���\nɾ����ջ��Ԫ�ص�ֵΪ��%d\n", e);
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
*/