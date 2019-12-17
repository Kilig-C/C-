#include"account.h"
#include<iostream>
#include<cmath>

using namespace std;

static int haha;


double SavingsAccount::total = 0;
//SavingsAccount类相关成员函数的实现
SavingsAccount::SavingsAccount(int date, int id, double rate) :id(id), balance(0), rate(rate), lastDate(date), accumulation(0)
{
	cout << date << "\t#" << id << " is creaed" << endl;
	cout << haha << endl;
}
void SavingsAccount::record(int date, double amount)//记录一笔账 date为日期 amount为金额
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;

	//cout << "******" << amount << endl;
	/*
	1、函数原型：
	1 double floor ( double x );
	2 float floor ( float x );
	3 long double floor ( long double x );

	2、功能：返回一个小于传入参数的最大整数

	3、参数：x为将来被处理的数

	4、返回值：返回不大于x的最大整数
	加0.5是为了四舍五入取整
	*/
	balance += amount;
	total += amount;
	cout << "date" << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
void SavingsAccount::deposit(int date, double amount)//存入现金
{
	record(date, amount);
}
void SavingsAccount::withdraw(int date, double amount)//取出现金
{
	if (amount > balance)
	{
		cout << "Error: not enough money" << endl;
	}
	else
	{
		record(date, -amount);
	}
}
void SavingsAccount::settle(int date)//计算利息，每年一月一号调用一次该函数
{
	double interest = accumulate(date)*rate / 365;
	if (interest != 0)
	{
		record(date, interest);
	}
	accumulation = 0;
}
void SavingsAccount::show()const
{
	cout << "#" << id << "\tBalance: " << balance << endl;
}

