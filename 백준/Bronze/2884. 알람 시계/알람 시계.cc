#include <iostream>
using namespace std;

int main()
{
	int hour;
	int min;
	cin >> hour >> min;
	if (min - 45 < 0)
	{
		hour -= 1;
		min += 60;
		if (hour < 0)
		{
			hour = 23;
		}
	}
	cout << hour <<" " <<min - 45;
	return 0;
}