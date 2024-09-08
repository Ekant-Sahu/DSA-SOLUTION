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
const long long N = 100001;
class graph
{
private:
    vector<long long> adj[N];

public:
    void addedge(long long u, long long v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print(long long V)
    {
        for (long long i = 0; i <= V; i++)
        {
            for (auto x : adj[i])
            {
                cout << i << x << " ";
            }
            cout << endl;
        }
    }
    vector<long long> get_neghibour(long long vertix)
    {
        return adj[vertix];
    }
};

vector<int> visted;
vector<int> connect;
vector<bool> marked(100001, false);
void dfs(graph g, long long start)
{
    visted.push_back(start);
    // cout << start << " ";
    marked[start] = true;
    {
        for (auto i : g.get_neghibour(start))
        {
            if (!marked[i])
            {
                // connect.push_back(i);
                dfs(g, i);
            }
        }
    }
}
queue<int> node;
vector<int> path;
void bfs(graph g, int start)
{
    node.push(start);
    while (node.size() > 0)
    {
        int f = node.front();
        node.pop();
        if (!marked[f])
        {
            visted.push_back(f);
            cout << f;
            marked[f] = true;
        }
        for (auto i : g.get_neghibour(f))
        {
            if (!marked[i])
            {
                node.push(i);
            }
        }
    }
}

void buildroad(graph g, int v)
{
    int count = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!marked[i])
        {
            connect.push_back(i);
            dfs(g, i);
            // connected.push_back(connect);
        }
    }
    // cout << count - 1;
}

void messageRoute(graph g)
{
}

int main()
{

    int n, m;
    cin >> n >> m;
    graph g1, g2;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g1.addedge(u, v);
    }

    // g1.addedge(1, 2);
    // g1.addedge(1, 3);
    // g1.addedge(1, 4);
    // g1.addedge(3, 5);
    // g1.addedge(5, 6);
    // g1.addedge(5, 7);
    // g1.addedge(5, 8);
    // g1.addedge(7, 8);
    // g1.addedge(8, 9);
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     g1.addedge(u, v);
    // }
    buildroad(g1, n);
    cout << connect.size() - 1 << endl;
    for (auto x : connect)
    {
        cout << x << " ";
    }
}
