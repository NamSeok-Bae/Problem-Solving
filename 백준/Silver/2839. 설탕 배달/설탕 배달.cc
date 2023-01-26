#include <iostream>

using namespace std;

int n;
int cnt;

int main()

{

	cin >> n;
	while (1)
	{
		if (n % 5 == 0)
		{
			cnt += n / 5;
			n %= 5;
		}
		else if (n < 0)
		{
			cnt = -1;
			break;
		}
		else
		{
			n -= 3;
			cnt++;
		}
		if (n == 0)
			break;
	}
	cout << cnt;
}