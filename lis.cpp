#include <iostream>
#include <cmath>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <stack>

int lengthOfLIS(vector<long long> &nums, int n)
{
    if (n == 0)
        return 0;
    vector<long long> sol;

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(sol.begin(), sol.end(), nums[i]);
        if (it == sol.end())
        {
            sol.push_back(nums[i]);
        }
        else
        {
            *it = nums[i];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << sol[i] << " ";
    // }
    // cout << endl;
    return sol.size();
}

int main()
{
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums, n);
}