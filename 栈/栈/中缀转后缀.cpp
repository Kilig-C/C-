//局限性：输入时必须合法 对于不合法输入没有做出处理、数字必须为0~9的范围 两位以上的数字没有实现
#include<iostream>
#include<string>
#include<stack>
#include<cmath>

using namespace std;
//中缀转化为后缀
int InfixToSuffix(string &Infix, string &Suffix)
{
	stack<char> S;
	for (int i = 0; i < Infix.length(); ++i)
	{
		if (Infix[i] >= '0' && Infix[i] <= '9')
		{
			Suffix.push_back(Infix[i]); //如果是数字就直接赋值给后缀字符串

		}
		else if (Infix[i] == '+' || Infix[i] == '-') 
		{
			//如果Infix[i]是+号或者是-号 如果字符栈中不为空切栈顶符号的优先级高于或等于Infix[i] 则出栈
			//一直到栈顶元素优先级低于Infix[i]或者栈空退出while循环
			while (!S.empty() && (S.top() == '*' || S.top() == '/' || S.top() == '+' || S.top() == '-'))
			{
				Suffix.push_back(S.top()); //栈顶元素赋值给后缀字符串
				S.pop(); //栈顶元素出栈
			}
			S.push(Infix[i]); //Infix[i]进入符号栈
		}
		else if (Infix[i] == '*' || Infix[i] == '/')
		{
			//如果Infix[i]是*号和/号 
			//字符栈不为空且栈顶元素为*号或者/号 
			//也就是栈顶符号的优先级比Infix[i]的符号优先级高或相等
			//字符栈栈顶元素赋值给后缀字符串且出栈
			while (!S.empty() && (S.top() == '/' || S.top() == '*'))
			{
				Suffix.push_back(S.top()); //栈顶元素赋值给后缀字符串
				S.pop(); //栈顶元素出栈
			}
			S.push(Infix[i]); //Infix[i]进入符号栈
		}
		else if (Infix[i] == '(')
		{
			//如果Infix[i]的符号为 ( 直接入符号栈
			S.push(Infix[i]); //入栈
		}
		else if (Infix[i] == ')')
		{
			//字符栈栈顶元素不为 ( 或者不为空时 弹出栈顶元素
			while (S.top() != '(' && !S.empty())
			{
				Suffix.push_back(S.top()); //栈顶元素赋值给后缀字符串
				S.pop(); //栈顶元素出栈
			}
			//此时栈顶元素为 ( 要将其弹出
			S.pop(); //弹出 ( 
		}
	}
	//中缀字符串处理完成之后 若字符栈不为空 则将其赋值给后缀字符串并且弹出
	while (!S.empty())
	{
		Suffix.push_back(S.top()); //将栈栈顶元素赋值给后缀字符串
		S.pop(); //出栈
	}
	return 0;
}
//后缀转化得出结果
float SuffixToValue(string &Suffix)
{
	stack<float> S;
	float n, m;
	for (int i = 0; i < Suffix.length(); ++i)
	{
		if (Suffix[i] >= '0'&& Suffix[i] <= '9')
		{
			//如果字符串Suffix[i]为数字字符 则进栈
			S.push(Suffix[i] - '0');
		}
		else
		{
			//如果字符串Suffix[i]为运算符号 则输出栈中两个元素 分别赋给n和m
			n = S.top();
			S.pop();
			m = S.top();
			S.pop();
			if (Suffix[i] == '+')
			{
				//n和m做加法 得出来的值入栈
				S.push(n + m);
			}
			else if (Suffix[i] == '-')
			{
				//n和m做减法 得出来的值入栈
				S.push(m - n);
			}
			else if (Suffix[i] == '*')
			{
				//n和m做乘法 得出来的值入栈
				S.push(n * m);
			}
			else if (Suffix[i] == '/')
			{
				//n和m做除法 得出来的值入栈
				S.push(m / n);
			}
		}
	}
	return S.top(); //执行到此处时 栈内只剩计算结果 返回计算结果
}
int main()
{
	stack<char> S;
	string Infix, Suffix;
	cout << "请输入运算表达式：";
	cin >> Infix;
	InfixToSuffix(Infix, Suffix);
	cout << "转化为后缀表达式为：";
	for (int i = 0; i < Suffix.length(); ++i)
	{
		cout << Suffix[i] << ' ';
	}
	cout << endl;
	cout<<"运算结果为："<<SuffixToValue(Suffix)<<endl;
	return 0;
}