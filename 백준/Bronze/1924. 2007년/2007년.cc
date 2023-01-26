#include <iostream>
using namespace std;

int main()
{
	int month_;
	int day_=0;
	cin >> month_ >> day_;
	for (int i = 1; i < month_; i++)
	{
		if (i == 1 || i== 3 ||i== 5 || i== 7 || i==8||i==10||i==12)
		{
			day_ += 31;
		}
		else if (i == 4||i== 6||i== 9||i== 11)
		{
			day_ += 30;
		}
		else if (i == 2)
		{
			day_ += 28;
		}
	}
	int dayofweek = day_ % 7;
	//요일 정하는 조건문
	if (dayofweek == 0)
	{
		cout << "SUN";
	}
	else if (dayofweek == 1)
	{
		cout << "MON";
	}
	else if (dayofweek == 2)
	{
		cout << "TUE";
	}
	else if (dayofweek == 3)
	{
		cout << "WED";
	}
	else if (dayofweek == 4)
	{
		cout << "THU";
	}
	else if (dayofweek == 5)
	{
		cout << "FRI";
	}
	else if (dayofweek == 6)
	{
		cout << "SAT";
	}
	return 0;
}