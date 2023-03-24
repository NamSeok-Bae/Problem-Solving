#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
pair<int, int> shark_point;
int shark_weight = 2;
int eat_point;
int map[21][21];
bool visit[21][21];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int result = 0;

struct cmp {
    bool operator() (pair<int, pair<int,int>> A, pair<int, pair<int,int>> B) {
        if(A.first != B.first) {
            return A.first > B.first;
        }
        
        if(A.second.first != B.second.first) {
            return A.second.first > B.second.first;
        }
        
        return A.second.second > B.second.second;
    }
};

void BFS() {
    queue<pair<int, pair<int, int>>> q;
    bool visit[21][21] = {false};
    q.push({0, shark_point});
    visit[shark_point.first][shark_point.second] = true;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, cmp> pq;
    
    while(!q.empty()) {
        pair<int, pair<int,int>> cur = q.front();
        q.pop();
        
        if(map[cur.second.first][cur.second.second] != 0 && map[cur.second.first][cur.second.second] < shark_weight) {
            pq.push({cur.first, {cur.second}});
        }
        
        for(int i=0; i<4; i++) {
            int nx = cur.second.second + dx[i];
            int ny = cur.second.first + dy[i];
            
            if(nx >= 0 && nx < n && ny>=0 && ny<n && map[ny][nx] <= shark_weight && visit[ny][nx] == false) {
                visit[ny][nx] = true;
                q.push({cur.first + 1, {ny, nx}});
            }
        }
    }
    
    if(!pq.empty()) {
        pair<int, pair<int,int>> cur = pq.top();
        pq.pop();
        map[shark_point.first][shark_point.second] = 0;
        map[cur.second.first][cur.second.second] = 0;
        result += cur.first;
        shark_point = cur.second;
        
        if(eat_point + 1 == shark_weight) {
            eat_point = 0;
            shark_weight++;
        } else {
            eat_point++;
        }
    }
}

int main() {
    cin>>n;
    
    for(int i=0; i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>map[i][j];
            
            if(map[i][j] == 9) {
                map[i][j] = 0;
                shark_point = {i, j};
            }
        }
    }
    
    while(true) {
        int temp = result;
        BFS();
        if(temp == result) {
            break;
        }
    }
    cout<<result;
}
