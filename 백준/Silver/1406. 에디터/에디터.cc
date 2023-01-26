#include<iostream>
#include<string>
#include<stack>

using namespace std;
string s;
stack<char> st;
stack<char> st2;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		st.push(s[i]);
	}

	int t;
	cin >> t;
	while (t--)
	{
		char temp;
		cin >> temp;
		if (temp == 'L')
		{
			if (!st.empty())
			{
				st2.push(st.top());
				st.pop();
			}
		}
		else if (temp == 'D')
		{
			if (!st2.empty())
			{
				st.push(st2.top());
				st2.pop();
			}
		}
		else if (temp == 'B')
		{
			if (!st.empty())
			{
				st.pop();
			}
		}
		else if (temp == 'P')
		{
			char a;
			cin >> a;
			st.push(a);
		}
	}
	while (!st.empty())
	{
		st2.push(st.top());
		st.pop();
	}
	while (!st2.empty())
	{
		cout << st2.top();
		st2.pop();
	}
}