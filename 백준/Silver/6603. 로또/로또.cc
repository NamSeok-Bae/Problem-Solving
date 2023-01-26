#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int arr[6];
int t;
int n;

void search(int k, int m)
{
	if (m == 6)
	{
		for (int i = 0;i < 6;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = k;i < t;i++)
		{
			arr[m] = v[i];
			search(i + 1, m + 1);
		}
	}
}

int main()
{
	while (1)
	{
		cin >> t;
		if (t == 0)
			break;

		for (int i = 0; i < t;i++)
		{
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(),v.end());
		search(0, 0);
		cout << endl;
		v.clear();
	}
	return 0;
}