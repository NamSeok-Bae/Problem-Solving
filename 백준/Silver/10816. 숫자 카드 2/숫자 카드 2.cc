#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	cin >> m;
	while (m--)
	{
		int k;
		cin >> k;
		cout << ((upper_bound(v.begin(), v.end(), k)-v.begin())-(lower_bound(v.begin(), v.end(), k) - v.begin())) << " ";
	}
}