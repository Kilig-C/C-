#define MAXSIZE 10	/* 用于要排序数组个数最大值，可根据需要修改 */
typedef struct
{
	int r[MAXSIZE + 1]; /* 用于存储要排序数组，r[0] 用作哨兵或临时变量 */
	int length;	/* 用于记录顺序表的长度 */
}SqList;

/* 交换 L 中数组 r 的下标为 i 和 j 的值 */
void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}


/* 对顺序表 L 作希尔排序 */
void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;	/* 增量序列 */
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])
			{
				/* 需将 L->r[i] 插入有序增量子表 */
				L->r[0] = L->r[i];	/* 暂存在 L->r[0] */
				for (j = i - increment; j>0 && L->r[0] < L->r[j]; j -= increment)
				{
					L->r[j + increment] = L->r[j];/*记录后移，査找插入位置*/
				}
				L->r[j + increment] = L->r[0]; /* 插入 */
			}
		}
	} while (increment>1);
}
