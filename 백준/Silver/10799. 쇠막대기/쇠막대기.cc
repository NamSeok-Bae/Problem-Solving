#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack<char> st;
int cnt;
string s;

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')')
		{
			if (s[i-1] == '(')
			{
				st.pop();
				cnt += st.size();
			}
			else if (s[i - 1] == ')')
			{
				st.pop();
				cnt += 1;
			}
		}
	}
	cout << cnt;
}