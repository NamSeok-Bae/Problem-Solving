#include <iostream>
#include<string>

using namespace std;

int main()
{
	string a;
	int t;

	cin >> t;
	int count = t;
	for (int i = 0;i < t;i++)
	{
		bool flag = 0;
		cin >> a;
		for (int j = 0;j < a.length();j++)
		{
			for (int k = 0;k < j;k++)
			{
				if (a[j]!=a[j-1] &&a[j] == a[k])
				{
					flag = 1;
					count--;
					break;
				}
			}
			if (flag == 1)
				break;
		}
	}
	cout << count;
}