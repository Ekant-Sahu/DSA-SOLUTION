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
vector<int> children;
for (int i = 0; i < n; i++)
{
    children.push_back(i+1);
}

while(children.size()>1){
    vector<int> survior;
    for (int i = 0; i < children.size(); i++)
    {
        if(i%2==1){
            cout<<children[i]<<" ";
        }
        else{
            survior.push_back(children[i]);
        }
    }
    if(children.size()%2==0){
        children = survior;
    }
    else{
        int start = survior.back();
        survior.pop_back();
        children.clear();
        children.push_back(start);
        for(int z:survior){
            children.push_back(z);
        }
    }
    
}
cout<<children[0];
}



