#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> v;
vector<char>list;
int j_cnt;
int m_cnt;

void combination(vector<char> v,int i,int c,int j_cnt,int m_cnt)
{
	if (j_cnt >= L - 1)
		return;
	else if (m_cnt >= L)
		return;
	if (list.size() == L && j_cnt <=L-2 && m_cnt <=L-1)
	{
		for (auto u : list)
			cout << u;
		cout << endl;
	}
	if (j_cnt + m_cnt == L)
		return;
	if (i >= C)
		return;
	list.push_back(v[i]);
	if (v[i] == 'a' || v[i] == 'e' || v[i] == 'u' || v[i] == 'o' || v[i] == 'i')
		j_cnt++;
	else
		m_cnt++;
	combination(v, i + 1, c + 1,j_cnt,m_cnt);
	list.pop_back();
	if (v[i] == 'a' || v[i] == 'e' || v[i] == 'u' || v[i] == 'o' || v[i] == 'i')
		j_cnt--;
	else
		m_cnt--;
	combination(v, i + 1, c, j_cnt, m_cnt);
}
int main()
{
	cin >> L >> C;
	for(int i=0;i<C;i++)
	{
		char a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	combination(v,0,0,0,0);
}