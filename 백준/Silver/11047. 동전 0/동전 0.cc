#include <iostream>
using namespace std;

int n;
long long int k;
long long int arr[11];
int cnt;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	while (1)
	{
		if (arr[n] <= k)
		{
			cnt++;
			k -= arr[n];
		}
		else
			n--;
		if (k <= 0)
			break;
	}
	cout << cnt;
}