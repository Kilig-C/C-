/* 对顺序表 L 中的子序列 L.r[low..high] 作快速排序 */ 
void QSortl(SqList *L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGTH_INSERT_SORT)
	{
		while (low < high)
		{
			pivot = Partitionl(L, low, high);	/* L. r [low. .high] —分为二，*/
			/* 算出枢轴值 pivot */
			QSortl(L, low, pivot - 1);	/* 对低子表递归排序 */
			low = pivot + 1;	/* 尾递归 */
		}
	}
	else
	{
		InsertSort(L);
	}
}





#define MAX_LENGTH_INSERT_SORT 7	/* 数组长度阀值 */
/* 对顺序表 L 中的子序列L.r[low..high] 作快速排序 */ 
void QSort(SqList &L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGTH_INSERT_SORT)
	{
		/* 当 high - low 大于常数时用快速排序 */
		pivot = Partition(L, low, high); /* 将 L.r[low..high]—分为二，*/
		/* 并算出枢轴值 pivot */
		QSort(L, low, pivot - 1);	/* 对低子表递归排序 */
		QSort(L, pivot + l, high);	/* 对高子表递归排序 */
	}
	else /* 当 high-low 小于等于常教时用直接插入排序 */
	{
		InsertSort(L);
	}
}


/* 快速排序优化算法 */
int Partitionl(SqList *L, int low, int high)
{
	int pivotkey;
	//这里省略三数取中代码
	pivotkey = L->r[low];	/*用子表的第一个记录作枢轴记录*/-
	L->r[0] = pivotkoy;		/* 将枢轴关鍵字备份到 L->r[0] */
	while (low < high)		/* 从表的两端交替向中间扫描 */
	{
		while (low < high&&L->r[high] >= pivotkey)
		{
			high--;
		}
		L->r[low] = L->r[high];	/* 采用替换而不是交换的方式进行操作 */
		while (low < high&&L->r[low] <= pivotkey)
		{
			low++;
		}
		L->r[high] = L->r[low];	/* 采用替换而不是交换的方式进行操作 */
	}
	L->r[low] = L->r[0]；	/* 将枢轴数值替换回 L.r[low] */
	return low;	/* 返回枢轴所在位置 */
}


int pivotkey;
//-----------增加代码-----------
int m = low + (high - low) / 2; /* 计算數组中间的元素的下标 */ 
if (L->r[low] > L->r[high])
{
	swap(L, low, high);	/* 交换左端与右端数据，保证左端较小 */
}
if (L->r[m] > L->r[high])
{
	swap(L, high, m);	/* 交换中间与右端数据，保证中间较小 */
}
if (L->r[m] > L->r[low])
{
	swap(L, m, low);	/* 交换中间与左端数据，保证左端较小 */
}
/*此时 L.r [low] 已经为整个序列左中右三个关鍵字的中间值。*/
//-----------------------------
pivotkey = L->r[low];	/* 用子表的第一个记录作枢轴记录 */



/* 交换顺序表 L 中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前（后）的记录均不大（小）于它。*/
int Partition(SqList *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low];	/* 用子表的第一个记录作枢轴记录 */
	while (low < high)	/* 从表的两端交替向中间扫描 */
	{
		while (low < high&&L->r[high] >= pivotkey)
		{
			high--;
		}
		swap(L, low, high); /* 将比枢轴记录小的记录交换到低端 */
		while (low < high&&L->r[low] <= pivotkey)
		{
			low++;
		}
		swap(L, low, high); /* 将比枢轴记录大的记录交换到高端 */
	}
	return low;	/* 返回枢轴所在位置 */
}


/* 对顺序表 L 作快速排序 */
void Quicksort(SqList *L)
{
	QSort(L, 1, L->length);
}
/*对顺序表 L 中的子序列 L->r[low..high] 作快速排序 */ 
void QSort(SqList *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high); /* 将 L->r [low. .high]—分为二，*/
		/* 算出枢轴值 pivot */
		QSort(L, low, pivot - 1);	/* 对低子表递归排序 */
		QSort(L, pivot + 1, high);	/* 对高子表递归排序 */
	}
}

