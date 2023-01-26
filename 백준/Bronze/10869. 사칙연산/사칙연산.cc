#include <iostream>

using namespace std;

class CTest
{
public:
	CTest()
	{
		cin >> a >> b;
	}
	int a, b;
	void printdata()
	{
		cout << a + b << endl;
		cout << a - b << endl;
		cout << a * b << endl;
		cout << a / b << endl;
		cout << a % b << endl;
	}
};

int main()
{
	CTest t;
	t.printdata();
	return 0;
}