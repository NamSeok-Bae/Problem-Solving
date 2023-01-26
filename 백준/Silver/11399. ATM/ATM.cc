#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum[1000];
int t;
int n;
int result;
vector <int> v;
int main()
{
	cin >> t;
	for (int i = 0; i < t;i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < t;i++)
	{
		sum[i+1] = sum[i] + v[i];
	}
	for (int i = 1;i <= t;i++)
	{
		result += sum[i];
	}
	cout << result;
}