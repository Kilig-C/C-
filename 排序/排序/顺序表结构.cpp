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
