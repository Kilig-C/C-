/*
//��ӡ��ǰ��ʮλ��쳲��������е���
#include<iostream>
using namespace std;
int main()
{
	int a[40]; //����һ������Ϊ40��int���͵�����
	a[0] = 0; //��ֵ
	a[1] = 1; //��ֵ
	cout << a[0] << endl;
	cout << a[1] << endl;
	for (int i = 2; i < 40; ++i)
	{
		a[i] = a[i - 1] + a[i - 2]; //��ֵ ��i����ֵ����ǰ������ֵ֮��
		cout << a[i] << endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
//쳲������ĵݹ麯��
int Fbi(int i)
{
	if (i < 2) //�ݹ���ֹ����
	{
		return i == 0 ? 0 : 1; //iΪ0ʱ����0����Ϊ0ʱ��˵��iΪ1���򷵻�1
	}
	return Fbi(i - 1) + Fbi(i - 2); //����Fbi���Ǻ����Լ������ڵ����Լ�
}
int main()
{
	for (int i = 0; i < 40; ++i)
	{
		cout << Fbi(i) << endl; //����Fbi����
	}
	return 0;
}
*/