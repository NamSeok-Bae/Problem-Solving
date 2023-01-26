#include <iostream>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for (int i = 1; i <=testcase; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << "Case #"<<i<<": "<<a<<" + "<<b<<" = "<<a + b << "\n";
	}
	return 0;
}