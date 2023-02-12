#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <string>
#include<math.h>
#include<algorithm>
#include<numeric>
#include <map>

int main(){
    int n,x;
    cin>>n>>x;
    map<int,int> value;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin>>v;
        if(value.count(x-v)){
            cout<<i+1<<" "<<value[x-v]<<endl;
            return 0;
        }
        value[v] = i+1;
    }
    cout<<"IMPOSSIBLE";
    
}
 