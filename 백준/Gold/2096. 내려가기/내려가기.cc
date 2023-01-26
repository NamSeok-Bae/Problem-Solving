#include  <stdio.h>
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b) ((a) < (b) ? (a) : (b))
 
int tower[3];
int DpMax[100001][3];
int DpMin[100001][3];
 
int main(void)
{
    int n;
    scanf("%d",&n);
     
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d", &tower[0], &tower[1], &tower[2]);
            
           DpMax[i][0] = Max(DpMax[i-1][0] , DpMax[i-1][1]) + tower[0]; 
           DpMax[i][1] = Max(Max(DpMax[i-1][0] , DpMax[i-1][1]),DpMax[i-1][2]) + tower[1]; 
           DpMax[i][2] = Max(DpMax[i-1][1] , DpMax[i-1][2]) + tower[2]; 
     
           DpMin[i][0] = Min(DpMin[i-1][0] , DpMin[i-1][1]) + tower[0]; 
           DpMin[i][1] = Min(Min(DpMin[i-1][0] , DpMin[i-1][1]),DpMin[i-1][2]) + tower[1]; 
           DpMin[i][2] = Min(DpMin[i-1][1] , DpMin[i-1][2]) + tower[2]; 
     
    }
     
   
     
    printf("%d %d\n", Max(Max(DpMax[n][0],DpMax[n][1]),DpMax[n][2]) ,  Min(Min(DpMin[n][0] , DpMin[n][1]),DpMin[n][2]));
    
     
    return 0;
}