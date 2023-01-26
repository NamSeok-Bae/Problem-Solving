#include <iostream>
#include <queue>
#include<cmath>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b))
			return abs(a)>abs(b);
		else if (abs(a) == abs(b))
		{
			return a > b;
		}
		return false;
	}
};
int n;
priority_queue<int,vector<int>,cmp> pq;
vector<int> v;

int main()
{
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		if (a != 0)
		{
			pq.push(a);
		}
		else
		{
			if (!pq.empty())
			{
				cout << pq.top() << endl;
				pq.pop();
			}
			else
				cout << 0 << endl;
		}
	}
}