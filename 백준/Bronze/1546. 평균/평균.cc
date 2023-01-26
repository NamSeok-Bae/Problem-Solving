#include <iostream>
using namespace std;

int main()
{
	int m=0; //최댓값
	int a; //과목점수
	double b[1000];
	double sum = 0;
	double ave = 0;
	int n=0; //과목갯수
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		b[i] = a;
		if (m < b[i])
			m = b[i];
	}
	for (int i = 0; i < n;i++)
	{
		sum += (b[i] / m) * 100;
	}
	ave = sum / n;
	cout << ave;
}