/* 顺序查找，a 为数组，n 为要查找的数组个数，key 为要查找的关键字*/ 
int Sequential_Search(int *a, int n, int key)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return 0;
}

/* 有哨兵顺序查找 */
int Sequential_Search2(int *a, int n, int key)
{
	int i;
	a[0] = key; /* 设置 a[0] 为关键字值，我们称之为“哨兵” */
	i = n;	/* 循环从数组尾部开始 */
	while (a[i] != key)
	{
		i--;
	}
	return i; /* 返回 0 则说明查找失败 */
}
