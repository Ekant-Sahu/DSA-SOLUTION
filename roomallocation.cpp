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



int main(){
int n;
cin>>n;
vector<pair<int,int>> schedule(n);
vector<int> rooms;
for (int i = 0; i < n; i++)
{
    int a,d;
    cin>>a>>d;
    schedule[i].first = a;
    schedule[i].second = d;
}
sort(schedule.begin(),schedule.end());
int count = n;
rooms[0] = 1;
int f = schedule[0].first;
for (int i = 1; i < n; i++)
{
    int d = schedule[i].second;
    if(d<f) {count--;}
    else{
        rooms[i] = rooms[i-1]+1;
    }
    f = schedule[i].first;
    cout<<schedule[i].first<<schedule[i].second<<endl;
}
cout<<count<<endl;
// for (int i = 0; i < count; i++)
// {
//     cout<<rooms[i]<<" ";
// }


}



