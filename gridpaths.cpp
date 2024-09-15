#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <stack>

int main()
{
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - 1 >= 0 && grid[i][j] != '*')
            {
                dp[i][j] += (dp[i - 1][j]);
            }
            if (j - 1 >= 0 && grid[i][j] != '*')
            {
                dp[i][j] += (dp[i][j - 1]);
            }
            dp[i][j] %= MOD;
        }
    }
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n - 1][n - 1] << endl;
}