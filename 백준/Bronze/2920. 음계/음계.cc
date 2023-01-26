#include <iostream>

using namespace std;

int brr[8];
int as, de;
int main()
{
	for (int i = 0;i < 8 ;i++)
	{
		cin >> brr[i];
	}
	for (int i = 0;i < 8;i++)
	{
		if (brr[i] == i + 1)
		{
			as++;
		}
		else if (brr[i] == 8 - i)
		{
			de++;
		}
	}
	if (as == 8)
	{
		cout << "ascending";
	}
	else if (de == 8)
	{
		cout << "descending";
	}
	else
	{
		cout << "mixed";
	}
}