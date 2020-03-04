/* ��˳��� L �е������� L.r[low..high] ���������� */ 
void QSortl(SqList *L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGTH_INSERT_SORT)
	{
		while (low < high)
		{
			pivot = Partitionl(L, low, high);	/* L. r [low. .high] ����Ϊ����*/
			/* �������ֵ pivot */
			QSortl(L, low, pivot - 1);	/* �Ե��ӱ�ݹ����� */
			low = pivot + 1;	/* β�ݹ� */
		}
	}
	else
	{
		InsertSort(L);
	}
}





#define MAX_LENGTH_INSERT_SORT 7	/* ���鳤�ȷ�ֵ */
/* ��˳��� L �е�������L.r[low..high] ���������� */ 
void QSort(SqList &L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGTH_INSERT_SORT)
	{
		/* �� high - low ���ڳ���ʱ�ÿ������� */
		pivot = Partition(L, low, high); /* �� L.r[low..high]����Ϊ����*/
		/* ���������ֵ pivot */
		QSort(L, low, pivot - 1);	/* �Ե��ӱ�ݹ����� */
		QSort(L, pivot + l, high);	/* �Ը��ӱ�ݹ����� */
	}
	else /* �� high-low С�ڵ��ڳ���ʱ��ֱ�Ӳ������� */
	{
		InsertSort(L);
	}
}


/* ���������Ż��㷨 */
int Partitionl(SqList *L, int low, int high)
{
	int pivotkey;
	//����ʡ������ȡ�д���
	pivotkey = L->r[low];	/*���ӱ�ĵ�һ����¼�������¼*/-
	L->r[0] = pivotkoy;		/* ��������I�ֱ��ݵ� L->r[0] */
	while (low < high)		/* �ӱ�����˽������м�ɨ�� */
	{
		while (low < high&&L->r[high] >= pivotkey)
		{
			high--;
		}
		L->r[low] = L->r[high];	/* �����滻�����ǽ����ķ�ʽ���в��� */
		while (low < high&&L->r[low] <= pivotkey)
		{
			low++;
		}
		L->r[high] = L->r[low];	/* �����滻�����ǽ����ķ�ʽ���в��� */
	}
	L->r[low] = L->r[0]��	/* ��������ֵ�滻�� L.r[low] */
	return low;	/* ������������λ�� */
}


int pivotkey;
//-----------���Ӵ���-----------
int m = low + (high - low) / 2; /* ���㔵���м��Ԫ�ص��±� */ 
if (L->r[low] > L->r[high])
{
	swap(L, low, high);	/* ����������Ҷ����ݣ���֤��˽�С */
}
if (L->r[m] > L->r[high])
{
	swap(L, high, m);	/* �����м����Ҷ����ݣ���֤�м��С */
}
if (L->r[m] > L->r[low])
{
	swap(L, m, low);	/* �����м���������ݣ���֤��˽�С */
}
/*��ʱ L.r [low] �Ѿ�Ϊ���������������������I�ֵ��м�ֵ��*/
//-----------------------------
pivotkey = L->r[low];	/* ���ӱ�ĵ�һ����¼�������¼ */



/* ����˳��� L ���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ���󣩵ļ�¼������С��������*/
int Partition(SqList *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low];	/* ���ӱ�ĵ�һ����¼�������¼ */
	while (low < high)	/* �ӱ�����˽������м�ɨ�� */
	{
		while (low < high&&L->r[high] >= pivotkey)
		{
			high--;
		}
		swap(L, low, high); /* ���������¼С�ļ�¼�������Ͷ� */
		while (low < high&&L->r[low] <= pivotkey)
		{
			low++;
		}
		swap(L, low, high); /* ���������¼��ļ�¼�������߶� */
	}
	return low;	/* ������������λ�� */
}


/* ��˳��� L ���������� */
void Quicksort(SqList *L)
{
	QSort(L, 1, L->length);
}
/*��˳��� L �е������� L->r[low..high] ���������� */ 
void QSort(SqList *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high); /* �� L->r [low. .high]����Ϊ����*/
		/* �������ֵ pivot */
		QSort(L, low, pivot - 1);	/* �Ե��ӱ�ݹ����� */
		QSort(L, pivot + 1, high);	/* �Ը��ӱ�ݹ����� */
	}
}

