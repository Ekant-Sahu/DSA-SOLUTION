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

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> sol;
    // vector<int> ans(3);
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    int j = 2;
    while (i <= n - 1 && j <= n - 1)
    {

        int f = -(nums[i] + nums[j]);
        auto k = find(nums.begin() + i + 1, nums.begin() + j, f) - nums.begin();
        // cout << f << "    " << k << " " << endl; // counting from zero
        if (k < j)
        {
            cout << nums[i] << nums[j] << nums[k] << endl;
            sol.insert({nums[i], nums[j], nums[k]});
            if (j < n - 1)
            {
                j++;
            }
            else
            {
                i++;
                j = i + 2;
            }
        }
        else
        {
            cout << "k NOT found" << endl;
            if (j < n - 1)
            {
                j++;
            }
            else
            {
                i++;
                j = i + 2;
            }
        }
    }
    vector<vector<int>> ans(sol.begin(), sol.end());
    return ans;
}
int main()
{
    vector<int> num = {-4, -1, -1, 0, 1, 1, 2};
    vector<vector<int>> sol = threeSum(num);
    for (auto &x : sol)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}