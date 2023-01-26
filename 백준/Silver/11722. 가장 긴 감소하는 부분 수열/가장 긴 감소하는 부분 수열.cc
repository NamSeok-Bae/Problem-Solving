#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[1001];
vector<int> lis;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	reverse(arr, arr + n);
	lis.push_back(arr[0]);
	for (int i = 0; i < n; i++)
	{
		if (lis.back() < arr[i])
			lis.push_back(arr[i]);
		else
		{
			int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[index] = arr[i];
		}
	}
	cout << lis.size();
}