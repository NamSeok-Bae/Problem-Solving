#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
string W[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW" };
string B[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
int cntB;
int cntW;
int result;
int arr = 64;
string s[51];

int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> s[i];
	}
	for (int a = 0;a <= n - 8;a++)
	{
		for (int b = 0;b <= m - 8;b++)
		{
			for (int i = 0;i < 8;i++)
			{
				for (int j = 0;j < 8;j++)
				{
					if (s[i + a][j + b] != B[i][j])
					{
						cntB++;
					}
					if (s[i + a][j + b] != W[i][j])
					{
						cntW++;
					}
				}
			}
			result = min(cntB, cntW);
			cntB = 0;
			cntW = 0;
			arr = min(arr, result);
		}
	}
	cout << arr;
}