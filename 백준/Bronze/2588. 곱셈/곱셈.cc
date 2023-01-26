#include <iostream>

using namespace std;

class CTest
{
public:
	CTest()
	{
		cin >> a >> b;
	}
	int a, b,c;
	int result1, result2, result3;
	int sum;

	void printdata()
	{	
		result1 = a * (b % 10);
		c = b % 10;
		b -= c;
		result2 = (a * (b % 100))/10;
		c = b % 100;
		b -= c;
		result3 = (a * b)/100;
		
		sum = result1 + (result2 * 10) + (result3 * 100);
		cout << result1 << "\n" << result2 << "\n" << result3 << "\n" << sum;
	}
};

int main()
{
	CTest t;
	t.printdata();
	return 0;
}