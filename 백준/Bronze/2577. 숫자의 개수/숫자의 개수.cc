#include <iostream>
using namespace std;

int main()
{
	int a=0, b=0, c=0;
	int count0=0,count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
	int result;
	int d; // 나머지
	cin >> a>>b>>c;
	result = a * b * c;
	while (1)
	{
		d = result % 10;
		result = result / 10;
		if (d == 0)
		{
			count0 += 1;
		}
		else if (d == 1)
		{
			count1 += 1;
		}
		else if (d == 2)
		{
			count2 += 1;
		}
		else if (d == 3)
		{
			count3 += 1;
		}
		else if (d == 4)
		{
			count4 += 1;
		}
		else if (d == 5)
		{
			count5 += 1;
		}
		else if (d == 6)
		{
			count6 += 1;
		}
		else if (d == 7)
		{
			count7 += 1;
		}
		else if (d == 8)
		{
			count8 += 1;
		}
		else if (d == 9)
		{
			count9 += 1;
		}
		if (result == 0)
		{
			break;
		}
	}
	cout << count0 << endl;
	cout << count1 << endl;
	cout << count2 << endl;
	cout << count3 << endl;
	cout << count4 << endl;
	cout << count5 << endl;
	cout << count6 << endl;
	cout << count7 << endl;
	cout << count8 << endl;
	cout << count9 << endl;
	return 0;
}