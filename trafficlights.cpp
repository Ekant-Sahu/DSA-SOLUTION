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
int n,m;
cin>>n>>m;
set<int> positions;
multiset<int> lengths;
positions.insert(0);
positions.insert(n);
lengths.insert(n-0);
for (int i = 0; i < m; i++)
{
    int added;
    cin>>added;
    positions.insert(added);
    auto iter = positions.find(added);
    int prevousval = *prev(iter);
    int nextval = *next(iter);
    lengths.erase(lengths.find(nextval-prevousval));
    lengths.insert(added-prevousval);
    lengths.insert(nextval-added);
    cout<<*lengths.rbegin()<<endl;
}

}