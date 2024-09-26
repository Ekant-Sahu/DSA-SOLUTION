#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Tree
{
public:
    Tree(int n) : n(n)
    {
        graph.resize(n + 1);
    }

    void addEdge(int a, int b)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<long long int> bfs(int node)
    {
        vector<long long int> level(n + 1);
        vector<bool> visit(n + 1, false);
        level[node] = 0;
        visit[node] = true;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            // cout << x << " level " << level[x] << endl;
            for (auto child : graph[x])
            {
                if (!visit[child])
                {
                    visit[child] = true;
                    level[child] = level[x] + 1;
                    q.push(child);
                }
            }
        }
        return level;
    }

private:
    int n;
    vector<vector<int>> graph;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Tree tree(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree.addEdge(a, b);
    }
    vector<long long int> from1 = tree.bfs(1);
    int far1 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (from1[i] > from1[far1])
        {
            far1 = i;
        }
    }
    vector<long long int> fromX = tree.bfs(far1);
    int farX = far1;
    for (int i = 1; i <= n; i++)
    {
        if (fromX[i] > fromX[farX])
        {
            farX = i;
        }
    }

    vector<long long int> fromY = tree.bfs(farX);
    for (int i = 1; i <= n; i++)
    {
        cout << max(fromX[i], fromY[i]) << " ";
    }

    return 0;
}