#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	queue<int> q;
	for (int i = 1;i <= N;i++)
	{
		q.push(i);
	}
	cout << "<";
	while (1)
	{
			for (int i = 1;i < M;i++)
			{
				int temp = q.front();
				q.pop();
				q.push(temp);
			}
		cout << q.front();
		q.pop();
		if (q.size() == 0)
			break;
		cout << ", ";
	}
	cout << ">";
}