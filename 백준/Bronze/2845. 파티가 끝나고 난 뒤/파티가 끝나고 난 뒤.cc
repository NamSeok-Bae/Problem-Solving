#include <iostream>


using namespace std;
int L, P;
int arr[6];
int result;

int main()
{
	cin >> L >> P;
	result = L * P;
	for (int i = 0; i < 5;i++)
	{
		cin >> arr[i];
		cout << arr[i]-result << " ";
	}
	return 0;
}