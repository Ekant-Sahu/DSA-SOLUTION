#include<iostream>
using namespace std;
#include<vector>
//missing coin sum

int main(){
    // int n;
    // cin>>n;
    // vector<int> arr;
    // int best = 0, sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum = 
    // }
    int n = 10;
    int r = n%7; 
        int q = n/7 ;
        int money = 0;
        if(n>7){
            money = (q*(56 + (q-1)*7))/2;
            cout<<money<<endl;
            }
        else{q = 1;}
        
        int rmoney = 0;
        for(int i = 0; i<r; i++)
        {
            rmoney = rmoney + q;
            q = q + 1;
        }
        cout<<money<<" "<<rmoney;
        return money + rmoney;
}