#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;
bool check;

int main()
{
	while (1)
	{
		stack<char> a;
		check = false;
		getline(cin, s);
		if (s == ".") break;
		for(int i=0;i<s.length();i++)
		{
			if (s[i] == '[' || s[i] == '(')
			{
				a.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (!a.empty() && a.top() == '(')
				{
					a.pop();
				}
				else {
					check = true;
					break;
				}
			}
			else if (s[i] == ']')
			{
				if (!a.empty() && a.top() == '[')
				{
					a.pop();
				}
				else {
					check = true;
					break;
				}
			}
		}
		if (!check && a.empty())
		{
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}