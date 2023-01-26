#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string s;
vector<string> v;

int main()
{
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		string srr;
		for (int j = i;j < s.size();j++)
		{
			srr += s[j];
		}
		v.push_back(srr);
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size();i++)
	{
		cout << v[i] << endl;
	}
}