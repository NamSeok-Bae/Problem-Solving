#include <iostream>

using namespace std;

int main()
{
	int N, M,K;
	int sum = 0;
	int arr[301][301];
	cin >> N >> M;
	for (int a = 1;a <= N;a++)
	{
		for (int b = 1;b <= M;b++)
		{
			cin >> arr[a][b];
		}
	}
	cin >> K;
	int i, j, x, y, o;
	for (int c = 0;c < K;c++)
	{
		cin >> i >> j >> x >> y;
		for (i;i <= x;i++)
		{
			for (o=j;o <= y;o++)
			{
				sum += arr[i][o];
			}
			o = j;
		}
		cout << sum<<endl;
		sum = 0;
	}
}