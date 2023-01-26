#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ck[102];
int arr[51][11];
vector<int> v;
vector<int> r;
int n;
int last_num;
int out_cnt;
int bit_set;
int score;
int max_score;
void resolve()
{
	score = 0;
	bit_set = 0;
	last_num = 0;
	for(int j=0;j<n;j++)
	{
		while (out_cnt != 3)
		{
			if (last_num > 8)
				last_num = 0;
			if (arr[j][r[last_num]] == 0)
			{
				out_cnt++;
			}
			else
			{
				bit_set = bit_set << arr[j][r[last_num]];
				bit_set = bit_set | (1 << arr[j][r[last_num]] - 1);
			}
			if (bit_set >= 8)
			{
				for (int i = 3; i <= 6; i++)
				{
					if (bit_set & (1 << i))
					{
						score++;
						bit_set = bit_set ^ (1 << i);
					}
				}
			}
			last_num++;
		}
		bit_set = 0;
		out_cnt = 0;
	}
	return;
}

void sol(int i) {
	if (i == 8) {
		while (!r.empty())
		{
			r.pop_back();
		}
		for (int j = 0; j < v.size(); j++)
		{
			if (j != 3)
			{
				r.push_back(v[j]);
			}
			else
			{
				r.push_back(1);
				r.push_back(v[j]);
			}
		}
		resolve();
		max_score = max(max_score, score);
		return;
	}
	for (int j = 2; j <= 9; j++) {
		if (!ck[j]) {
			v.push_back(j);
			ck[j] = true;
			sol(i + 1);
			v.pop_back();
			ck[j] = false;
		}
	}
}

int main() 
{
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i <= 9; i++)
		{
			cin >> arr[j][i];
		}
	}
	sol(0);
	cout << max_score;
}