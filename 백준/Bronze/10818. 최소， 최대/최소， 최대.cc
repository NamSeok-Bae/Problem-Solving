#include <iostream>
using namespace std;

int a[1000001];
int min1 = -1000001;
int max1 = 1000001;

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		if (min1 < a[i])
			min1 = a[i];
		if (max1 > a[i])
			max1 = a[i];
	}
	cout << max1 << " " << min1;
	return 0;
}