#include <iostream>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for (int i = testcase; i > 0; i--)
	{
		int a, b;
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}