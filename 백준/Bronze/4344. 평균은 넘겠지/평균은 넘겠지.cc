#include <iostream>

using namespace std;

int main()
{
	int a[1000];//천명의 학생 점수배열
	double ave=0;//학생배열 평균
	int t;// 테스트 개수
	int p;//사람 수
	int pcount=0;//평균보다 높은 사람수 구하기
	double per;//퍼센테이지 구하기
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			cin >> a[j];
			ave += a[j]; //평균 구하기위한 총합구하기
		}
		ave = ave / (double)p; // 평균
		for (int j = 0;j < p;j++)
		{
			if (a[j] > ave)
				pcount++;
		}
		per = ((double)pcount / (double)p) * 100;
		cout << fixed;
		cout.precision(3);
		cout << per <<"%"<< endl;
		pcount = 0;
		ave = 0;
	}
}