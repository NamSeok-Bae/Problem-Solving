#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a; cin>> a;
        int arr[101][101];
        vector<pair<int,int>> v;
        for(int i=1;i<=100;i++) {
            for(int j=1;j<=100;j++) {
                cin>>arr[i][j];
                if(i==1 && arr[i][j] == 1) {
                    v.push_back({i, j});
                }
            }
        }
        int min_dist = 987654321;
        int min_x = 0;
        for(int i=0;i<v.size();i++) {
            int ny = v[i].first;
            int nx = v[i].second;
            bool visited[101][101];
            for(int i=1;i<=100;i++) {
                for(int j=1;j<=100;j++) {
                    visited[i][j] = false;
                }
            }
            
            queue<pair<int,pair<int,int>>> q;
            q.push({0,{ny, nx}});
            while(!q.empty()) {
                int dist = q.front().first;
                int y = q.front().second.first;
                int x = q.front().second.second;
                visited[y][x] = true;
                q.pop();
                if(y == 100) {
                    if(min_dist >= dist) {
                        min_dist = dist;
                        min_x = nx;
                    }
                    break;
                }
                if(x + 1 <= 100 && arr[y][x+1] == 1 && visited[y][x+1] == false) {
                    q.push({dist+1, {y, x+1}});
                } else if(x - 1 >= 0 && arr[y][x-1] == 1 && visited[y][x-1] == false) {
                    q.push({dist+1, {y, x-1}});
                } else if(y + 1 <= 100 && arr[y+1][x] == 1 && visited[y+1][x] == false) {
                    q.push({dist+1, {y+1, x}});
                }
            }
        }
        cout<<"#"<<test_case<<" "<<min_x -1 <<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
