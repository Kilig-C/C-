//#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a;
	string  b;
	if (a < 60)
	{
		b = "不及格";
	}
	else if (a < 70)
	{
		b = "及格";
	}
	else if (a < 80)
	{
		b = "中等";
	}
	else if (a < 90)
	{
		b = "良好";
	}
	else
	{
		b = "优秀";
	}
	return 0;
}