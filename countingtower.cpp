#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9


const int N = 1000000;
const int m = 1000000007;




int ans = 0;
//recersive implementation
int solve(int n){
    if(n==1){
        return 2;
    }
    else{
        ans = ans + 2*solve(n-1);
    }
    return ans;
}



int main(){
    //iterative implementaion
    int n = 6;
    cout<<solve(n);
    return 0;
    }
    
