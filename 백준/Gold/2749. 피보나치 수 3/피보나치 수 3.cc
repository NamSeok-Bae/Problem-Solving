#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long n, cnt;
int d = 1000000;
vector<int> v;

int main()
{
	cin >> n;
	v.push_back(0);
	v.push_back(1);
	cnt = 1;
	//피사노 주기
	while (1)
	{
		v.push_back((v[cnt] + v[cnt - 1]) % d);
		cnt++;

		if (v[cnt] == 0 && v[cnt - 1] == 1)
			break;
	}
	cout << v[n % cnt];
}