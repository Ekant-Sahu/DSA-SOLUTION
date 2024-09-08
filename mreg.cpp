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

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> nums;
    if (n == 0)
    {
        nums = nums1;
    }
    if (m == 0)
    {
        nums = nums2;
    }
    while (k < m + n)
    {
        if (i == m)
        {
            nums.push_back(nums2[j]);
            j++;
            k++;
            continue;
        }
        if (j == n)
        {
            nums.push_back(nums1[j]);
            i++;
            k++;
            continue;
        }
        if (nums1[i] < nums2[j])
        {
            nums.push_back(nums1[i]);
            i++;
        }
        else
        {
            nums.push_back(nums2[j]);
            j++;
        }
        k++;
    }
    for (int i = 0; i < n + m; i++)
    {
        nums1[i] = nums[i];
    }
}

int removeElement(vector<int> &nums, int val)
{
    vector<int> ans;
    int k = 0;
    for (auto n : nums)
    {
        if (n != val)
        {
            ans.push_back(n);
            k++;
        }
    }
    nums.clear();
    nums = ans;
    return k;
}

class Solution
{
public:
    bool is_l(vector<int> &flowerbed, int x)
    {
        if (x - 1 < 0 || flowerbed[x - 1] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_r(vector<int> &flowerbed, int x)
    {
        if (x + 1 > flowerbed.size() - 1 || flowerbed[x + 1] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int cnt = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (is_l(flowerbed, i) && is_r(flowerbed, i) && flowerbed[i] == 0)
            {
                cnt++;
                flowerbed[i] = 1;
            }
        }
        return cnt >= n;
    }
};