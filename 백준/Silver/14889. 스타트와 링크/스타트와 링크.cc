#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
int bit_set;
int arr[21][21];
int temp = 10000;
int in_num;
void combination(int i,int c)
{
	if (c == in_num) {
		vector<int> v;
		vector<int> v2;
		int sum = 0;
		int sum2 = 0;
		for (int k = 1; k <= n; k++)
		{
			if (bit_set & (1 << k-1))
			{
				v.push_back(k);
			}
		}
		for (int k = 1; k <= n; k++)
		{
			if (~bit_set & (1 << k - 1))
			{
				v2.push_back(k);
			}
		}
		for (int k = 0; k < v.size(); k++)
		{
			for (int j = k+1; j < v.size(); j++)
			{
				sum += arr[v[k]][v[j]] + arr[v[j]][v[k]];
			}
		}
		for (int k = 0; k < v2.size(); k++)
		{
			for (int j = k + 1; j < v2.size(); j++)
			{
				sum2 += arr[v2[k]][v2[j]] + arr[v2[j]][v2[k]];
			}
		}
		temp = min(temp, abs(sum - sum2));
		return;
	}
	if (i > n)
		return;
	bit_set |= (1 << i-1);
	combination(i + 1, c + 1);
	bit_set &= ~(1 << i-1);
	combination(i + 1, c);
	return;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
	in_num = n / 2;
	combination(1, 0);
	cout << temp;
}