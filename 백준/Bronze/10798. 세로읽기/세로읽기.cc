#include <iostream>

using namespace std;

int main()
{
	char arr[5][15];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			arr[i][j] = NULL;
		}
	}

	char N;

	for (int i = 0; i < 5; i++)
	{

		cin >> arr[i];

	}

	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (arr[i][j] == NULL)
				continue;
			else
				cout << arr[i][j];
		}
	}
	
}