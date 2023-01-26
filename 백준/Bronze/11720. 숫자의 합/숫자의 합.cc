#include <iostream>

using namespace std;

int main()
{
	int t;
	int num[101];
	int sum = 0;
	char a[101];

	cin >> t;
	cin >> a;
	for (int i = 0;i<t;i++)
	{
		num[i] = a[i] - '0';
		sum += num[i];
	}
	cout << sum;
}