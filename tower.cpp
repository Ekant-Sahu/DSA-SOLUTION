#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include<math.h>
#include<algorithm>
#include<numeric>


int main(){
int n,count = 0;
cin>>n;
// vector<vector<int>> tower;
int last = 0;
vector<int> arr(n);
multiset<int> set;
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
for (int i = 0; i < n; i++)
{
    if(set.size()==0){
        set.insert(arr[i]);
    }
    else{
        auto base = set.upper_bound(arr[i]);
        if(base == set.end())
            set.insert(arr[i]);
        else{
            set.insert(arr[i]);
            set.erase(base);
        }
    }
}
cout<<set.size();
}