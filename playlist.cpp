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

vector<int> arr(n);
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
set<int> heard;
int best = 0;
int i = 0;
int j = 0;
while(j<n && i<n){
    while(j<n && !heard.count(arr[j])){
        heard.insert(arr[j]);
        best = max(best,j-i+1);
        j++;
    }
    while(j<n && heard.count(arr[j])){
        heard.erase(arr[i]);
        i++;
    }
}
cout<<best;
}