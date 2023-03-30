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
int n,t;
vector<int> time;
cin>>n>>t;
for (int i = 0; i < n; i++)
{
    cin>>time[i];
}
long long low = 0;
long long high = INF;
long long answer = INF;
while(low<=high){
    long long mid = (low+high)/2;
    long long products = 0;
    for (int i = 0; i < n; i++)
    {
        products += mid/time[i];
    }
    if(products>= t){
        if(mid<answer) answer = mid;
        high = mid -1;
    }
    else low = mid +1;
    

}


cout<<answer;

}



