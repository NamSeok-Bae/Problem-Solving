#include <iostream>
#include <cstdlib>

using namespace std;

int n;
int x;
int cnt;
int a1, a2, a3;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		if (i < 100)
		{
			cnt++;
		}
		else 
		{
			a1 = i / 100;
			a2 = (i / 10) % 10;
			a3 = i % 10;
			if (a2 - a1 == a3 - a2)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
}