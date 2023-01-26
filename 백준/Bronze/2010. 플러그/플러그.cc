#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int t;
	int m = 0;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> t;
		m += t;
	}
	cout << m-N+1;
}