#include <iostream>

using namespace std;

int main()
{
	int A[101] = { 0 };
	int B[101] = { 0 };
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++)
	{
		cin >> B[i];
	}
	A[1] = B[1];
	for (int i = 2;B[i] != NULL;i++)
	{
		A[i] = i * B[i] - (i-1)*B[i - 1];
	}
	for (int i = 1;i <= N;i++)
		cout << A[i] << " ";
}