#include <iostream>
#include<string>

using namespace std;

int main()
{
	string a;

	int t,R;

	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> R;
		cin >> a;
		for (int j = 0;j < a.length();j++)
		{
			for (int k = 0;k < R;k++)
			{
				cout << a[j];
			}
		}
		cout << endl;
	}
}