#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int result = 10;
	cin >> a;
	for (int i = 1;a[i] != NULL;i++)
	{
		if (a[i] == a[i - 1])
		{
			result += 5;
		}
		if (a[i] != a[i - 1])
		{
			result += 10;
		}
	}
	cout << result;
}