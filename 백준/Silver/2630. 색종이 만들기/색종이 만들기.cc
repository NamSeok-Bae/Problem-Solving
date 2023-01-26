#include <iostream>

using namespace std;

int t;
int blue;
int white;
int map[129][129] = { 0 };

void paper(int x,int y, int k)
{
	int sum = 0;
	for (int i = y; i < y + k; i++)
	{
		for (int j = x; j < x + k; j++)
		{
			if (map[i][j]) 
			{
				sum++;
			}
		}
	}

	if (sum == k*k) blue++;
	else if (sum == 0) white++;
	else 
	{
		paper(x, y, k / 2);
		paper(x, y + k / 2, k / 2);
		paper(x + k / 2, y, k / 2);
		paper(x + k / 2, y + k / 2, k / 2);
	}
	return;
}

int main()
{
	cin >> t;
	for (int i = 0; i < t;i++)
	{
		for (int j = 0;j < t;j++)
		{
			cin >> map[i][j];
		}
	}
	paper(0, 0, t);
	cout << white << "\n" << blue << endl;
	return 0;
}