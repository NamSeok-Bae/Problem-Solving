#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n;
string temp;
int t;
stack<int> s;

int main()
{
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> temp;
		if (temp == "push")
		{
			cin >> n;
			s.push(n);
		}
		else if (temp == "top")
		{
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.top() << endl;
			}
		}
		else if (temp == "size")
		{
			cout << s.size() << endl;
		}
		else if (temp == "empty")
		{
			cout << s.empty() << endl;
		}
		else if (temp == "pop")
		{
			if (s.empty())
			{
				cout<<"-1\n";
			}
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
	}
}