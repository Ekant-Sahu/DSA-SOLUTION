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
const int N = 100001;
// class graph
// {
// private:
//     int V;
//     vector<int> adj[N];

// public:
//     graph(int vertices)
//     {
//         V = vertices;
//     }
//     void addedge(int u, int v)
//     {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     void print(int V)
//     {
//         for (int i = 1; i <= V; i++)
//         {
//             for (auto x : adj[i])
//             {
//                 cout << x << " ";
//             }
//             cout << endl;
//         }
//     }
//     vector<int> get_neghibour(int vertix)
//     {
//         return adj[vertix];
//     }
// };
bool vist[100001];
vector<int> ar[100001];

void dfs(int start)
{
    vist[start] = true;
    for (auto i : ar[start])
    {
        if (!vist[i])
        {
            dfs(i);
        }
    }
}

// void buildroad(int v, graph g)
// {
//     vector<int> visted(0);
//     int count = 0;
//     vector<int> roads;
//     for (int i = 1; i <= v; i++)
//     {
//         if (visted[i] == 0)
//         {
//             dfs(g, i);
//             count++;
//         }
//     }
//     cout << count;
// }

int main()
{
    int n, m, u, v;
    vector<int> road;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v, ar[u].push_back(v), ar[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vist[i] == 0)
        {
            dfs(i), road.push_back(i);
        }
    }

    cout << road.size() - 1 << endl;
    for (int i = 1; i < road.size(); i++)
    {
        cout << road[i - 1] << " " << road[i] << endl;
    }
}
