#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n;
string temp;
int t;
queue<int> s;

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
		else if (temp == "front")
		{
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.front() << endl;
			}
		}
		else if (temp == "back")
		{
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.back() << endl;
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
				cout << s.front() << endl;
				s.pop();
			}
		}
	}
}