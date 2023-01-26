#include <iostream>

using namespace std;

bool check[1001];
int main()
{
	int N, K;
	int cnt = 0;
	int temp = 0;
	bool end = false;
	cin >> N >> K;
	check[1] = true;
	for (int i = 2; i <= N; i++)
	{
		for (int j = i; j <= N; j += i)
		{
			if (check[j] == false)
			{
				check[j] = true;
				cnt++;
			}
			if (cnt == K)
			{
				cout << j;
				end = true;
				break;
			}
		}
		if (end)
			break;
	}
}