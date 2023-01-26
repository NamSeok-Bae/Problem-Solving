#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int m, n;
vector<int> v;
long long sum, anger;

int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		sum += a;
	}
	sum -= m;
	sort(v.begin(), v.end()); // 오름차순 정렬
	long long anger = 0;
	for (int i = 0; i < n; i++)
	{
		// 제곱하면 값이 커지니깐 캔디를 더 받고싶은 사람이 많이 가져가도록 하기
		long long min_num = min((long long)v[i], sum / (n - i));
		anger += min_num * min_num;
		sum -= min_num;
	}
	cout << (long long) anger % (long long) pow(2,64);
}