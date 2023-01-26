#include<iostream>
#include<queue>
using namespace std;

int n,temp,result;
priority_queue<int,vector<int>,greater<int>> q;

int main()
{
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		q.push(t);
	}
	while (q.size()!=1)
	{
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		temp = a + b;
		result += temp;
		q.push(temp);
	}
	cout << result;
}