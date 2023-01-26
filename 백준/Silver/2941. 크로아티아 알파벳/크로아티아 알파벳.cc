#include <iostream>
#include<string>

using namespace std;

int main()
{
	string a;

	cin >> a;
	int count = a.length();

	for (int i = 0;i < a.length();i++)
	{
		if (a[i] == 'c')
		{
			if (a[i + 1] == '=')
			{
				count--;
			}
			else if (a[i + 1] == '-')
			{
				count--;
			}
		}
		else if (a[i] == 'd')
		{
			if (a[i + 1] == 'z')
			{
				if (a[i + 2] == '=')
				{
					count -= 2;
				}
			}
			else if (a[i + 1] == '-')
			{
				count--;
			}
		}
		else if (a[i] == 'l')
		{
			if (a[i + 1] == 'j')
			{
				count--;
			}
		}
		else if (a[i] == 'n')
		{
			if (a[i + 1] == 'j')
			{
				count--;
			}
		}
		else if (a[i] == 's')
		{
			if (a[i + 1] == '=')
				count--;
		}
		else if (a[i] == 'z')
		{
			if (a[i + 1] == '=' && a[i - 1] != 'd')
			{
				count--;
			}
		}
	}
	cout << count;
}