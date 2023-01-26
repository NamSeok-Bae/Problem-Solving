#include <iostream>

using namespace std;

int main()
{
	int total[5];
	int n1, n2, n3, n4;
	int max=0;
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> n1 >> n2 >> n3 >> n4;
		total[i] = n1 + n2 + n3 + n4;
		if (total[i] > max)
		{
			max = total[i];
			count = i + 1;
		}
	}
	cout << count << " " << max;

	return 0;
}