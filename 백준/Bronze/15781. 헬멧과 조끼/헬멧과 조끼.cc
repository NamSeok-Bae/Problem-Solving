#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int h[1000];
	int a[1000];
	int hmax,amax;

	cin >> n >> m;

	for (int i = 0; i < n;i++)
	{
		cin >> h[i];
	}
	hmax = h[0];
	for (int i = 0; i < n;i++)
	{
		if (h[i] > hmax)
			hmax = h[i];
	}
	for (int i = 0; i < m;i++)
	{
		cin >> a[i];
	}
	amax = a[0];
	for (int i = 0; i < m;i++)
	{
		if (a[i] > amax)
			amax = a[i];
	}
	cout << hmax + amax;
}