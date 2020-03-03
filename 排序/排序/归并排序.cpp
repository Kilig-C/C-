/* 将 SR[] 中相邻长度为 s 的子序列两两归并到 TR[] */
void MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1; 
	int j;
	while (i <= n - 2 * s + 1)
	{
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1); /* 两两归并 */
		i = i + 2 * s;
	}
	if (i < n - s + l)	/* 归并最后两个序列 */
	{
		Merge(SR, TR, i, i + s - 1, n);
	}
	else	/* 若最后只剩下单个子序列 */
	{
		for (j = i; j <= n; j++)
		{
			TR[j] = SR[j];
		}
	}									
}



/* 对顺序表 L 作归并非递归排序 */
void MergeSort2(SqList *L)
{
	int* TR = (int*)malloc(L->length*sizeof(int));/* 申请额外空间 */
	int	k = 1;
	while (k < L->length)
	{
		MergePass(L->r, TR, k, L->length);
		k = 2 * k;		/* 子序列长度加倍 */
		MergePass(TR, L->r, k, L->length);
		k = 2 * k;		/* 子序列长度加倍 */
	}
}

/* 将有序的 SR[i..m] 和 SR[m + l..n] 归并为有序的 TR[i..n] */
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++) /* 将 SR 中记录由小到大归并入 TR */
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
			TR[k + l] = SR[i + l];	/* 将剩余的 SR[i..m] 复制到 TR */
		}
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
		{
			TR[k + l] = SR[j + l];	/* 将剩余的 SR[j..n] 复制到 TR */
		}
	}
}


#define MAXSIZE 10
/* 将 SR[s..t] 归并排序为 TRl[s..t] */
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
		m = (s + t) / 2; /* 将 SR[s. .t] 平分为 SR[s. .m]和 SR[m+l. .t] */
		MSort(SR, TR2, s, m);/* 递归将 SR[s. .m] 归并为有序的 TR2[s. .m] */
		MSort(SR, TR2, m + l, t);/* 递归将 SR[m+l. .t] 归并为有序 TR2 [m+1. .t] */
		Merge(TR2, TR1, s, m, t); /* 将TR2[s..m] 和 TR2[m+l..t] */
		/* 归并到TR1[S. .t] */
	}
}


/* 对顺序表 L 作归并排序 */
void MergeSort(SqList *L)
{
	Msort(L->r, L->r, L->length);
}