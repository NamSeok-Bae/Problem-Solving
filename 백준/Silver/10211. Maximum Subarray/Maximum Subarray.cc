#include <iostream>

using namespace std;


int arr[1001];
int sum[1001] = { 0 };
int n;//포문 갯수

int main()
{
	int t;//테스트 케이스
	cin >> t;
	while(t--)
	{
		int max = -21321414;
		cin >> n;
		for (int i = 1; i <= n;i++)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i;j <= n;j++)
			{
				if (max < sum[j] - sum[i - 1]) max = sum[j] - sum[i - 1];
			}
		}
		cout << max << endl;
	}
}