#include<iostream>
#include<new>
using namespace std;

int main()
{
	/*
	int *point;
	point = new int(10);

	*point += 10;
	cout << "point= " << point << endl;
	cout << "*point= " << *point << endl;

	delete point;

	point = new int[10];

	for (int i = 0; i < 10; i++)
	{
		point[i] = i+1;
		cout << "point[" << i+1 << "] = " << point[i] << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		*(point + i) += 10;
		cout << "point[" << i+1 << "] = " << point[i] << endl;
	}

	delete[] point;
	
	int *ip = new int(10);
	float *fp = new float(88.88f);
	char *cp = new char('c');

	cout << "*ip = " << *ip << endl;
	cout << "*fp = " << *fp << endl;
	cout << "*cp = " << *cp << endl;

	delete ip;
	delete fp;
	delete cp;

	int *point;
	point = new(nothrow) int[10];
	if (point == nullptr)
	{
		cout << "�����ڴ�ʱ����!" << endl;
	}
	*/
	int i;
	int *point;
	cout << "�������鳤��Ϊ��";
	cin >> i;
	point = new(nothrow) int[i];
	if (point == nullptr)
	{
		cout << "�ڴ������ִ����޷������ڴ棡" << endl;
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			cout << "����������Ԫ��" << j + 1 << ": ";
			cin >> point[j];
		}
		cout << "���������Ԫ��Ϊ��";
		for (int j = 0; j < i; j++)
		{
			cout << point[j] << "  ";
		}
		cout << endl;
	}
	delete[] point;
	

	return 0;
}