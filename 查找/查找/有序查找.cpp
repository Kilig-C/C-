/* �۰���� */
int Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;	/* ��������±�Ϊ��¼��λ */
	high = n;	/* ��������±�Ϊ��¼ĩλ */
	while (low <= high)
	{
		mid = (low + high) / 2;	/* �۰� */
		if (key<a[mid])	/* ������ֵ����ֵС */
		{
			high = mid - 1;	/* ����±��������λ�±�Сһλ */
		}
		else if (key>a[mid])	/* ������ֵ����ֵ�� */
		{
			low = mid + 1;	/* ����±��������λ�±��һλ */
		}
		else
		{
			return mid;	/* �������˵�� mid ��Ϊ���ҵ���λ�� */
		}
	}
	return 0;
}
