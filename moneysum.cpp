// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9


const int N = 1000000;
bool ready[N];
int value[N];


// int solve(int x,vector<int> coins, int n){
//     if(x<0) return INF;
//     if(x==0) return 0;
//     if(ready[x]) return value[x];
//     int best = INF;
//     for(auto c:coins)
//     {
//         best = min(best, solve(x-c,coins,n)+1);
//     }
//     ready[x] = true;
//     value[x] = best;
//     return best;
// }



int main(){
    //iterative implementaion
    int n,count = 0;
    cin>>n;
    int x = 0;

    vector<int> coins(n);
    for(int i = 0; i<n; i++)
    {
        cin>>coins[i];
        x = x + coins[i];
    }
    vector<int> ans;
    vector<int> sum(x+1,0);
    sum[0] = 1;
    for(int ci = 0; ci<n; ci++){
        for(int s = x; s>=1; s--){
            if(s-coins[ci]>=0 && sum[s]==0){
                sum[s] = sum[s-coins[ci]];
            }
        }

    }
    for(int i = 1; i<=x; i++){
        if(sum[i]==1){
            count++;
            ans.push_back(i);
        }
    }
    cout<<count<<endl;
    for (int i = 0; i < count; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}