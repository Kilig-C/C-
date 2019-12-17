#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
class SavingsAccount //�����˻���
{
	int id;//�˺�
	double balance;//���
	double rate;//����������
	int lastDate;//�ϴα������ʱ��
	double accumulation;//�����ۼ�֮��
	static double total;//�����˻����ܽ��
	void record(int date, double amount);//��¼һ���� ���� ���
	double accumulate(int date) const//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
	{
		return accumulation + balance*(date - lastDate);
	}
public:
	SavingsAccount(int date, int id, double rate);//���캯��
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
	void deposit(int date, double amount);//�����ֽ�
	void withdraw(int date, double amount);//ȡ���ֽ�
	void settle(int date);//������Ϣ��ÿ��һ��һ�ŵ���һ�θú���
	void show() const;//��ʾ�˻���Ϣ
};
#endif//_ACCOUNT_H_