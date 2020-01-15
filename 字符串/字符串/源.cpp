/*
ADT 串（string）
Data
串中元素仅由一个字符组成，相邻元素具有前驱和后继关系。
Opration
StrAssign(T, *chars)：生成一个其值等于字符串常量chars的串T。
StrCopy(T, S)：串S存在，由串S复制得串T。
ClearString(S)：若串S存在，将串清空。
StringEmpty(S)：若串S为空，返回true，否则返回false。
StrLength(S)：返回串的元素个数，即串的长度。
StrCompare(S, T)：若S > T，返回值 > 0，若S = T，返回0，若S < T，返回值 < 0。
Concat(T, S1, S2)：用T返回由S1和S2联接而成的新串。
SubString(Sub, S, pos, len)：串S存在，1≤pos≤StrLength(S), 且0≤len≤StrLength(S) - pos + 1，用Sub返回串S的第pos个字符，用Sub返回串S的第pos个字符起长度为len的字串
Index(S, T, pos)：串S和T存在，T是非空串，1≤pos≤StrLength(S)。若主串S中存在和串T相同的子串，则返回它在主串S中第pos个字符之后第一个出现的位置，则返回0。
Replace(S, T, V)：串S、T和V存在，T是非空串。用V替换主串S中出现的所有与T相等的不重叠的子串。
StrInsert(S, pos, T)：串S和T存在，1≤pos≤StrLength(S) + 1。在串S的第pos个字符之前插入串T。
StrDelete(S, pos, len)：串S存在，1≤pos≤StrLength(S) - len + 1。从串S中删除第pos个字符起长度为len的子串。
endADT
*/

#include<iostream>
#include<cstring>
using namespace std;
/*
T为非空串。若主串S中第pos个字符串之后存在与T相等的子串,
则返回第一个这样的子串在S中的位置，否则返回0
*/
int Index(string  S, string  T, int pos)
{
	int n, m, i;
	string sub;
	if (pos > 0)
	{
		n = StrLength(S); //得到主串S的长度
		m = StrLenhth(T); //得到子串T的长度
		i = pos;
		while (i <= n - m + 1)
		{
			SubString(sub, S, i, m); //取主串第i个位置，长度与T相等子串给sub
			if (StrCompare(sub, T) != 0) //如果两串不相等
			{
				++i;
			}
			else //如果两串相等
			{
				return i; //返回i值
			}
		}
	}
	return 0; //若无子串与T相等，返回0
}
/*
返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0。
T 非空，1≤pos≤StrLength(S)。
*/
int Index(string S, string T, int pos)
{
	int i = pos; //i用于主串S中当前位置下标，若pos不为1，则从pos位置开始匹配
	int j = 1; //j用于子串T中当前位置下标值
	while (i <= S[0] && j <= T[0]) //若i小于S长度且j小于T的长度时循环
	{
		if (S[i] == T[j]) //两字母相等则继续
		{
			++i;
			++j;
		}
		else //指针后退重新开始匹配
		{
			i = i - j + 2; //i退回到上次匹配首位的下一位
			j = 0; //j退回到子串T的首位
		}
	}
	if (j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

int main()
{

	return 0;
}