#include <iostream>
#include <string>

using namespace std;

string s;
string result;
long long n;

int main()
{
	for (int i = 0;i < 3;i++)
	{

		cin >> s;
		if (i <= 1)
		{
			if (s == "black")
			{
				result += '0';
			}
			else if (s == "brown")
			{
				result += '1';
			}
			else if (s == "red")
			{
				result += '2';
			}
			else if (s == "orange")
			{
				result += '3';
			}
			else if (s == "yellow")
			{
				result += '4';
			}
			else if (s == "green")
			{
				result += '5';
			}
			else if (s == "blue")
			{
				result += '6';
			}
			else if (s == "violet")
			{
				result += '7';
			}
			else if (s == "grey")
			{
				result += '8';
			}
			else if (s == "white")
			{
				result += '9';
			}
		}
		else
		{
			n = stoi(result);
			if (s == "black")
			{
				n *= 1;
			}
			else if (s == "brown")
			{
				n *= 10;
			}
			else if (s == "red")
			{
				n *= 100;
			}
			else if (s == "orange")
			{
				n *= 1000;
			}
			else if (s == "yellow")
			{
				n *= 10000;
			}
			else if (s == "green")
			{
				n *= 100000;
			}
			else if (s == "blue")
			{
				n *= 1000000;
			}
			else if (s == "violet")
			{
				n *= 10000000;
			}
			else if (s == "grey")
			{
				n *= 100000000;
			}
			else if (s == "white")
			{
				n *= 1000000000;
			}
		}
	}
	cout << n;
}