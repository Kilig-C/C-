/*쳲���������*/
int Fibonacci_Search(int *a, int n, int key)
{
	int low, high, mid, i, k;
	low = 1;	/*	��������±�Ϊ��¼��λ */
	high = n;	/*	��������±�Ϊ��¼ĩλ */
	k = 0;
	while (n > F[k] - 1)	/*	���� n λ��쳲��������е�λ�� */
	{
		k++;
	}
	for (i = n; i < F[k] - 1; i++)	/* ����������ֵ��ȫ */
	{
		a[i] = a[n];
	}
	while (low <= high)
	{
		mid = low + F[k - 1] - 1;	/*	���㵱ǰ�ָ����±� */
		if (key<a[mid])		/* �����Ҽ�¼С�ڵ�ǰ�ָ���¼ */
		{
			high = mid - 1;	/*	����±�������ָ��±� mid-1 �� */
			k = k - 1;		/* 쳲����������±��һλ */
		}
		else if (key>a[mid]) /*	�����Ҽ�¼���ڵ�ǰ�ָ���¼ */
		{
			low = mid + 1;	/* ����±�������ָ��±� mid+1 �� */
			k = k - 2;		/* 쳲����������±����λ */
		}
		else
		{
			if (mid <= n)
			{
				return mid;	/*	�������˵�� mid ��Ϊ���ҵ���λ�� */
			}
			else
			{
				return n;	/*	�� mid>n ˵���ǲ�ȫ��ֵ������n */
			}
		}
	}
	return	0;
}
