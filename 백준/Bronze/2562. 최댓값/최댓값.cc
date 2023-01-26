#include <iostream>
#include <string>

using namespace std;

int main()
{
	int arr[9];
	int max = 0;
	int h = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
			h = i + 1;
		}
	}
	cout << max << "\n" << h;
}