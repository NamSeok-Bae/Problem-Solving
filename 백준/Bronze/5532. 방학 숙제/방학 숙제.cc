#include <iostream>

using namespace std;

int main()
{
	int L, A, B, a, b,result;

	cin >> L >> A >> B >> a >> b;
	
	if (A%a == 0) //남은 일수를 계산하기 위해 A % a 를 하여 나머지를 구합니다.
	{
		A = A / a;
	}
	else //나누어 떨어지지않았기 떄문에 하루 더 숙제를 해야합니다.
	{
		A = A / a + 1;
	}
	if (B%b == 0) //남은 일수를 계산하기 위 해 B % b 를 하여 나머지를 구합니다.
	{
		B = B / b;
	}
	else //나누어 떨어지지않았기 떄문에 하루 더 숙제를 해야합니다.
	{
		B = B / b + 1;
	}
	if (A >= B)
	{
		result = A;
	}
	else
	{
		result = B;
	}
	cout << L - result;
}