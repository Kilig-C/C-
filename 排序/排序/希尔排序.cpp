/* ��˳��� L ��ϣ������ */
void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + l��	/* �������� */
		for (i = increment + l; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])
			{
				/* �轫 L->r[i] �������������ӱ� */
				L->r[0] = L->r[i];	/* �ݴ��� L->r[0] */
				for (j = i - increment; j>0 && L->r[0] < L->r[j]; j -= increment)
				{
					L->r[j + increment] = ��->2��[��)];/*��¼���ƣ����Ҹ���λ��*/
				}
				L->r[j + increment] - L->r[0]; /* ���� */

			}
		}
	} while (increment��1);
}
