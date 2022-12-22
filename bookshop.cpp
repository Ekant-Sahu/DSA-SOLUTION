#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9


const int N = 1000000;
const int m = 1000000007;
vector<bool> bought(false);
int noPages = 0;
int best = 0;


//recersive implementation

int solve(int x,vector<int> price,vector<int> page,int n){
    if(x<=0){
        return 0;
    }
    else{
        for(int i = 0; i<n;i++){
            if(!bought[i] && x-price[i]>=0){
                bought[i] = true;
                //cout<<price[i]<<" "<<x-price[i]<<endl;
                noPages = noPages + page[i];
                solve(x-price[i],price,page,n);
                bought[i]=false;
                best = max(noPages,best);
                noPages=0;
            }
        }
        return best;
    }
}






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
    cout<<solve(x,price,page,n);
    
    return 0;
}