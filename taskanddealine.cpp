// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <utility>
#define INF 1e18

bool winner(vector<int> temp)
{
    if (temp.size() == 1)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i] = temp[i] - temp.size() - 1 < 1 ? temp[i] - temp.size() - 1 : temp.pop();
        }
    }
}

int solve(int n, int m)
{
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            if (find(temp.begin(), temp.end(), i) != temp.end())
            {
                break;
            }
            else
            {
                temp.push_back(i);
            }
        }
        cnt++;
    }
    return pow(m, n) - cnt;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int dfs(int i, int j, vector<vector<int>> &grid, int n, int m, int hcf)
{
    if (i == n - 1 && j == m - 1)
    {
        return hcf;
    }
    hcf = gcd(hcf, grid[i][j]);
    int max_hcf = 0;
    if (j + 1 < m)
    {
        max_hcf = max(max_hcf, dfs(i, j + 1, grid, n, m, hcf));
    }
    if (i + 1 < n)
    {
        max_hcf = max(max_hcf, dfs(i + 1, j, grid, n, m, hcf));
    }
    return max_hcf;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int hcf = grid[0][0];
    cout << dfs(0, 0, grid, n, m, hcf);
    return 0;
}