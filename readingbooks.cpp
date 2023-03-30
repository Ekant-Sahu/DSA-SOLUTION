// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include<math.h>
#include<algorithm>
#include<numeric>
#include <utility>
#define INF 1e18




int main(){
    vector<int> time;
    int n;
    long long sum = 0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        time.push_back(t);
        sum +=t;
    }
    sort(time.begin(),time.end(),greater<int>());
    long long check = time[0]*2;
    cout<<max(sum,check);
    
    
}