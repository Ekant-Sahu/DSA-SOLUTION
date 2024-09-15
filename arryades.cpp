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
    int n, m;
    cin >> n >> m;
    const int MOD = 1e9 + 7;
    vector<int> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(m + 1));
    if (grid[0] != 0)
        dp[0][grid[0]] = 1;
    else
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (grid[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j - 1 >= 1)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
        else
        {
            if (grid[i] - 1 >= 1)
                dp[i][grid[i]] = (dp[i][grid[i]] + dp[i - 1][grid[i] - 1]) % MOD;
            dp[i][grid[i]] = (dp[i][grid[i]] + dp[i - 1][grid[i]]) % MOD;
            if (grid[i] + 1 <= m)
                dp[i][grid[i]] = (dp[i][grid[i]] + dp[i - 1][grid[i] + 1]) % MOD;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n - 1][i]) % MOD;
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
}