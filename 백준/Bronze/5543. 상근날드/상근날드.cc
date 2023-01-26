#include <iostream>

using namespace std;

int main()
{
	int b1;
	int w1;
	int b[3];
	int w[2];
	int minb=2000;
	int minw = 2000;
	for (int i = 0; i < 3; i++)
	{
		cin >> b1;
		b[i] = b1;
		if (minb > b[i])
		{
			minb = b[i];
		}
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> w1;
		w[i] = w1;
		if (minw > w[i])
		{
			minw = w[i];
		}
	}
	cout << minb + minw -50<< endl;
	return 0;
}