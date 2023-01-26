#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int rv;
int rm;

int main()
{
	cin >> n >> m;
	while (1)
	{
		rv += n % 10;
		n /= 10;
		if (n) rv *= 10;

		rm += m % 10;
		m /= 10;
		if (m) rm *= 10;

		if (n == 0 && m == 0) break;

	}
	cout << max(rv, rm);
}