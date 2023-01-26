#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int m;
vector<int> v;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> m;
	while (m--)
	{
		int num;
		cin >> num;
		cout << binary_search(v.begin(), v.end(), num) << " ";
	}
}