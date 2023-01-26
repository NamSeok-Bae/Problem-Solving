#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x;
int arr[100001];
bool check[100001];
vector<int> v;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}

	int l = 0;
	int r = n;
	int min_height = 987654321;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		
		int temp = 0;
		for (int i = 0; i < m; i++)
		{
			if (temp >= arr[i] - mid)
			{
				temp = arr[i] + mid;
			}
			else
			{
				break;
			}
		}
		if (temp < n)
		{
			l = mid + 1;
		}
		else
		{
			min_height = min(min_height, mid);
			r = mid - 1;
		}
	}
	cout << min_height;
}