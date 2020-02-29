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
