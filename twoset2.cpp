#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Function to perform modular exponentiation
long long modExpo(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod; // Handle large values of base
    while (exp > 0)
    {
        // If exp is odd, multiply base with the result
        if (exp % 2 == 1)
            result = (result * base) % mod;
        // Now exp must be even
        exp = exp >> 1;             // exp = exp / 2
        base = (base * base) % mod; // Square the base
    }
    return result;
}

// Function to find modular inverse of 'a' under modulo MOD
long long modInverse(long long a, long long mod)
{
    return modExpo(a, mod - 2, mod);
}

int main()
{
    // iterative implementation
    int n;
    cin >> n;

    // Corrected target calculation
    int target = (n * (n + 1) % 4 == 0) ? (n * (n + 1)) / 4 : 0;

    if (target == 0)
    {
        cout << 0;
        return 0;
    }

    vector<long long> dp(target + 1);
    dp[0] = 1;

    // DP approach to calculate partition ways
    for (int i = 1; i <= n; i++)
    {
        for (int j = target; j >= i; j--)
        {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    // Debugging DP array
    // for (auto x : dp)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // Final output with correct modular inverse
    cout << (dp[target] * modInverse(2, MOD)) % MOD;
}
