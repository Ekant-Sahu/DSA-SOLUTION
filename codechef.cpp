#include <iostream>
using namespace std;

// int main()
// {
//     vector<int> arr;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;

//         arr = vector<int>(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         int target = arr[n - 1] + arr[n - 2];
//         int i = 0;
//         int j = n - 1;
//         bool ans = false;
//         while (i < j)
//         {
//             if (arr[i] + arr[j] < target)
//             {
//                 i++;
//                 j--;
//             }
//             else
//             {
//                 ans = false;
//                 break;
//             }
//             ans = true;
//         }
//         if (ans)
//         {
//             cout << "YES";
//         }
//         else
//         {
//             cout << "NO";
//         }
//     }
//     return 0;
// }

// class Solution {
// public:

//     bool is_valid(int x, int y, int n, vector<vector<bool>> vis){
//         if(x>=0 && y>=0 && x<=n && y<=n && vis[x][y]==false){
//             return true;
//         }
//         else {
//             return false;
//         }
//     }

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size() - 1;
    int len = 0;
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        len++;
        pair<int, int> cord = q.front();
        x = cord.first;
        y = cord.second;
        q.pop();
        if (x == n && y == n)
        {
            return len;
        }
        if (is_valid(x + 1, y, n, vis))
        {
            q.push(make_pair(x + 1, y));
        }
        if (is_valid(x + 1, y + 1, n, vis))
        {
            q.push(make_pair(x + 1, y + 1));
        }
        if (is_valid(x, y + 1, n, vis))
        {
            q.push(make_pair(x, y + 1));
        }
        if (is_valid(x - 1, y, n, vis))
        {
            q.push(make_pair(x - 1, y + 1));
        }
        if (is_valid(x, y - 1, n, vis))
        {
            q.push(make_pair(x, y - 1));
        }
        if (is_valid(x - 1, y - 1, n, vis))
        {
            q.push(make_pair(x - 1, y - 1));
        }
        if (is_valid(x - 1, y + 1, n, vis))
        {
            q.push(make_pair(x - 1, y + 1));
        }
        if (is_valid(x + 1, y - 1, n, vis))
        {
            q.push(make_pair(x + 1, y - 1));
        }
    }
    return -1;
}
}
;