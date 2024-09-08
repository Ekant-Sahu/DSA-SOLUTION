#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <queue>
#include <stack>
vector<int> ar[200001];
vector<bool> visted(200001);
vector<int> next_node(200001);
vector<int> dp(200001);
int m = 1e9 + 7;
int c = 0;

void dfs(int nodes, int n)
{
    visted[nodes] = true;
    for (auto i : ar[nodes])
    {
        if (!visted[i] && i != n)
        {
            dfs(i, n);
            // next_node[nodes] = i;
        }
        else if (i == n)
        {
            c += 1;
        }
    }
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ar[u].push_back(v);
    }

    dfs(1, n);
    cout << c % m;
}