#include <iostream>

using namespace std;
string s;
char a[27];
int cnt[27];

int main()
{
	cin >> s;
	for (int i = 0; i < 26; i++)
	{
		a[i] = 97 + i;
	}
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (s[i] == a[j])
			{
				cnt[j]++;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << " ";
	}
}