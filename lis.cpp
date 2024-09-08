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

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sol(n, 0);
    sol[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (nums[j] < nums[i])
            {
                sol[i] = max(sol[i], sol[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
    // cout << sol[n - 1] + 1;
}

int main()
{
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums2 = {1, 3, 6, 7, 9, 4, 10, 5, 6};

    lengthOfLIS(nums1);
    lengthOfLIS(nums2);
}