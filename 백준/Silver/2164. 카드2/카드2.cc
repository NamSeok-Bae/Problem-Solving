#include <iostream>
#include <queue>

using namespace std;

queue<int>q;

int main() {
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++)
	{
		q.push(i);
	}
	while (q.size()!=1)
	{
		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front();
}