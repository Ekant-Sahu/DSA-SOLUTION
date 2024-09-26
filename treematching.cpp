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
    pair<int, int> bfs(int node)
    {
        vector<int> level(n + 1);
        vector<bool> visit(n + 1, false);
        level[node] = 0;
        int far = node;
        int dia = level[node];
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
                    if (level[child] > dia)
                    {
                        dia = level[child];
                        far = child;
                    }
                    q.push(child);
                }
            }
        }
        return {far, dia};
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
    pair<int, int> first;
    Tree tree(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree.addEdge(a, b);
    }

    first = tree.bfs(1);
    cout << tree.bfs(first.first).second;

    return 0;
}