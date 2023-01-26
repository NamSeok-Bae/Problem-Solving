#include <iostream>

using namespace std;

int x;
int sum;
int cnt;
int main()
{
	sum = 64;
	cin >> x;
	while (1)
	{
		if (sum > x)
		{
			sum /= 2;
		}
		else
		{
			x -= sum;
			cnt++;
		}

		if (x == 0)
			break;
	}
	cout << cnt;
}