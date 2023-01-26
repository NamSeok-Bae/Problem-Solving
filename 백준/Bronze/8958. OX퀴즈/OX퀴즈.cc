#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,sum=0,count = 0;
	string s;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> s;
		for (int j = 0;j < s.length();j++)
		{
			if (s[j] == 'O')
			{
				count += 1;
				sum = sum + count;
			}
			else if (s[j] == 'X')
			{
				count = 0;
			}
		}

		cout << sum << endl;
		sum = 0;
		count = 0;
	}

}