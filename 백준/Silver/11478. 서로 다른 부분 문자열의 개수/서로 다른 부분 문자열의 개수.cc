//
//  11478_서로 다른 부분 문자열의 개수.cpp
//  알고리즘
//
//  Created by 배남석 on 2022/11/01.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    
    string str;
    set<string> s;
    cin>> str;
    
    int size = str.size();
    int n = size;
    
    for(int i=1;i<=size; i++) {
        for(int j=0;j<n;j++) {
            s.insert(str.substr(j,i));
        }
        n -= 1;
    }
    cout<<s.size();
}
