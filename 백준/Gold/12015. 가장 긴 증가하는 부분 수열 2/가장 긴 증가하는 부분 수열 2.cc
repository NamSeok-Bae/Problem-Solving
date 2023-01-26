#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int cnt(1);
int arr[1000001];
vector<int> v;

int main()
{
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	for (int i = 1;i < t;i++)
	{
		if (v.back() < arr[i])
		{
			v.push_back(arr[i]);
			cnt++;
		}
		else
		{
			vector<int>::iterator iter = lower_bound(v.begin(), v.end(), arr[i]);
			v[iter - v.begin()] = arr[i];
		}
	}
	cout << cnt;
}