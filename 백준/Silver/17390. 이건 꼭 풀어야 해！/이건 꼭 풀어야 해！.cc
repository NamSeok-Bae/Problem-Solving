#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q, l , r;
vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	vector<int> arr(n + 1);
	arr[1] = v[1];
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + v[i];

	while (q--)
	{
		cin >> l >> r;
		cout << arr[r] - arr[l - 1] << '\n';
	}
	return 0;
}