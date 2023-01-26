#include <iostream>

using namespace std;

int arr[10];
bool mos[42];
int cnt;

int main()
{
	for (int i = 0;i < 10;i++)
	{
		cin >> arr[i];
		mos[arr[i] % 42] = true;
	}
	for (int i = 0;i < 42;i++)
	{
		if (mos[i])
		{
			cnt++;
		}
	}
	cout << cnt;
}