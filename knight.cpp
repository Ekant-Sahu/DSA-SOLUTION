// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9


const int N = 1000000;


long long solve(long long k){
    long long ans;
    ans = k*k*(k*k - 1)/2 - 4*(k-1)*(k-2);
    return ans;
}



int main(){
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        cout<<solve(i)<<endl;
    }
    
    return 0;
}