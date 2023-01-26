#include <iostream>

using namespace std;

int n, cnt;
int arr[101];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++)
	{
		cnt = 1;
		int first = arr[0];
		while (first % arr[i] != 0)
		{
			first += arr[0];
			cnt++;
		}
		cout << int(first / arr[i]) << "/" << cnt << endl;
	}
}