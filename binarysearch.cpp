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

vector<vector<int>> twosum(int s, int e, vector<int> &nums, int sum)
{
    vector<vector<int>> ans;
    int i = s;
    int j = e;
    while (j >= i)
    {
        if (nums[i] + nums[j] == sum)
        {
            ans.push_back({nums[i], nums[j], -sum});
            i++;
            j--;
        }
        else if (nums[i] + nums[j] > sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> sol;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (i != 0 || nums[i - 1] != nums[i])
        {
            int sum = -nums[i];
            // cout << "sum : " << sum << endl;
            sol = twosum(i + 1, n - 1, nums, sum);
            // for (auto &x : sol)
            // {
            //     for (auto y : x)
            //     {
            //         cout << y << " ";
            //     }
            //     cout << endl;
            // }
        }
    }

    return sol;
}

int main()
{
    vector<int> num = {-4, -1, -1, 0, 1, 1, 2};
    vector<vector<int>> sol = threeSum(num);
    for (auto x : sol)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    // vector<int> s = threeSum(num);
    // for (auto x : s)
    // {
    //     cout << x << endl;
    // }
}