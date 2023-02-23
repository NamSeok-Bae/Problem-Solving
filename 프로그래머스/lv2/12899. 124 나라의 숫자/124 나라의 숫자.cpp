#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n!=0)
    {
        int rest = n%3;
        n = n/3;
        if(rest==0)
        {
            answer+="4";
            n--;
        }
        else
        {
            answer+=rest + '0';
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}