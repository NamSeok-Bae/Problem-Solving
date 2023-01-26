#include <iostream>
#include <string>

using namespace std;

char arr[8][8];
int cnt;
string s;

int main()
{
	for (int i = 0;i < 8;i++)
	{
		cin >> s;
		for (int j = 0;j < 8;j++)
		{
			arr[i][j] = s[j];
		}
	}
	for (int i = 0;i < 8;i += 2)
	{
		for (int j = 0;j < 8;j += 2)
		{
			if (arr[i][j] == 'F') cnt++;
		}
	}
	for (int i = 1;i < 8;i += 2)
	{
		for (int j = 1;j < 8;j += 2)
		{
			if (arr[i][j] == 'F') cnt++;
		}
	}
	cout << cnt;
}