#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> st;
int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*' || s[i]=='/')
		{
			while (!st.empty() && (st.top() == '*' || st.top() == '/'))
			{
				cout << st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '-' || s[i]=='+')
		{
			while (!st.empty() && st.top() !='(')
			{
				cout << st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '(')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			while (st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			cout << s[i];
		}
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}