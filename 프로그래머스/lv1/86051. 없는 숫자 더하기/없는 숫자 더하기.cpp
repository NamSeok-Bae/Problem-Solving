#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visit[11];

int solution(vector<int> numbers) {
    int answer = 0;
    for(auto i : numbers)
    {
        visit[i] = true;
    }
    for(int i=1;i<=9;i++)
    {
        if(visit[i]==false)
        {
            answer+=i;
}
    }
    return answer;
}