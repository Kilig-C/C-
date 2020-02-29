typedef int Status;
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10	/* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
typedef struct
{
	int r[MAXSIZE + 1]; /* ���ڴ洢Ҫ�������飬r[0] �����ڱ�����ʱ���� */
	int length;	/* ���ڼ�¼˳���ĳ��� */
}SqList;

/* ���� L ������ r ���±�Ϊ i �� j ��ֵ */
void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}



/* ��˳��� L ����������ð����������棩*/ 
void BubbleSort0(SqList *L)
{
	int i, j;
	for (i = 1; i<L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[i] > L->r[j])
			{
				swap(L, i, j); /* ���Q L->r[i] �� L->r[j] ��ֵ */
			}
		}
	}
}

/* ��˳��� L ��ð������ */ 
void BubbleSort(SqList *L)
{
	int i, j;
	for (i = 1; i<L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)	/* ע�� j �ǴӺ���ǰѭ�� */
		{
			if (L->r[j] > L->r[j + 1])	/* ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨���죩*/
			{
				swap(L, j, j + 1); /* ���� L->r[j] �� L->r[j+l] ��ֵ */
			}
		}
	}
}


/* ��˳��� L ���Ľ�ð���㷨 */
void BubbleSort2(SqList *L)
{
	int i, j;
	Status flag = TRUE;	/* flag ������Ϊ��� */
	for (i = 1; i<L->length && flag; i++) /* �� flag Ϊ true ���˳�ѭ�� */
	{
		flag = FALSE;	/* ��ʼΪ false */
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j]>L->r[j + 1])
			{
				swap(L, j, j + 1); /* ���� L->r[j] �� L->r[j + l] ��ֵ */
				flag = TRUE;	/* ��������ݽ������� flag Ϊ true */
			}
		}
	}
}

 