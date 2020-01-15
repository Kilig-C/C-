//ͨ�����㷵���Ӵ�T��next����
void get_next(String T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0]) //�˴�T[0]��ʾ��T�ĳ���
	{
		if (j == 0 || T[i] == T[j]) //T[i]��ʾ��׺�ĵ����ַ� T[j]��ʾǰ׺�ĵ����ַ�
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j]; //���ַ�����ͬ����jֵ����
		}
	}
}
/*
�����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ���������Ϊ0
T�ǿգ�1��pos��StrLength(S)
*/
int Index_KMP(String S, String T, int pos)
{
	//i��������S��ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ��
	int i = pos;
	//j�����Ӵ�T�е�ǰλ���±�ֵ
	int j = 1;
	int next[255]; //����һ��next����
	get_next(T, next); //�Դ�T���������õ�next����
	while (i <= S[0] && j <= T[0]) //��iС��S�ĳ�����jС��T�ĳ���ʱ������ѭ��
	{
		if (j == 0 || S[i] == T[j])//����ĸ�����������������㷨������j=0�ж�
		{
			++i;
			++j;
		}
		else //ָ��������¿�ʼƥ��
		{
			j = next[j]; //j�˻غ��ʵ�λ�ã�iֵ����
		}
	}
	if (j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}
//��ģʽ��T��next��������ֵ����������nextval
void get_nextval(String T, int *nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T[0]) //�˴�T[0]��ʾ��T�ĳ���
	{
		if (j == 0 || T[i] == T[j]) //T[i]��ʾ��׺�ĵ����ַ� T[j]��ʾǰ׺�ĵ����ַ�
		{
			++i;
			++j;
			if (T[i] != T[j]) //����ǰ�ַ���ǰ׺�ַ���ͬ
			{
				nextval[i] = j; //��ǰ��jΪnextval��iλ�õ�ֵ
			}
			else
			{
				//�����ǰ׺�ַ���ͬ����ǰ׺�ַ���nextvalֵ��ֵ��nextval��iλ�õ�ֵ
				nextval[i] = nextval[j]; 
			}
		}
		else
		{
			j = nextval[j]; //���ַ�����ͬ����jֵ����
		}
	}
}

