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
vector<int> ticket(n);
vector<int> customer(m);
// 
vector<int> ans(m);

for (int i = 0; i < n; i++)
{
    cin>>ticket[i];
    }

for (int i = 0; i < m; i++)
{
    cin>>customer[i];
}



vector<int> taken(n,0);
sort(ticket.end(),ticket.begin());
int i = 0;
int j = 0;

while(j<m){
    while(i<n){
        if(!taken[i] && customer[j]-ticket[i]>=0){
            taken[i] = 1;
            ans[j] = ticket[i];
            break;
        }
        else{
            ans[j] = -1;
        }
        i++;
    }
    j++;
}
for (int i = 0; i < m; i++)
{
    cout<<ans[i]<<endl;
}

}