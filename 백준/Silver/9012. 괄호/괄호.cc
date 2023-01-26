#include <iostream>
#include <string>

using namespace std;

int t;
string s;
int cnt1;
int cnt2;

int main()
{
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cnt1 = 0;
		cnt2 = 0;
		cin >> s;
		for (int j = 0;j < s.size();j++)
		{
			if (s[j] == '(')
			{
				cnt1++;
			}
			if (cnt1 > cnt2)
			{
				if (s[j] == ')')
				{
					cnt2++;
				}
			}
			else
			{
				cnt1--;
			}
		}
		if (cnt1 == cnt2)
		{
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}