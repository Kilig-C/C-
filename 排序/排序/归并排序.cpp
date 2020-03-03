/* �� SR[] �����ڳ���Ϊ s �������������鲢�� TR[] */
void MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1; 
	int j;
	while (i <= n - 2 * s + 1)
	{
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1); /* �����鲢 */
		i = i + 2 * s;
	}
	if (i < n - s + l)	/* �鲢����������� */
	{
		Merge(SR, TR, i, i + s - 1, n);
	}
	else	/* �����ֻʣ�µ��������� */
	{
		for (j = i; j <= n; j++)
		{
			TR[j] = SR[j];
		}
	}									
}



/* ��˳��� L ���鲢�ǵݹ����� */
void MergeSort2(SqList *L)
{
	int* TR = (int*)malloc(L->length*sizeof(int));/* �������ռ� */
	int	k = 1;
	while (k < L->length)
	{
		MergePass(L->r, TR, k, L->length);
		k = 2 * k;		/* �����г��ȼӱ� */
		MergePass(TR, L->r, k, L->length);
		k = 2 * k;		/* �����г��ȼӱ� */
	}
}

/* ������� SR[i..m] �� SR[m + l..n] �鲢Ϊ����� TR[i..n] */
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++) /* �� SR �м�¼��С����鲢�� TR */
	{
		if (SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
		{
			TR[k + l] = SR[i + l];	/* ��ʣ��� SR[i..m] ���Ƶ� TR */
		}
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
		{
			TR[k + l] = SR[j + l];	/* ��ʣ��� SR[j..n] ���Ƶ� TR */
		}
	}
}


#define MAXSIZE 10
/* �� SR[s..t] �鲢����Ϊ TRl[s..t] */
void MSort(int SR[], int TR1[], int s, int t)
{
	int	m;
	int	TR2[MAXSIZE + 1];
	if (s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		m = (s + t) / 2; /* �� SR[s. .t] ƽ��Ϊ SR[s. .m]�� SR[m+l. .t] */
		MSort(SR, TR2, s, m);/* �ݹ齫 SR[s. .m] �鲢Ϊ����� TR2[s. .m] */
		MSort(SR, TR2, m + l, t);/* �ݹ齫 SR[m+l. .t] �鲢Ϊ���� TR2 [m+1. .t] */
		Merge(TR2, TR1, s, m, t); /* ��TR2[s..m] �� TR2[m+l..t] */
		/* �鲢��TR1[S. .t] */
	}
}


/* ��˳��� L ���鲢���� */
void MergeSort(SqList *L)
{
	Msort(L->r, L->r, L->length);
}