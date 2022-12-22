#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9


const int N = 1000000;
const int m = 1000000007;
bool ready[N];
int value[N];

int main(){
    //iterative implementaion
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    vector<int> count(x+1);
    for(int i = 0; i<n; i++)
    {
        cin>>coins[i];
    }
    count[0] = 1;
    for(int j = 0; j<n; j++)
    {
        
        for(int i = 1;i<=x;i++){
            if(i-coins[j]>=0){
                count[i] += count[i-coins[j]];
                count[i] %= m; 
            } 
        }
    }
    cout<<count[x];
    return 0;
}