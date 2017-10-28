/*

题目描述
输入一个字符串，然后对每个字符进行奇校验，最后输出校验后的二进制数(如'3’，输出：10110011)。
输入描述:

输入包括一个字符串，字符串长度不超过100。



输出描述:

可能有多组测试数据，对于每组数据，
对于字符串中的每一个字符，输出按题目进行奇偶校验后的数，每个字符校验的结果占一行。


输入例子:

3
3a


输出例子:

10110011
10110011
01100001



*/




#include<iostream>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int arr[1000] = { 0 };

	int num = 0;
	cin >> num;
	for (int i = 0; i<num; i++)
		cin >> arr[i];

	int max = arr[0];

	for (int i = 0; i<num - 1; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}

	
	sort(arr, arr + num);


	for (int i = 0; i<num - 1; i++)
	{
		if (i != num - 2)
			cout << arr[i] << " ";
		else
			cout << arr[i] << endl;
	}

	return 0;
}