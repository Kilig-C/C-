/* ˳����ң�a Ϊ���飬n ΪҪ���ҵ����������key ΪҪ���ҵĹؼ���*/ 
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

/* ���ڱ�˳����� */
int Sequential_Search2(int *a, int n, int key)
{
	int i;
	a[0] = key; /* ���� a[0] Ϊ�ؼ���ֵ�����ǳ�֮Ϊ���ڱ��� */
	i = n;	/* ѭ��������β����ʼ */
	while (a[i] != key)
	{
		i--;
	}
	return i; /* ���� 0 ��˵������ʧ�� */
}
