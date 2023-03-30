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
vector<bool> visted(100001, false);
int dist[100001];
int par[100001];
int n, m;

void addedge(int u, int v)
{
    ar[u].push_back(v);
    ar[v].push_back(u);
}

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
        for (auto u : ar[node])
        {
            if (visted[u] == true && (u == par[node]))
                return true;
            if (visted[u] == false)
            {
                dist[u] = dist[node] + 1;
                visted[u] = true;
                cout << u << " ";
                par[u] = node;
                q.push(u);
            }
        }
    }
    return false;
}

bool check_cycledfs(int node, int par)
{
    visted[node] = true;
    cout << node << " ";
    for (auto i : ar[node])
    {
        if (!visted[i])
        {
            if (check_cycledfs(i, node))
            {
                return true;
            }
        }
        else if (i != par)
        {
            return true;
        }
    }
    return false;
}

vector<int> color(100001, -1);
bool biparti = true;
void dfs(int node, int par)
{
    if (color[node] == -1)
    {
        color[node] = 0;
        for (auto child : ar[node])
        {
            if (color[child] == 0)
            {
                biparti = false;
                return;
            }
            else if (color[child] != 1)
            {
                color[child] = 1;
                // cout << child << "color: " << color[child] << endl;
                dfs(child, node);
            }
        }
    }
    else if (color[node] == 1)
    {
        for (auto child : ar[node])
        {
            if (child != par)
            {
                if (color[child] == 1)
                {
                    biparti = false;
                    return;
                }
                else if (color[child] != 0)
                {
                    color[child] = 0;
                    // cout << child << "color:  " << color[child] << endl;
                    dfs(child, node);
                }
            }
        }
    }
    else if (color[node] == 0)
    {
        for (auto child : ar[node])
        {
            if (child != par)
            {
                if (color[child] == 0)
                {
                    biparti = false;
                    return;
                }
                else if (color[child] != 1)
                {
                    color[child] = 1;
                    // cout << child << "color:  " << color[child] << endl;
                    dfs(child, node);
                }
            }
        }
    }
    biparti = true;
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
    // addedge(8, 9);
    // addedge(1, 2);
    // addedge(1, 3);
    // addedge(4, 5);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        addedge(u, v);
    }

    for (int i = 1; i <= n; i++)
    {
        dfs(i, -1);
    }
    if (biparti)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] + 1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}
