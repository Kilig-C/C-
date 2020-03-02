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


/* ��˳��� L ��ϣ������ */
void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;	/* �������� */
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])
			{
				/* �轫 L->r[i] �������������ӱ� */
				L->r[0] = L->r[i];	/* �ݴ��� L->r[0] */
				for (j = i - increment; j>0 && L->r[0] < L->r[j]; j -= increment)
				{
					L->r[j + increment] = L->r[j];/*��¼���ƣ����Ҳ���λ��*/
				}
				L->r[j + increment] = L->r[0]; /* ���� */
			}
		}
	} while (increment>1);
}
