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
vector<int> visted(100001, false);

int dist[100001];

void addedge(int u, int v)
{
    ar[u].push_back(v);
    ar[v].push_back(u);
}

int par[100001];
vector<int> road;
bool dfs(int node, int par)
{
    visted[node] = true;
    road.push_back(node);
    // cout << node;
    for (auto child : ar[node])
    {
        if (!visted[child])
        {
            if (dfs(child, node))
                return true;
        }
        else if (visted[child] && par != child)
        {

            road.push_back(child);
            return true;
        }
    }
    road.pop_back();
    return false;
}

int main()
{
    // addedge(1, 2);
    // addedge(1, 3);
    // addedge(1, 4);
    // addedge(3, 5);
    // addedge(5, 6);
    // addedge(5, 7);
    // addedge(5, 8);
    // addedge(7, 8);
    // addedge(8, 9)

    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        addedge(u, v);
    }
    bool x;
    for (int i = 1; i <= n; i++)
    {
        if (!visted[i])
        {
            x = dfs(i, -1);
            if (x)
            {
                break;
            }
        }
    }
    bool start = false;
    int end = road.back();
    vector<int> ans;

    if (x)
    {
        for (auto i : road)
        {
            if (start)
            {
                ans.push_back(i);
            }
            else
            {
                if (i == end)
                {
                    start = true;
                    ans.push_back(i);
                }
            }
        }
        cout << ans.size() << endl;
        for (auto a : ans)
        {
            cout << a << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}
