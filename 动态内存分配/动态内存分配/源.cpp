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
		cout << "分配内存时出错!" << endl;
	}
	*/
	int i;
	int *point;
	cout << "创建数组长度为：";
	cin >> i;
	point = new(nothrow) int[i];
	if (point == nullptr)
	{
		cout << "内存分配出现错误，无法分配内存！" << endl;
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			cout << "请输入数组元素" << j + 1 << ": ";
			cin >> point[j];
		}
		cout << "你所输入的元素为：";
		for (int j = 0; j < i; j++)
		{
			cout << point[j] << "  ";
		}
		cout << endl;
	}
	delete[] point;
	

	return 0;
}