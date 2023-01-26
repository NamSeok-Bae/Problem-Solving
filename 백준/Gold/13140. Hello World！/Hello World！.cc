#include <iostream>
#include <vector>
using namespace std;

int answer, a_first, a_second, arr[8], first, second, sum;
bool check;
bool ck[102];
vector<int> v;

void sol(int i) {
	if (i == 7) {
		for (int i = 0; i < v.size(); i++)
		{
			arr[i] = v[i];
		}
		if (arr[4] == 0 || arr[0] == 0)
			return;
		first = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[2] * 10 + arr[3];
		second = arr[4] * 10000 + arr[3] * 1000 + arr[5] * 100 + arr[2] * 10 + arr[6];
		sum = first + second;
		if (sum == answer)
		{
			check = true;
			a_first = first;
			a_second = second;
		}
		return;
	}

	for (int j = 0; j <= 9; j++) {
		if (!ck[j]) {
			v.push_back(j);
			ck[j] = true;
			sol(i + 1);
			v.pop_back();
			ck[j] = false;
		}
	}
}

int main() {

	cin >> answer;
	sol(0);
	if (check)
	{
		cout << "  " << a_first << "\n+ " << a_second << "\n" << "-------\n";
		if (answer >= 100000)
			cout << " " << answer;
		else
			cout << "  " << answer;
	}
	else
		cout << "No Answer";
}