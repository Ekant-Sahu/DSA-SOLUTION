#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <utility>
#define INF 1e18

int check(int x, vector<pair<int, int>> &minimum, int index)
{

    for (int i = minimum.size() - 1; i >= 0; i--)
    {
        if (x > minimum[i].first)
        {
            minimum.push_back(make_pair(x, index));
            return minimum[i].second;
        }
        else
        {
            minimum.pop_back();
        }
    }
    if (minimum.empty())
    {
        minimum.push_back(make_pair(x, index));
        return 0;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    vector<int> ans(n);
    vector<pair<int, int>> minimum;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = check(num[i], minimum, i + 1);
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
}
