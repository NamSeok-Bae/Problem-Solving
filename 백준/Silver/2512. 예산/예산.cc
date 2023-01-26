#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long int m;
vector<long long int> v;
long long int mx;
long long int ans;
long long int temp;
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		long long int a;
		cin >> a;
		v.push_back(a);
		mx = max(mx, a);
	}
	cin >> m;
	long long int left = 0;
	while (left<=mx)
	{
		long long int sum = 0;
		long long int mid = (left + mx) / 2;
		for (int i = 0; i < n; i++)
		{
			long long int a;
			if (v[i] >= mid)
				 a = mid;
			else
			{
				a = v[i];
			}
			sum += a;
		}
		if (sum > m)
		{
			mx = mid - 1;
		}
		else
		{
			ans = mid;
			left = mid + 1;
		}
		temp = max(temp, ans);
	}
	cout << temp;
}