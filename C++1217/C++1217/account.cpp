#include"account.h"
#include<iostream>
#include<cmath>

using namespace std;

static int haha;


double SavingsAccount::total = 0;
//SavingsAccount����س�Ա������ʵ��
SavingsAccount::SavingsAccount(int date, int id, double rate) :id(id), balance(0), rate(rate), lastDate(date), accumulation(0)
{
	cout << date << "\t#" << id << " is creaed" << endl;
	cout << haha << endl;
}
void SavingsAccount::record(int date, double amount)//��¼һ���� dateΪ���� amountΪ���
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;

	//cout << "******" << amount << endl;
	/*
	1������ԭ�ͣ�
	1 double floor ( double x );
	2 float floor ( float x );
	3 long double floor ( long double x );

	2�����ܣ�����һ��С�ڴ���������������

	3��������xΪ�������������

	4������ֵ�����ز�����x���������
	��0.5��Ϊ����������ȡ��
	*/
	balance += amount;
	total += amount;
	cout << "date" << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
void SavingsAccount::deposit(int date, double amount)//�����ֽ�
{
	record(date, amount);
}
void SavingsAccount::withdraw(int date, double amount)//ȡ���ֽ�
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
void SavingsAccount::settle(int date)//������Ϣ��ÿ��һ��һ�ŵ���һ�θú���
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

