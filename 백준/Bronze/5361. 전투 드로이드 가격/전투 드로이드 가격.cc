#include <iostream>

using namespace std;

int main()
{
	int t;
	double a=350.34, b=230.90, c=190.55, d=125.30, e=180.90;
	double A, B, C, D, E;
	double result;
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		result = 0;
		cin >> A >> B >> C >> D >> E;
		result = a * A + b * B + c * C + d * D + e * E;
		cout << fixed;
		cout.precision(2);
		cout << "$" << result << endl;
	}
}