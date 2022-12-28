#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9


const int N = 505;
const int m = 1000000007;
// int solve(int a, int b){
//     if(a==b){
//         return moves;
//     }
//     else{
//         if(a>b){
//             cout<<a-b<<" "<<b<<endl;
//             moves = moves + 1 + solve(a-b,b);
//         }
//         else{
//             cout<<a<<" "<<b-a<<endl;
//             moves = moves + 1 + solve(a,b-a);
//         }
//         return moves;
//     }
// }



int dp[N][N];
//recersive implementation

int main(){
    //iterative implementaion
    int w,h;
    cin>>w>>h;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            dp[i][j] = INF;
        }
        
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            for(int cut = 1; cut<i; cut++){
                dp[i][j] = min(dp[i][j], dp[cut][j] + dp[i-cut][j]+1);
            }
            for(int cut = 1; cut<j; cut++){
                dp[i][j] = min(dp[i][j], dp[i][cut] + dp[i][j-cut]+1);
            }
        }
        
    }
    cout<<dp[w][h];
    return 0;
}
    
