

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
#include <unordered_map>

void solve(int n, int k, int m, string s)
{
    unordered_map<char, int> occur;
    for (int i = 0; i < m; i++)
    {
        occur[s[i]]++;
    }

    for (int i = 0; i < k; i++)
    {
        if (occur[i].second < k)
    }
    int i = 0;
    int j = m - 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            if (occur[s[i]] > k)
            {
                i++;
                occur[s[i]]--;
            }
            else if (occur[s[j]] > k)
            {
                j--;
                occur[s[j]]--;
            }
            else
            {
                cout << "no" << endl;
                string ans = "";
                ans = ans + s[j] + s[i] + s.substr(i + 1, i + k - 2);
                cout << ans << endl;
                return;
            }
        }
    }
    cout << "yes" << endl;
    return;
}

int main()
{

    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> n >> k >> m;
        cin >> s;
        solve(n, k, m, s);
    }
    return 0;
}