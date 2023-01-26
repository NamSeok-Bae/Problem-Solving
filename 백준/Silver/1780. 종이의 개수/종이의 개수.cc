#include <iostream>

using namespace std;

int t;
int f_cnt;
int s_cnt;
int t_cnt;
int arr[2188][2188];

void paper(int x, int y, int n)
{
	int fsum = 0;
	int ssum = 0;
	int tsum = 0;
	for (int i = y;i <y+ n;i++)
	{
		for (int j = x;j <x+ n;j++)
		{
			if (arr[i][j] == 1)
			{
				tsum++;
			}
			else if (arr[i][j] == 0)
			{
				ssum++;
			}
			else {
				fsum++;
			}
		}
	}
	if (tsum == n * n) t_cnt++;
	else if (ssum == n * n) s_cnt++;
	else if (fsum == n*n) f_cnt++;
	else {
		paper(x, y, n / 3);
		paper(x + n / 3, y, n / 3);
		paper(x + (n / 3) * 2, y, n / 3);
		paper(x, y + n / 3, n / 3);
		paper(x + n / 3, y + n / 3, n / 3);
		paper(x + 2 * (n / 3), y + n / 3, n / 3);
		paper(x, y + 2 * (n / 3), n / 3);
		paper(x + n / 3, y + 2 * (n / 3), n / 3);
		paper(x + 2 * (n / 3), y + 2 * (n / 3), n / 3);
	}
	return;
}

int main()
{
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		for (int j = 0;j < t;j++)
		{
			cin >> arr[i][j];
		}
	}
	paper(0, 0, t);
	cout << f_cnt << "\n" << s_cnt << "\n" << t_cnt << endl;
}