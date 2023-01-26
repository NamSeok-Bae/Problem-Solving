#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int mx = min(w - x, x);
	int my = min(h - y, y);
	int mm = min(mx, my);
	cout << mm;
}