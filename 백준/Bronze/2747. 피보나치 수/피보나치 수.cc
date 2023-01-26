#include <iostream>

using namespace std;

int t;
int fibo[46];
int f;
int main()
{
	cin >> t;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2;i <= t;i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[t];
}