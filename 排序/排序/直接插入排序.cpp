/* 对顺序表 L 作直接插入排序 */
void InsertSort(SqList *L)
{
	int	i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->r[i]<L->r[i - l])	/* 需将 L->r[i] 插入有序子表 */ 
		{
			L->r[0] = L->r[i];	/* 设置哨兵 */
			for (j = i - l; L->r[j]>L->r[0]; j--)
			{
				L->r[j + l] = L->r[j];  /* 记录后移 */
			}
			L->r[j + l] = L->r[0];	/* 插入到正确位置 */
		}
	}
}
