#include <iostream>

using namespace std;

int sum[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, arr;
	int i, j;
	cin >> N >> M;
	for (int x = 1; x <= N; x++)
	{
		cin >> arr;
		sum[x] = sum[x - 1] + arr;
	}
	for (int y = 0; y < M; y++)
	{
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";
	}
}