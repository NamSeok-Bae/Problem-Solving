#include <iostream>

using namespace std;

class CTest
{
public:
	CTest()
	{
		cin >> a >> b;
	}
	double a, b;
	double result;
	void printdata()
	{
		result = a / b;
		cout.precision(15);
		cout << result << endl;
	}
};

int main()
{
	CTest t;
	t.printdata();
	return 0;
}