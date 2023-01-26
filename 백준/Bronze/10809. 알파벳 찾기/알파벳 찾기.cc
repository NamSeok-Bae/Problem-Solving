#include <iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int index;
	for (char a = 'a';a <= 'z';a++)
	{
		index = str.find(a);
		cout << index << " ";
	}
}