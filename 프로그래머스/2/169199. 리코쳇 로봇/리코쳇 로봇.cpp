#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    pair<int,int> goal;
    int map[101][101];
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    queue<pair<int,int>> q;
    for(int i=0;i<n; i++) {
        for(int j=0;j<m; j++) {
            map[i][j] = 987654321;
            
            if(board[i][j] == 'R') {
                q.push({i, j});
                map[i][j] = 0;
            } else if(board[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(q.front() == goal) { continue; }
        
        for(int i=0;i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny>=0 && ny<n && nx >=0 && nx <m && board[ny][nx] != 'D') {
                while(true) {
                    if(ny>=0 && ny<n && nx >=0 && nx <m && board[ny][nx] != 'D') {
                        ny += dy[i];
                        nx += dx[i];
                    } else {
                        ny -= dy[i];
                        nx -= dx[i];
                        break;
                    }
                }
                
                if(map[ny][nx] > map[y][x] + 1) {
                    map[ny][nx] = map[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
    
    return map[goal.first][goal.second] == 987654321 ? -1 : map[goal.first][goal.second];
}
