// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;
#include<vector>

long long ans = 0;
int m = 1000000007;
bool ready[1000001];
long long value[1000001];
long long val;
long long solve(long long n)
{
    if(ready[n]){
        return ans = value[n] + ans%m;
        }
    else if(n==0){
        ans = ans + 1;
        return ans%m;
        }
    else if(n<0){
        return ans%m;
    }
    else
    {
        for(int i = 1 ; i<=6; i++)
        {
            
            val = solve(n-i);
        }
        ready[n] = true;
        value[n] = val%m;
        return ans%m;

    }
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}