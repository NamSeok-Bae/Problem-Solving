#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	int J;
	cin >> N;
	string K;

	for (int i = 0; i < N; i++)
	{	

		cin >> K;
		K = K[K.length() - 1];
		J = stoi(K);
		J = J % 2;
		switch (J)
		{
		case 0: cout << "even";
			break;
		case 1: cout << "odd";
			break;
		}
		cout << "\n";
	}
}