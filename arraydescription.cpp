#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9


const int N = 1000000;
const int m = 1000000007;


int arr[N] = {2,0,2};


//recersive implementation






int main(){
    //iterative implementaion
    int n = 3;
    int m = 5;
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    if(arr[0]!=0){
        dp[0][arr[0]]  = 1;
    }
    else{
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i<n; i++){
        if(arr[i]==0){
            for(int j = 0 ; j<m; j++){
                if(j-1>=1){
                    dp[i][j] = dp[i][j] + dp[i-1][j-1];
                }
                dp[i][j] = dp[i][j] + dp[i-1][j];
                if(j+1<=m){
                    dp[i][j] = dp[i][j] + dp[i-1][j+1];
                }
            }
        }
        else{
            if(arr[i]-1>=1){
                dp[i][arr[i]] = dp[i][arr[i]] + dp[i-1][arr[i]-1];
            }
            dp[i][arr[i]] = dp[i][arr[i]] + dp[i-1][arr[i]];
            if(arr[i]+1<=m)
                dp[i][arr[i]] = dp[i][arr[i]] + dp[i-1][arr[i]+1];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = ans + dp[n-1][i];
    }
    cout<<ans%m;
    return 0;
    }
    
