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
const int N = 1e9;
vector<pair<int, int>> ar[100001];
vector<vector<int>> adj(501, vector<int>(501, 0));

int n = 3, m;

void addedge(int u, int v, int w)
{
    adj[u][v] = w;
    adj[v][u] = w;
}

vector<vector<int>> floy_warshall(int nodes)
{
    vector<vector<int>> dis(nodes + 1, vector<int>(nodes + 1, N));
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else if (adj[i][j])
                dis[i][j] = adj[i][j];
            else
                dis[i][j] = N;
        }
    }

    for (int k = 1; k <= nodes; k++)
    {
        for (int i = 1; i <= nodes; i++)
        {
            for (int j = 1; j <= nodes; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    return dis;
}

int main()
{
    addedge(1, 2, 5);
    addedge(1, 3, 9);
    addedge(2, 3, 3);
    int u, v, w, q;
    int x, y;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    vector<vector<int>> dis = floy_warshall(n);

    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        if (x > n || x < 0 || y > n || y < 0 || dis[x][y] == N)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[x][y] << endl;
        }
    }
}
