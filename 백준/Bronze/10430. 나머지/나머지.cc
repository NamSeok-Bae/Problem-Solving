#include <iostream>

using namespace std;

class CTest
{
public:
	CTest()
	{
		cin >> a >> b>>c;
	}
	int a, b, c;

	void printdata()
	{
		cout << (a + b) % c << endl;
		cout << (a % c + b % c) % c << endl;
		cout << (a * b) % c << endl;
		cout << (a % c * b % c) % c << endl;
	}
};

int main()
{
	CTest t;
	t.printdata();
	return 0;
}