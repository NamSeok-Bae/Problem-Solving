#include <iostream>
#include <string>

using namespace std;

int w, l, g;
int n, p;
int score;
string s[1001];
bool check;
bool name;
char a[1001];
string b[1001];

int main()
{
	cin >> n >> p;
	cin >> w >> l >> g;

	for (int i = 0;i < p;i++)
	{
		cin >> s[i] >> a[i];
	}
	for (int i = 0;i < n;i++)
	{
		cin >> b[i];
	}
	for (int i = 0;i < n;i++)
	{
		name = false;
		for (int j = 0;j < p;j++)
		{
			if (b[i] == s[j] && a[j] == 'W')
			{
				score += w;
				name = true;
				break;
			}
			else if (b[i] == s[j] && a[j] == 'L')
			{
				score -= l;
				name = true;
				break;
			}
		}
		if (!name)
		{
			score -= l;
		}

		if (score < 0)
			score = 0;
		if (score >= g)
			check = true;
	}
	if (check)
		cout << "I AM NOT IRONMAN!!" << endl;
	else
		cout << "I AM IRONMAN!!" << endl;
	return 0;
}