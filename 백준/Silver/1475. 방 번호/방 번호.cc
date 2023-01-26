#include <iostream>

using namespace std;

int n;
int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
int cnt[9];
int max_cnt;
int main()
{
	cin >> n;
	while (n != 0)
	{
		int temp = n % 10;
		n /= 10;
		if (temp == 6 || temp == 9)
			cnt[6]++;
		else
			cnt[temp]++;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == 6)
		{
			max_cnt = max(max_cnt, (cnt[6] + 1) / 2);
		}
		else
			max_cnt = max(max_cnt, cnt[i]);
	}
	cout << max_cnt;
}