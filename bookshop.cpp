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
    int n,x;
    cin>>n>>x;
    vector<int> price(n);
    vector<int> page(n);
    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>page[i];
    }
    vector<vector<int>> sol(n+1,vector<int>(x+1,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            sol[i+1][j] = sol[i][j];
            if(j>=price[i]){
                sol[i+1][j] = max(sol[i+1][j],page[i]+sol[i][j-price[i]]);
            }
        } 
    }
    cout<<sol[n][x];
    
    
    return 0;
}