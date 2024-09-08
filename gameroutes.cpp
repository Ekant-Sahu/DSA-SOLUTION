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

void set_base(int n)
{
    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
    }
    dp[1] = 1;
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
    set_base(n);
    for (int i = 1; i <= n; i++)
    {
        for (auto child : ar[i])
        {
            dp[child] = dp[child] + dp[i] + 1;
        }
    }

    cout << dp[n] % m;
}