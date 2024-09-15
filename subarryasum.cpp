#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> num(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    map<long long, int> prefix_sum_map;
    prefix_sum_map[0] = 1; // To handle cases where subarray starts from index 0
    long long sum = 0;
    long long cnt = 0;

    for (int i = 0; i < n; i++)
    {
        sum += num[i];
        cnt += prefix_sum_map[sum - target];
        prefix_sum_map[sum]++;
    }

    for (auto x : prefix_sum_map)
    {
        cout << x.first << " " << x.second << endl;
    }
}
