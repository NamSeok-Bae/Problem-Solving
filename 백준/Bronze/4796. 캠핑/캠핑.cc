#include <iostream>
using namespace std;

int l, p,v;
int i;
int main()
{
	while (1)
	{
		i++;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;
		int temp = v / p;
		int ans = v % p;
		
		int sum = temp * l;
		if (ans > l)
		{
			sum += l;
		}
		else
			sum += ans;
		cout << "Case " << i << ": " << sum << endl;
	}
}