#include <iostream>
#include <string>

using namespace std;

int t; 
int n;
string s;
int arr[64][64];


void tree(int x, int y,int k)
{
	bool check = true;
	for (int i = x;i < x + k;i++)
	{
		for (int j = y;j < y + k;j++)
		{
			if (arr[x][y] != arr[i][j])
			{
				check = false;
				break;
			}
		}
		if (!check)
			break;
	}
	if (check)
	{
		if (arr[x][y] == 0)
		{
			cout << 0;
			return;
		}
		else if (arr[x][y] == 1)
		{
			cout << 1;
			return;
		}
	}
	else {
		cout << "(";
		tree(x, y, k / 2);
		tree(x, y + k / 2, k / 2);
		tree(x + k / 2, y, k / 2);
		tree(x + k / 2, y + k / 2, k / 2);
		cout << ")";
	}
	return;
}

int main()
{
	cin >> t;
	for (int i = 0; i < t;i++)
	{
		cin >> s;
		for (int j = 0;j < t;j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	tree(0,0,t);
	return 0;
}