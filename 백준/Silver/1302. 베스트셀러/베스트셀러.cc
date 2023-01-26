#include <iostream>
#include <string>
#include <map>

using namespace std;

multimap<string,int>m;
string s;
int mx = 0;
string ms;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		m.insert(pair<string, int>(s, m.count(s)+1));
	}
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		if (mx < iter->second)
		{
			mx = iter->second;
			ms = iter->first;
		}
	}
	cout<<ms;
}