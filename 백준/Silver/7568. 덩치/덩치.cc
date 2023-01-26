#include <iostream>

using namespace std;

int t;
int arr[51];
int brr[51];
int cnt;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> arr[i] >> brr[i];
	}
	for (int i = 0; i < t; i++)
	{
		cnt = 1;
		for (int j = 0; j < t; j++)
		{
			if (arr[i] < arr[j] && brr[i] < brr[j])
			{
				cnt++;
			}
		}
		cout << cnt << " ";
	}
}