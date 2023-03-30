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
const int N = 2501;
vector<pair<int, int>> ar[N];
queue<int> cycle;
vector<bool> visted(2501, false);
vector<bool> dfsvist(2501, false);
void addedge(int u, int v, int w)
{
    ar[u].push_back({v, w});
}

bool dfs(int start)
{
    visted[start] = true;
    dfsvist[start] = true;
    cycle.push(start);
    for (auto child : ar[start])
    {
        int c = child.first;
        if (!visted[c])
        {
            bool check = dfs(c);
            if (check)
            {
                return true;
            }
        }
        else if (dfsvist[c])
        {
            cycle.push(c);
            return true;
        }
    }
    dfsvist[start] = false;
    cycle.pop();
    return false;
}

int main()
{

    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addedge(u, v, w);
    }

    // addedge(1, 2, 1);
    // addedge(2, 4, 1);
    // addedge(3, 1, 1);
    // addedge(4, 1, -3);
    // addedge(4, 3, -2);

    for (int i = 1; i <= n; i++)
    {
        if (!visted[i])
        {
            bool cyclefound = dfs(1);
            if (cyclefound)
            {
                cout << "YES" << endl;
                while (!cycle.empty())
                {
                    cout << cycle.front() << " ";
                    cycle.pop();
                }
            }
            return 0;
        }
    }
    cout << "NO";
}
