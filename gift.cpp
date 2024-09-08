#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <queue>
#define endl "\n"
using namespace std;
#define int long long int
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;
const int MAXD = 1e9;
vector<vector<int>> ans;
int cnt = 0;
vector<int> arr;
void solve(int k, int n)
{
    if (k == 0)
    {
        for (auto a : arr)
        {
            cout << a << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
            solve(k--, n);
            arr.pop_back();
            solve(k--, n);
        }
    }
}

int main()
{
    solve(3, 2);
}