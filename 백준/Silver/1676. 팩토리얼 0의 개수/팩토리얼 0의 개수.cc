#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
    for(int i=2;i<=N;i++)
    {
        int temp = i;
        while (temp % 5 == 0)
	    {
		    cnt++;
		    temp /= 5;
	    }
    }
	cout << cnt;
}