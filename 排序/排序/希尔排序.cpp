/* 对顺序表 L 作希尔排序 */
void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + l；	/* 增量序列 */
		for (i = increment + l; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])
			{
				/* 需将 L->r[i] 插入有序增量子表 */
				L->r[0] = L->r[i];	/* 暂存在 L->r[0] */
				for (j = i - increment; j>0 && L->r[0] < L->r[j]; j -= increment)
				{
					L->r[j + increment] = 乙->2：[：)];/*记录后移，査找搞入位置*/
				}
				L->r[j + increment] - L->r[0]; /* 插入 */

			}
		}
	} while (increment〉1);
}
