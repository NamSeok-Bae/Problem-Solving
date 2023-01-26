#include <iostream>
#include<string>

using namespace std;

int main()
{
	string a;
	char b[26];
	int num = 65;
	int sum = 0;
	cin >> a;

	for (int i = 0;i<26;i++)
	{
		b[i] = num;
		num++;
	}

	for (int i = 0; i < a.length();i++)
	{
		for (int j = 0;j < 26;j++)
		{
			if (a[i] == b[j])
			{
				if (j <= 2)
				{
					sum += 2;
				}
				else if (j <= 5)
				{
					sum += 3;
				}
				else if (j <= 8)
				{
					sum += 4;
				}
				else if (j <= 11)
				{
					sum += 5;
				}
				else if (j <= 14)
				{
					sum += 6;
				}
				else if (j <= 18)
				{
					sum += 7;
				}
				else if (j <= 21)
				{
					sum += 8;
				}
				else if (j <= 25)
				{
					sum += 9;
				}
			}
		}
		sum += 1;
	}
	cout << sum;
}