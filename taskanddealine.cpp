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
    vector<pair<long long,long long>> time;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long a,d;
        cin>>a>>d;
        time.push_back(make_pair(a,d));
    }
    
    sort(time.begin(),time.end());
    long long cost = 0;
    long long t = 0;
    for (int i = 0; i < n; i++)
    {
        t += time[i].first;
        cost += time[i].second - t;
    }
    
    cout<<cost;
    
}