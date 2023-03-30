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
const int N = 1000;
int n, m;
bool check[1001][1001];
char building[1001][1001];
bool is_vaild(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    if ((check[x][y] == true) || (building[x][y] == '#'))
    {
        return false;
    }
    return true;
}

void mod_dfs(int x, int y)
{
    check[x][y] = true;
    if (is_vaild(x - 1, y))
    {
        mod_dfs(x - 1, y);
    }
    if (is_vaild(x, y + 1))
    {
        mod_dfs(x, y + 1);
    }
    if (is_vaild(x + 1, y))
    {
        mod_dfs(x + 1, y);
    }
    if (is_vaild(x, y - 1))
    {
        mod_dfs(x, y - 1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> building[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {

    //         cout << building[i][j];
    //     }
    // }

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((building[i][j] == '.') && (check[i][j] == false))
                mod_dfs(i, j), count++;
        }
    }
    cout << count;
}
