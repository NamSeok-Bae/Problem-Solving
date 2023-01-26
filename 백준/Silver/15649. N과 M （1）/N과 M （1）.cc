#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> list;
bool visit[10];

void permutation()
{
	if (list.size() == m)
	{
		for (auto a : list)
			cout << a << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i])
			continue;

		visit[i] = true;
		list.push_back(i);
		permutation();
		visit[i] = false;
		list.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	permutation();
}