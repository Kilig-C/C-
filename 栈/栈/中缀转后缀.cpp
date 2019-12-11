//�����ԣ�����ʱ����Ϸ� ���ڲ��Ϸ�����û�������������ֱ���Ϊ0~9�ķ�Χ ��λ���ϵ�����û��ʵ��
#include<iostream>
#include<string>
#include<stack>
#include<cmath>

using namespace std;
//��׺ת��Ϊ��׺
int InfixToSuffix(string &Infix, string &Suffix)
{
	stack<char> S;
	for (int i = 0; i < Infix.length(); ++i)
	{
		if (Infix[i] >= '0' && Infix[i] <= '9')
		{
			Suffix.push_back(Infix[i]); //��������־�ֱ�Ӹ�ֵ����׺�ַ���

		}
		else if (Infix[i] == '+' || Infix[i] == '-') 
		{
			//���Infix[i]��+�Ż�����-�� ����ַ�ջ�в�Ϊ����ջ�����ŵ����ȼ����ڻ����Infix[i] ���ջ
			//һֱ��ջ��Ԫ�����ȼ�����Infix[i]����ջ���˳�whileѭ��
			while (!S.empty() && (S.top() == '*' || S.top() == '/' || S.top() == '+' || S.top() == '-'))
			{
				Suffix.push_back(S.top()); //ջ��Ԫ�ظ�ֵ����׺�ַ���
				S.pop(); //ջ��Ԫ�س�ջ
			}
			S.push(Infix[i]); //Infix[i]�������ջ
		}
		else if (Infix[i] == '*' || Infix[i] == '/')
		{
			//���Infix[i]��*�ź�/�� 
			//�ַ�ջ��Ϊ����ջ��Ԫ��Ϊ*�Ż���/�� 
			//Ҳ����ջ�����ŵ����ȼ���Infix[i]�ķ������ȼ��߻����
			//�ַ�ջջ��Ԫ�ظ�ֵ����׺�ַ����ҳ�ջ
			while (!S.empty() && (S.top() == '/' || S.top() == '*'))
			{
				Suffix.push_back(S.top()); //ջ��Ԫ�ظ�ֵ����׺�ַ���
				S.pop(); //ջ��Ԫ�س�ջ
			}
			S.push(Infix[i]); //Infix[i]�������ջ
		}
		else if (Infix[i] == '(')
		{
			//���Infix[i]�ķ���Ϊ ( ֱ�������ջ
			S.push(Infix[i]); //��ջ
		}
		else if (Infix[i] == ')')
		{
			//�ַ�ջջ��Ԫ�ز�Ϊ ( ���߲�Ϊ��ʱ ����ջ��Ԫ��
			while (S.top() != '(' && !S.empty())
			{
				Suffix.push_back(S.top()); //ջ��Ԫ�ظ�ֵ����׺�ַ���
				S.pop(); //ջ��Ԫ�س�ջ
			}
			//��ʱջ��Ԫ��Ϊ ( Ҫ���䵯��
			S.pop(); //���� ( 
		}
	}
	//��׺�ַ����������֮�� ���ַ�ջ��Ϊ�� ���丳ֵ����׺�ַ������ҵ���
	while (!S.empty())
	{
		Suffix.push_back(S.top()); //��ջջ��Ԫ�ظ�ֵ����׺�ַ���
		S.pop(); //��ջ
	}
	return 0;
}
//��׺ת���ó����
float SuffixToValue(string &Suffix)
{
	stack<float> S;
	float n, m;
	for (int i = 0; i < Suffix.length(); ++i)
	{
		if (Suffix[i] >= '0'&& Suffix[i] <= '9')
		{
			//����ַ���Suffix[i]Ϊ�����ַ� ���ջ
			S.push(Suffix[i] - '0');
		}
		else
		{
			//����ַ���Suffix[i]Ϊ������� �����ջ������Ԫ�� �ֱ𸳸�n��m
			n = S.top();
			S.pop();
			m = S.top();
			S.pop();
			if (Suffix[i] == '+')
			{
				//n��m���ӷ� �ó�����ֵ��ջ
				S.push(n + m);
			}
			else if (Suffix[i] == '-')
			{
				//n��m������ �ó�����ֵ��ջ
				S.push(m - n);
			}
			else if (Suffix[i] == '*')
			{
				//n��m���˷� �ó�����ֵ��ջ
				S.push(n * m);
			}
			else if (Suffix[i] == '/')
			{
				//n��m������ �ó�����ֵ��ջ
				S.push(m / n);
			}
		}
	}
	return S.top(); //ִ�е��˴�ʱ ջ��ֻʣ������ ���ؼ�����
}
int main()
{
	stack<char> S;
	string Infix, Suffix;
	cout << "������������ʽ��";
	cin >> Infix;
	InfixToSuffix(Infix, Suffix);
	cout << "ת��Ϊ��׺���ʽΪ��";
	for (int i = 0; i < Suffix.length(); ++i)
	{
		cout << Suffix[i] << ' ';
	}
	cout << endl;
	cout<<"������Ϊ��"<<SuffixToValue(Suffix)<<endl;
	return 0;
}