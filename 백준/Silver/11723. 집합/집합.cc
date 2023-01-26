#include <iostream>
#include <string>
using namespace std;

int bit_set;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int m;
	cin >> m;
	while (m--)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			int a;
			cin >> a;
			bit_set = bit_set | (1 << a-1);
		}
		else if (s == "remove")
		{
			int a;
			cin >> a;
			bit_set = bit_set & (~(1 << a-1));
		}
		else if (s == "check")
		{
			int a;
			cin >> a;
			if (bit_set & (1 << a - 1))
			{
				cout << 1 << "\n";
			}
			else
				cout << 0 << "\n";
		}
		else if (s == "toggle")
		{
			int a;
			cin >> a;
			bit_set = bit_set ^ (1 << a-1);
		}
		else if (s == "all")
		{
			bit_set = ~0;
			// 위,아래 두가지 방법
			//bit_set = 1 << 20;
			//bit_set--;
		}
		else if (s == "empty")
		{
			bit_set = 0;
		}
	}
}