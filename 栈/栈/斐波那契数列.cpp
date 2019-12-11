/*
//打印出前四十位的斐波那契数列的数
#include<iostream>
using namespace std;
int main()
{
	int a[40]; //定义一个长度为40的int类型的数组
	a[0] = 0; //赋值
	a[1] = 1; //赋值
	cout << a[0] << endl;
	cout << a[1] << endl;
	for (int i = 2; i < 40; ++i)
	{
		a[i] = a[i - 1] + a[i - 2]; //赋值 第i个的值等于前两个的值之和
		cout << a[i] << endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
//斐波那契的递归函数
int Fbi(int i)
{
	if (i < 2) //递归终止条件
	{
		return i == 0 ? 0 : 1; //i为0时返回0，不为0时，说明i为1，则返回1
	}
	return Fbi(i - 1) + Fbi(i - 2); //这里Fbi就是函数自己，它在调用自己
}
int main()
{
	for (int i = 0; i < 40; ++i)
	{
		cout << Fbi(i) << endl; //调用Fbi函数
	}
	return 0;
}
*/