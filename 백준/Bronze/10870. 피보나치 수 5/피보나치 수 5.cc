#include <iostream>

using namespace std;

int f[21] = { 0,1,1 };
int fibo(int n)
{
	for (int i = 3;i <= n;i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int main()
{	
	int a;
	cin >> a;
	cout<<fibo(a);
	return 0;
}