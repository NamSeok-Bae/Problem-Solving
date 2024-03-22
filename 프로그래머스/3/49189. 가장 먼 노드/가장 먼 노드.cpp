#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[20001];
bool visited[20001];
vector<int> v[20001];
queue<int> q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=2;i<=n;i++) {
        arr[i] = 987654321;
    }
    
    for(int i=0;i<edge.size();i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        
        for(int i=0;i<v[top].size();i++) {
            int a = v[top][i];
            if(visited[a] == false) {
                arr[a] = arr[top] + 1;
                visited[a] = true;
                q.push(a);
            }
        }
    }
    
    int max_num = 0;
    for(int i=2;i<=n;i++) {
        if(max_num == arr[i]) {
            answer++;
        }
        
        if(max_num < arr[i]) {
            max_num = arr[i];
            answer = 1;
        }
    }
    
    return answer;
}