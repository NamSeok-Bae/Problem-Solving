#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a; cin>> a;
        
        int arr[101][101];
        int column[101];
        int row[101];
        int diag_sum = 0;
        int diag_L_sum = 0;
        for(int i=1;i<=100;i++) {
            row[i] = 0;
            column[i] = 0;
        }
        for(int i=1;i<=100;i++) {
            for(int j=1;j<=100;j++) {
                cin>>arr[i][j];
                column[i] += arr[i][j];
                row[j] += arr[i][j];
                
                if(i == j) {
                    diag_sum += arr[i][j];
                }
            }
        }
        
        for(int i=100;i>=1;i--) {
            diag_L_sum += arr[101-i][i];
        }
        
        int result = max(diag_sum, diag_L_sum);
        sort(column, column + 101);
        sort(row, row + 101);
        
        result = max(result, max(column[100], row[100]));
        
        cout<<"#"<<test_case<<" "<< result<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
