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
#include <utility>
const int N = 1000;
int n, m;
bool check[1001][1001];
char map[1001][1001];
vector<char> path;
char br[1001][1001];
bool is_vaild(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    if ((check[x][y] == true) || (map[x][y] == '#'))
    {
        return false;
    }
    return true;
}

bool mod_bfs(int startx, int starty)
{
    queue<pair<int, int>> q;
    q.push({startx, starty});
    check[startx][starty] = true;
    while (!q.empty())
    {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        if (map[fx][fy] == 'B')
        {
            while (1)
            {
                path.push_back(br[fx][fy]);
                if (path.back() == 'L')
                    fy++;
                if (path.back() == 'R')
                    fy--;
                if (path.back() == 'U')
                    fx++;
                if (path.back() == 'D')
                    fx--;
                if (fx == startx && fy == starty)
                {
                    break;
                }
            }
            return true;
        }
        if (is_vaild(fx, fy - 1))
            br[fx][fy - 1] = 'L', q.push({fx, fy - 1}), check[fx][fy - 1] = true;

        // right
        if (is_vaild(fx, fy + 1))
            br[fx][fy + 1] = 'R', q.push({fx, fy + 1}), check[fx][fy + 1] = true;

        // up
        if (is_vaild(fx - 1, fy))
            br[fx - 1][fy] = 'U', q.push({fx - 1, fy}), check[fx - 1][fy] = true;

        // down
        if (is_vaild(fx + 1, fy))
            br[fx + 1][fy] = 'D', q.push({fx + 1, fy}), check[fx + 1][fy] = true;
    }
    return false;
}

int main()
{
    int startx, starty;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'A')
            {
                startx = i, starty = j;
            }
        }
    }
    if (mod_bfs(startx, starty) == true)
    {
        cout << "YES" << endl;
        cout << path.size() << endl;
        while (path.size() > 0)
            cout << path.back(), path.pop_back();
    }
    else
    {
        cout << "NO";
    }
}
