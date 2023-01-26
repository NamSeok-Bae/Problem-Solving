#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int up, down;
	int sum = 0;
	int result = 0;
	for (int i = 0;i < 4;i++)
	{
		cin >> down >> up;
		sum = sum + up - down;
		result = max(result, sum);
	}
	cout << result;
}