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
const int m = 1e9 + 7;
vector<int> indegree(2000001);
vector<int> ar[2000001];
vector<int> c(2000001);
void addedge(int u, int v)
{
    ar[u].push_back(v);
    indegree[v]++;
}

void topsort(int n)
{
    queue<int> q;
    for (int i = 2; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto child : ar[top])
        {
            --indegree[child];
            if (indegree[child] == 0 && child != 1)
            {
                q.push(child);
            }
        }
    }
    q.push(1);
    c[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : ar[u])
        {
            --indegree[v];
            c[v] = c[v] + c[u];
            c[v] %= m;
            if (!indegree[v])
            {
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        addedge(u, v);
    }
    topsort(n);
    cout << c[n];
}