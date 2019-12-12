//˳�����֮ѭ������
#include<iostream>
#include<cstdlib>
using namespace std;

#define MAXSIZE 1024
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;//QElemType���͸���ʵ���������
//ѭ�����е�˳��洢�ṹ 
typedef struct
{
	QElemType data[MAXSIZE];
	int front; //ͷָ��
	int rear; //βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
} SqQueue;
//��ʼ��һ���ն���
Status InitQueue(SqQueue **Q)
{

	//��ʼ��ʱ�����еĶ�ͷָ��front�Ͷ�βָ��rear��ָ���±�0
	(*Q)->front = 0;
	(*Q)->rear = 0;
	return OK;
}
//����˳�����
Status CreateQueue(SqQueue *Q)
{
	return OK;
}
//���ض��г���
//����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ����
int QueueLenght(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
//����в���
//������δ���������Ԫ��eΪQ�µĶ�βԪ��
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) //���������ж� 
	{
		return ERROR;
	}
	Q->data[Q->rear] = e; //��Ԫ��e��ֵ����β 
	Q->rear = (Q->rear + 1) % MAXSIZE; //rearָ�������һλ�� 
	//���������ת������ͷ��
	return OK;
}
//�����в���
//�����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear) //���пյ��ж�
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; //����ͷԪ�ظ�ֵ��e
	Q->front = (Q->front + 1) % MAXSIZE; //frontָ�������һλ�ã����������ת������ͷ��
	return OK;
}

//������Q�����ҷǿգ���e���ض���Q�Ķ�ͷԪ��
Status GetHead(SqQueue *Q, QElemType*e)
{
	return OK;
}
//���˳����и���Ԫ��
Status OutValue(SqQueue *Q)
{
	return OK;
}
//���˳�����
Status ClearQueue(SqQueue *Q)
{
	return OK;
}
//˳������Ƿ�Ϊ�� �շ���true ��Ϊ�շ���false
Status QueueEmpty(SqQueue *Q)
{
	return OK;
}
//�˵�����
void Menu()
{
	system("cls"); //�����Ļ
	printf("\n");
	printf("\t\t-------------------��ӭʹ��˳����еĻ�������----------------------\n");
	printf("\t\t|\t\t 1  ��ʼ��˳�����                   \t\t|\n");
	printf("\t\t|\t\t 2  ����˳�����                     \t\t|\n");
	printf("\t\t|\t\t 3  ���˳����е�Ԫ�ظ���           \t\t|\n");
	printf("\t\t|\t\t 4  ���˳����ж�ͷԪ��             \t\t|\n");
	printf("\t\t|\t\t 5  ����ָ��Ԫ�ص���β             \t\t|\n");
	printf("\t\t|\t\t 6  ɾ����ͷԪ��                   \t\t|\n");
	printf("\t\t|\t\t 7  ���˳����и���Ԫ��             \t\t|\n");
	printf("\t\t|\t\t 8  ���˳�����                     \t\t|\n");
	printf("\t\t|\t\t 9  ˳������Ƿ�Ϊ��                 \t\t|\n");
	printf("\t\t|\t\t 10 �˳�ϵͳ                       \t\t|\n");
	printf("\t\t-----------------------------------------------------------------\n");
	printf("\t\t��ѡ��(1-10):");
}
int main()
{
	SqQueue *Q;
	int quit = 0;
	int select;
	QElemType e;
	while (1)
	{
		Menu(); //���ò˵�����
		scanf("%d", &select);
		switch (select)
		{
		case 1: InitQueue(&Q); break; //��ʼ��˳�����
		case 2: CreateQueue(Q); break; //����˳�����
		case 3: QueueLenght(*Q); break; //���˳����е�Ԫ�ظ���
		case 4: GetHead(Q,&e); break; //���˳����ж�ͷԪ��
		case 5: //����ָ��Ԫ�ص���β
			printf("Ҫ�����Ԫ�ص�ֵΪ��");
			scanf("%d", &e);
			EnQueue(Q, e);
			break;
		case 6: //ɾ�����ж�ͷԪ��
			if (DeQueue(Q, &e))
			{
				printf("ɾ���ɹ���\nɾ���Ķ��ж�ͷԪ�ص�ֵΪ��%d\n", e);
			}
			break;
		case 7: OutValue(Q); break; //���˳����и���Ԫ��
		case 8: ClearQueue(Q); break; //���˳�����
		case 9: //˳������Ƿ�Ϊ��
			if (QueueEmpty(Q))
			{
				printf("����Ϊ�ն��У�\n");
			}
			else
			{
				printf("���в�Ϊ�գ�\n");
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
	free(Q);//�ͷ�Q
	printf("���������\n");
	return 0;
}