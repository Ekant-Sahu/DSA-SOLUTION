#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <stdio.h>
const int MOD = 1e9 + 7;
typedef long long ll;
int dp[1001][1 << 10];
int n, m;
void fill_column(int col, int idx, int curr_mask, int next_mask)
{
    if (idx == n)
    {
        dp[col + 1][next_mask] = (dp[col + 1][next_mask] + dp[col][curr_mask]) % MOD;
        return;
    }
    if ((curr_mask) & (1 << idx))
    {
        fill_column(col, idx + 1, curr_mask, next_mask);
    }
    else
    {
        fill_column(col, idx + 1, curr_mask, next_mask | (1 << idx));
        if (idx + 1 < n && (!curr_mask & (1 << (idx + 1))))
            fill_column(col, idx + 2, curr_mask, next_mask);
    }
}

int main()
{
    // iterative implementaion
    cin >> n >> m;

    dp[0][0] = 1;
    for (int col = 0; col < m; col++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (dp[col][mask] > 0)
                fill_column(col, 0, mask, 0);
        }
    }
    cout << dp[m][0];
}
