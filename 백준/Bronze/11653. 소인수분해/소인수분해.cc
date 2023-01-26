#include <iostream>

using namespace std;

int N;
int i = 2;

int main()
{
	cin >> N;
	while (N != 1)
	{
		while (N % i == 0)
		{
			cout << i << endl;
			N /= i;
		}
		i++;
	}
}