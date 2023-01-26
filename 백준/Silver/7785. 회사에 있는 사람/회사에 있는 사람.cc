#include <iostream>
#include <set>
#include <string>

using namespace std;
set<string,greater<string>> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--)
	{
		string s1;
		string s2;
		cin >> s1 >> s2;
		if (s2 == "enter")
		{
			s.insert(s1);
		}
		else if (s2 == "leave")
		{
			s.erase(s1);
		}
	}
	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << "\n";
	}
}