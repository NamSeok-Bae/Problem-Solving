#include <iostream>

using namespace std;

int n;
int r;
int cnt;

int main()
{
	cin >> n;
	r = n;
	while (1)
	{
		r = (r % 10) * 10 + ((r / 10) + (r % 10)) % 10;
		cnt++;
		if (r == n)
		{
			cout << cnt;
			break;
		}
	}
}