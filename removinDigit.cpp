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

//recersive implementation
int ans = 0;
int solve(int n){
    if(n>0 && n<10){
        return ans + 1;
    }
    else if(n==0){
        return ans;
    }
    else{
        int a = 0;
        int d = n;
        while(d>0){
            int r = d%10;
            if (r>a)
            {
                a=r; 
            }
            d = d/10;
        }
        //cout<<n-a<<" ";
        ans++;
        solve(n-a);
        return ans+1;
    }
    
}






int main(){
    //iterative implementaion
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}