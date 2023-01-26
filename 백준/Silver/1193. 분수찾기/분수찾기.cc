#include <iostream>

using namespace std;

int main()
{
	int x = 1, y = 1, c = 1;
	int n;
	cin >> n; 
	for (int i = 1; i < n; i++) //n이 1보다 클 때부터 시작
	{
		x = x + c; //최종 x의 값은 2부터 시작
		y = y + (c * -1); 

		if (y == 0)
		{
			y++; //밑에 y의 값이 여기서 결정 된다.
			c *= -1;
		}
		else if (x == 0)
		{
			x++;
			c *= -1;
		}
	}
	cout << y << "/" << x; //n이 1일때 x,y 값이 1이니 1/1
	return 0;
}
