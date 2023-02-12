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
int n;
cin>>n;
vector<int> coins(n);
for (int i = 0; i < n; i++)
{
    cin>>coins[i];
}
sort(coins.begin(),coins.end());
long long check = 1;
for (int i = 0; i < n && check>=coins[i]; i++)
{
    check += coins[i];
}
cout<<check;

}