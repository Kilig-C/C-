/*
ADT ����string��
Data
����Ԫ�ؽ���һ���ַ���ɣ�����Ԫ�ؾ���ǰ���ͺ�̹�ϵ��
Opration
StrAssign(T, *chars)������һ����ֵ�����ַ�������chars�Ĵ�T��
StrCopy(T, S)����S���ڣ��ɴ�S���Ƶô�T��
ClearString(S)������S���ڣ�������ա�
StringEmpty(S)������SΪ�գ�����true�����򷵻�false��
StrLength(S)�����ش���Ԫ�ظ����������ĳ��ȡ�
StrCompare(S, T)����S > T������ֵ > 0����S = T������0����S < T������ֵ < 0��
Concat(T, S1, S2)����T������S1��S2���Ӷ��ɵ��´���
SubString(Sub, S, pos, len)����S���ڣ�1��pos��StrLength(S), ��0��len��StrLength(S) - pos + 1����Sub���ش�S�ĵ�pos���ַ�����Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ִ�
Index(S, T, pos)����S��T���ڣ�T�Ƿǿմ���1��pos��StrLength(S)��������S�д��ںʹ�T��ͬ���Ӵ����򷵻���������S�е�pos���ַ�֮���һ�����ֵ�λ�ã��򷵻�0��
Replace(S, T, V)����S��T��V���ڣ�T�Ƿǿմ�����V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ���
StrInsert(S, pos, T)����S��T���ڣ�1��pos��StrLength(S) + 1���ڴ�S�ĵ�pos���ַ�֮ǰ���봮T��
StrDelete(S, pos, len)����S���ڣ�1��pos��StrLength(S) - len + 1���Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ���
endADT
*/

#include<iostream>
#include<cstring>
using namespace std;
/*
TΪ�ǿմ���������S�е�pos���ַ���֮�������T��ȵ��Ӵ�,
�򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
*/
int Index(string  S, string  T, int pos)
{
	int n, m, i;
	string sub;
	if (pos > 0)
	{
		n = StrLength(S); //�õ�����S�ĳ���
		m = StrLenhth(T); //�õ��Ӵ�T�ĳ���
		i = pos;
		while (i <= n - m + 1)
		{
			SubString(sub, S, i, m); //ȡ������i��λ�ã�������T����Ӵ���sub
			if (StrCompare(sub, T) != 0) //������������
			{
				++i;
			}
			else //����������
			{
				return i; //����iֵ
			}
		}
	}
	return 0; //�����Ӵ���T��ȣ�����0
}
/*
�����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ���������ֵΪ0��
T �ǿգ�1��pos��StrLength(S)��
*/
int Index(string S, string T, int pos)
{
	int i = pos; //i��������S�е�ǰλ���±꣬��pos��Ϊ1�����posλ�ÿ�ʼƥ��
	int j = 1; //j�����Ӵ�T�е�ǰλ���±�ֵ
	while (i <= S[0] && j <= T[0]) //��iС��S������jС��T�ĳ���ʱѭ��
	{
		if (S[i] == T[j]) //����ĸ��������
		{
			++i;
			++j;
		}
		else //ָ��������¿�ʼƥ��
		{
			i = i - j + 2; //i�˻ص��ϴ�ƥ����λ����һλ
			j = 0; //j�˻ص��Ӵ�T����λ
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

int main()
{

	return 0;
}