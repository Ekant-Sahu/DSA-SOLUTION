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
const int N = 100000;
vector<int> ar[100001];
bool visted[100001];
int dist[100001];
int par[100001];
int n, m;

bool bfs()
{
    queue<int> q;
    dist[1] = 1;
    visted[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == n)
            return true;
        for (int u : ar[node])
        {
            if (visted[u] == false)
            {
                dist[u] = dist[node] + 1;
                visted[u] = true;
                par[u] = node;
                q.push(u);
            }
        }
    }
    return false;
}

int main()
{
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v, ar[u].push_back(v), ar[v].push_back(u);
    }
    if (bfs())
    {
        cout << dist[n] << endl;
        int path = n;
        vector<int> res;
        while (path != 0)
            res.push_back(path), path = par[path];
        reverse(res.begin(), res.end());
        for (int node : res)
            cout << node << " ";
    }
    else
        cout << "IMPOSSIBLE";
}
