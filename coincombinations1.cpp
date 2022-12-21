// Online C++ compiler to run C++ program online
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
    for(int i = 0; i<=x; i++)
    {
        for(auto c: coins){
            if(i-c>=0){
                count[i] += count[i-c];
                count[i] %= m; 
            } 
        }
    }
    cout<<count[x];
    return 0;
}