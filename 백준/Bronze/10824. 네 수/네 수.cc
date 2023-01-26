#include <iostream>
#include <string>

using namespace std;
int a, b, c, d;
string s, s2;

int main()
{
	cin >> a >> b >> c >> d;
	s += to_string(a);
	s += to_string(b);
	s2 += to_string(c);
	s2 += to_string(d);

	long long temp = stoll(s);
	temp += stoll(s2);
	cout << temp;
}