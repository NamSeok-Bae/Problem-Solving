#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isP(char c) {
    return c == 'p' || c == 'P';
}

bool isY(char c) {
    return c == 'y' || c == 'Y';
}

bool solution(string s)
{
    bool answer = true;
    int p_cnt = count_if(s.begin(), s.end(), isP);
    int y_cnt = count_if(s.begin(), s.end(), isY);

    return p_cnt == y_cnt;
}