#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
	while (1)
	{
		int cnt1 =0, cnt2=0, cnt3=0, cnt4=0;
		getline(cin, s);
		if (s.size() == 0)
			break;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 48 && s[i] <= 57)
			{
				cnt3++;
			}
			else if (s[i] >= 65 && s[i] <= 90)
			{
				cnt2++;
			}
			else if (s[i] >= 97 && s[i] <= 122)
			{
				cnt1++;
			}
			else if (s[i] == ' ')
			{
				cnt4++;
			}
		}
		cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt4 << endl;
		s.clear();
	}
}