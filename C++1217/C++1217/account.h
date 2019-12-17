#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
class SavingsAccount //储蓄账户类
{
	int id;//账号
	double balance;//余额
	double rate;//存款的年利率
	int lastDate;//上次变更余额的时间
	double accumulation;//余额按日累加之和
	static double total;//所有账户的总金额
	void record(int date, double amount);//记录一笔账 日期 金额
	double accumulate(int date) const//获得到指定日期为止的存款金额按日累积值
	{
		return accumulation + balance*(date - lastDate);
	}
public:
	SavingsAccount(int date, int id, double rate);//构造函数
	int getId()
	{
		return id;
	}
	int getBalance()
	{
		return balance;
	}
	double getRate()
	{
		return rate;
	}
	static double getTotal()
	{
		return total;
	}
	void deposit(int date, double amount);//存入现金
	void withdraw(int date, double amount);//取出现金
	void settle(int date);//计算利息，每年一月一号调用一次该函数
	void show() const;//显示账户信息
};
#endif//_ACCOUNT_H_