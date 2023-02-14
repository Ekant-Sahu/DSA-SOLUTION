#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9


const int N = 1000000;
const int m = 1000000007;
//recersive implementation

int main(){
    //iterative implementaion
    vector<vector<long long>> dp(N,vector<long long>(8,0));
    for (int i = 0; i < 8; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(j == 0 || j == 2 || j == 3 || j == 4 || j==5)
                dp[i][j] = (dp[i-1][0]+dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5])%m;
            else{
                dp[i][j] = (dp[i-1][2]+dp[i-1][6]+ dp[i-1][7])%m;
            } 
        }
        
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n-1][2] + dp[n-1][6])%m<<endl;
    } 
    return 0;
}
    
