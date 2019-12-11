/*
#include<cstdio>
#include<cstdlib>

#define OK 1
#define ERROR 0
typedef int SElemType; //����ʵ���������
typedef int Status; //����ʵ���������
//��ջ���ṹ
typedef struct StackNode
{
	SElemType data; //���������
	struct StackNode *next; //���ָ����ָ����һ�����
}StackNode,*LinkStackPtr;
//��ջջ���ṹ
typedef struct 
{
	LinkStackPtr top; //ָ����ջջ��Ԫ��
	int count; //��¼��ջ�ĳ���
}LinkStack;

//��ʼ����ջ
Status InitLinkStack(LinkStack **S)
{
	*S = (LinkStack*)malloc(sizeof(LinkStack)); //�����ڴ�ռ�
	if ((*S) == NULL) //�ж������ڴ�ռ��Ƿ�ɹ�
	{
		printf("�����ڴ�ռ�ʧ�ܣ���ʼ��ʧ�ܣ�\n"); //�����ʾ��
		return ERROR;
	}
	(*S)->top = NULL; //ջΪ��ʱ��ΪNULL,�������һ������ָ����ΪNULL
	(*S)->count = -1; //��ջΪ��ʱ����ֵΪ-1
	printf("��ʼ���ɹ���\n"); //�����ʾ��
	return OK;
}
//������ջ
Status CreateLinkStack(LinkStack *S)
{
	int i = 0;
	SElemType e;
	StackNode *N;
	printf("������Ԫ��(ÿ��Ԫ��֮��ո�ֿ������һ��Ԫ�������ֱ�ӻ���)��");
	do
	{
		scanf("%d", &e);
		N = (StackNode*)malloc(sizeof(StackNode)); //������������ڴ�ռ�
		if (N == NULL) //�ж������ڴ�ռ��Ƿ�ɹ�
		{
			printf("�����ڴ�ռ�ʧ�ܣ��޷�����������㣡"); //�����ʾ��
			return ERROR;
		}
		N->data = e; //��e��ֵ��ֵ�����N��������
		N->next = S->top; //������ջ��ջ������ͷ��������ջ������������½���ָ����Ҫָ��ԭ����ջ��
		S->top = N; //��N����Ϊջ��
		S->count++; //��ջ���ȼ�һ
	} while(getchar()!='\n'); //�ж�Ϊ����ʱ �������
	printf("����Ԫ����ջ�ɹ���\n");
	return OK;
}
//�����ջ��Ԫ�ظ���
Status LengthLinkStack(LinkStack *S)
{
	if (S->count == -1) //�ж���ջ�Ƿ�Ϊ��ջ
	{
		printf("��ջΪ��ջ��Ԫ�ظ���Ϊ�㣡\n"); //�����ʾ��
		return ERROR;
	}
	printf("��ջ��Ԫ�ظ���Ϊ��%d\n", S->count + 1); //�����ջԪ�ظ���
	return OK;
}
//���ջ��Ԫ��
Status OutTop(LinkStack *S)
{
	if (S->count == -1) //�ж���ջ�Ƿ�Ϊ��ջ
	{
		printf("��ջΪ��ջ��û��ջ��Ԫ�أ�\n"); //�����ʾ��
		return ERROR;
	}
	printf("��ջ��ջ��Ԫ��Ϊ��%d\n", S->top->data); //�����ջջ��Ԫ�ص�ֵ
	return OK;
}
//��ջ����
//����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(LinkStack *S, SElemType e)
{
	StackNode *N;
	N = (StackNode*)malloc(sizeof(StackNode)); //�����ڴ�ռ䣬��ʧ�ܻ᷵��NULL���ɹ����ص�ַ
	if (N == NULL) //�ж������ڴ�ռ��Ƿ�ɹ�
	{
		printf("�����ڴ�ռ�ʧ�ܣ��޷������µ�ջ��Ԫ�أ�\n"); //�����ʾ��
		return ERROR;
	}
	N->data = e; //��e��ֵ��ֵ��N��������
	N->next = S->top; //��ԭ����ջ����ΪN��next
	S->top = N; //��N�ĵ�ַ��ֵ��S ��top��Ϊ�µ�ջ��Ԫ��
	S->count++; //ջ�ĳ��ȼ�һ
	printf("��ջ�ɹ���\n"); //�����ʾ��
	return OK;
}
//��ջ����
//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status Pop(LinkStack *S, SElemType *e)
{
	StackNode *p;
	if (S->count == -1) //�ж���ջ�Ƿ�Ϊ��ջ
	{
		printf("��ջΪ��ջ��û��Ԫ�ؿ��Գ�ջ��\n"); //�����ʾ��
		return ERROR;
	}
	p = S->top; //��ջ��Ԫ�ص�ָ�븳ֵ��p
	*e = p->data; //��ջ��Ԫ���������ֵ����e
	S->top = p->next; //��ջ��Ԫ�ص�ָ�����ֵ��ֵ��Sջ��ָ��
	S->count--; //��ջ���ȼ�һ
	free(p); //�ͷ�p��ָ����ڴ�ռ� �˲�һ��Ҫ�У���Ȼ������ڴ��޷��ͷţ�����ڴ���Ƭ
	return OK;
}
//�����ջ����Ԫ��
Status OutValue(LinkStack *S)
{
	StackNode *N;
	int i = 1;
	if (S->count == -1) //�ж��Ƿ�Ϊ��ջ
	{
		printf("��ջΪ��ջ��û��Ԫ�ؿ������\n"); //�����ʾ��
		return ERROR;
	}
	N = S->top; //��ջ��ָ�븳ֵ��N
	do
	{
		printf("��%d��Ԫ��Ϊ��%d\n", i++, N->data);
		N = N->next; //Nָ����һ�����
	} while (N != NULL);
	printf("����Ԫ�ذ��մ�ջ����ջ�׵�˳����ϣ�\n"); //�����ʾ��
	return OK;
}
//�����ջ
Status ClearStack(LinkStack *S)
{
	StackNode *N;
	if (S->count == -1) //�ж���ջ�Ƿ�Ϊ��ջ
	{
		printf("��ջΪ��ջ��������գ������ظ�ִ�дι��ܣ�\n"); //�����ʾ��
		return ERROR;
	}
	do
	{
		N = S->top; //��ջ��ָ�븳ֵ��N
		S->top = N->next; //ջ��ָ��ָ��N������һ����� 
		free(N); //�ͷ�N��ָ����ڴ�ռ�
	} while (S->top != NULL); //���һ������ָ����ָ��NULL
	free(S->top); //�ͷ����һ�����
	S->count = -1; //��ջ������Ϊ-1
	printf("��ջ��ճɹ���\n"); //�����ʾ��
	return OK;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStack *S)
{
	if (S->count == -1) //�ж��Ƿ�Ϊ��ջ
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
	printf("\t\t-------------------��ӭʹ����ջ�Ļ�������----------------------\n");
	printf("\t\t|\t\t 1  ��ʼ����ջ                   \t\t|\n");
	printf("\t\t|\t\t 2  ������ջ                     \t\t|\n");
	printf("\t\t|\t\t 3  �����ջ��Ԫ�ظ���           \t\t|\n");
	printf("\t\t|\t\t 4  �����ջջ��Ԫ��             \t\t|\n");
	printf("\t\t|\t\t 5  ����ָ��Ԫ�ص�ջ��             \t\t|\n");
	printf("\t\t|\t\t 6  ɾ��ջ��Ԫ��                   \t\t|\n");
	printf("\t\t|\t\t 7  �����ջ����Ԫ��             \t\t|\n");
	printf("\t\t|\t\t 8  �����ջ                     \t\t|\n");
	printf("\t\t|\t\t 9  ��ջ�Ƿ�Ϊ��                 \t\t|\n");
	printf("\t\t|\t\t 10 �˳�ϵͳ                       \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t��ѡ��(1-10):");
}
int main()
{
	LinkStack *S;
	int quit = 0;
	int select;
	SElemType e;
	while (1)
	{
		Menu(); //���ò˵�����
		scanf("%d", &select);
		switch (select)
		{
		case 1: InitLinkStack(&S); break; //��ʼ����ջ
		case 2: CreateLinkStack(S); break; //������ջ
		case 3: LengthLinkStack(S); break; //�����ջ��Ԫ�ظ���
		case 4: OutTop(S); break; //�����ջջ��Ԫ��
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
		case 7: OutValue(S); break; //�����ջ����Ԫ��
		case 8: ClearStack(S); break; //�����ջ
		case 9: //��ջ�Ƿ�Ϊ��
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