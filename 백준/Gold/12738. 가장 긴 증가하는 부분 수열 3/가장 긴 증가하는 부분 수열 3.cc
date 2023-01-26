#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1000001];
vector<int> v;
int cnt = 1;

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	for (int i = 1;i < n;i++)
	{
		if (v.back() < arr[i])
		{
			cnt++;
			v.push_back(arr[i]);
		}
		else
		{
			int x = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[x] = arr[i];
		}
	}
	cout << cnt;
}