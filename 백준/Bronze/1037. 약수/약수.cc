#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A, N=1;
	int arr[51];
	int t;// 약수의 갯수
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> A;
		arr[i] = A;
	}
	sort(arr, arr + t);
	N = arr[0] * arr[t - 1];
	cout << N;
}