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


int solve(int x,vector<int> coins, int n){
    if(x<0) return INF;
    if(x==0) return 0;
    if(ready[x]) return value[x];
    int best = INF;
    for(auto c:coins)
    {
        best = min(best, solve(x-c,coins,n)+1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
}



int main(){
    //iterative implementaion
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    vector<int> nocoins(x+1,INF);
    for(int i = 0; i<n; i++)
    {
        cin>>coins[i];
    }
    nocoins[0] = 0;
    for(int value = 1; value<=x; value++){
        for(int j = 0; j<n; j++){
            if(value - coins[j]>=0){
                nocoins[value] = min(nocoins[value],nocoins[value - coins[j]]+1);
            }
        }
    }
    cout<<(nocoins[x] == INF? -1: nocoins[x]);
    return 0;
}