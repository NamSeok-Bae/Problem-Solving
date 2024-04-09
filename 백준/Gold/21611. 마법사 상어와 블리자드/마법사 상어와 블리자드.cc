#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    int arr[51][51] = {0, };
    list<int> li;
    int result = 0;
    int shark_y = (n+1)/2;
    int shark_x = (n+1)/2;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>arr[i][j];
        }
    }
    
    int cnt = 1;
    int map[52][52] = {0, };
    int y = shark_y, x = shark_x;
    arr[y][x] = -1;
    map[y][x] = 1;
    int up_down_count = 1, left_right_count = 1;
    
    for( int i=0;i<n*n; i++) {
        switch (i%4) {
            case 0: // 좌
                if(y < 1 || y > n || x < 1 || x > n) break;
                for(int i=0;i<left_right_count;i++) {
                    x--;
                    map[y][x] = ++cnt;
                    if(arr[y][x] != 0)
                        li.push_back(arr[y][x]);
                }
                left_right_count++;
                break;
            case 1: // 하
                if(y < 1 || y > n || x < 1 || x > n) break;
                for(int i=0;i<up_down_count;i++) {
                    y++;
                    map[y][x] = ++cnt;
                    if(arr[y][x] != 0)
                        li.push_back(arr[y][x]);
                }
                up_down_count++;
                break;
            case 2: // 우
                if(y < 1 || y > n || x < 1 || x > n) break;
                for(int i=0;i<left_right_count;i++) {
                    x++;
                    map[y][x] = ++cnt;
                    if(arr[y][x] != 0)
                        li.push_back(arr[y][x]);
                }
                left_right_count++;
                break;
            case 3: // 상
                if(y < 1 || y > n || x < 1 || x > n) break;
                for(int i=0;i<up_down_count;i++) {
                    y--;
                    map[y][x] = ++cnt;
                    if(arr[y][x] != 0)
                        li.push_back(arr[y][x]);
                }
                up_down_count++;
                break;
        }
    }
    
    for(int i=1;i<=m;i++) {
        int d,s; cin>>d>>s;
        
        int y = shark_y, x = shark_x;
        for(int j=0;j<s;j++) {
            y += dy[d];
            x += dx[d];
            
            if(!(y >= 1 && y <= n && x >= 1 && x <= n)) {
                break;
            }
            
            int idx = map[y][x];
            if(li.size() + 1 < idx) {
                break;
            }
            list<int>::iterator it = li.begin();
            for(int k=0;k< idx - 2 - j; k++) {
                it++;
            }
            
            li.erase(it);
        }
        
        list<int>::iterator it = li.begin();
        bool isExplosion = false;
        while(true) {
            if(it == li.end() || li.empty()) {
                if(!isExplosion) {
                    break;
                }
                isExplosion = false;
                it = li.begin();
                continue;
            }
            
            int number = *it;
            int cnt = 0;
            while(*it == number) {
                cnt++;
                it++;
            }
            
            if(cnt >= 4) {
                result += number * cnt;
                isExplosion = true;
                it--;
                while(cnt--) {
                    li.erase(it--);
                }
                it++;
            }
        }
        
        it = li.begin();
        while(it != li.end()) {
            int number = *it;
            int cnt = 0;
            while(*it == number) {
                cnt++;
                it++;
            }
            it--;
            for(int i=0;i<cnt;i++) {
                li.erase(it--);
            }
            it++;
            li.insert(it, cnt);
            li.insert(it, number);
        }
        
        while(li.size() > n*n - 1) {
            li.pop_back();
        }
    }
    cout<<result;
}
 