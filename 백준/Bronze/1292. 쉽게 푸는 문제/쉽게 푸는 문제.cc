#include <iostream>

using namespace std;

int main()
{
	int a[1100];
	int cnt = 1;
	for (int i = 1;i <= 45;i++)
	{
		for (int j = 1; j <= i;j++)
		{
			a[cnt] = i;
			cnt++;
		}
	}
	int s, e;
	int result = 0;
	cin >> s >> e;
	for (int i = s;i <= e;i++)
	{
		result += a[i];
	}
	cout << result;
}