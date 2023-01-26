#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, M{ -2 };
int map[1001][1001];
int visit[1001][1001];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue <pair<int, int>> Q;


void reset() { // visit 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = 0;
        }
    }
}
void bfs() {
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if ((map[nx][ny] == 0 || map[nx][ny] > map[x][y]) && visit[nx][ny] == 0) {
                map[nx][ny] = map[x][y] + 1;
                visit[nx][ny] = 1;
                Q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int cnt{ 0 };
    cin >> m >> n;

    for (int i = 0; i < n; i++) { //입력
        for (int j = 0; j < m; j++) {
            int a; cin >> a;
            if (a == 0) cnt++;
            map[i][j] = a;
        }
    }

    for (int i = 0; i < n; i++) { //익은토마토 있을때 탐색 시작
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visit[i][j] == 0) {
                Q.push({i,j});
                visit[i][j] = 1;
            }
        }
    }
    bfs();
    if (cnt == 0) { cout << 0; return 0; } // 처음부터 0인 토마토가 없으면 0출력
    for (int i = 0; i < n; i++) { //최대값 or 0이 남아있으면 -1 출력
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) { cout << -1; return 0; }
            if (map[i][j] > M) M = map[i][j];
        }
    }

    cout << M - 1;
}