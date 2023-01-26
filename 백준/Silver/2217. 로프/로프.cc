#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n;
int m;
int i;
vector<int> v;


int main()
{
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	while (1)
	{
		if (m < v[i] * t)
		{
			m = v[i] * t;
		}
		i++;
		t--;
		if (t == 0)
			break;
	}
	cout << m << endl;
	return 0;
}