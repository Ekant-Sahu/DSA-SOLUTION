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
    vector<bool> taken(20);
    vector<vector<int>> rides;
    int n = 4, max = 10;
    vector<int> weight = {4,8,6,1};
    // for(int i = 1; i<=max; i++){
        
    //     for(int j = 0; j<n; j++){
    //         if(max - weight[j] >=0 && !taken[i]){
    //             taken[j] = true;
    //         }
    //     }
    // }
    int sum = 0;
    while(sum<=max){
        for(int w = 0; w<n; w++){
            if(sum+weight[w]<=max && !taken[w]){
                sum = sum + weight[w];
                taken[w] = true;
            }
        }
        sum = 0;
    }







    return 0;
    }
    
