#include"account.h"
#include<iostream>

using namespace std;
int haha = 10000;
int main()
{
	SavingsAccount sa0(1, 21325302, 0.015);
	SavingsAccount sa1(1, 58320212, 0.015);
	sa0.deposit(5, 5000);//��
	sa1.deposit(25, 10000);//��
	sa0.deposit(45, 5500);//��
	sa1.withdraw(60, 4000);//ȡ
	sa0.settle(90);//������Ϣ
	sa1.settle(90);//������Ϣ
	sa0.show();
	sa1.show();
	cout << "Total: " << SavingsAccount::getTotal() << endl;
	//haha++;
	cout << haha << endl;
	int i;
	char *p = "This is an example.";
	i = reinterpret_cast<int>(p);
	cout << i << endl;
	cout << p << endl;
	return 0;
}
