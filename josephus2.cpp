#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less, rb_tree_tag, tree_order_statistics_node_update>

    int main()
{
    int n, k;
    cin >> n >> k;
    ordered_set<int> children;
    for (int i = 1; i <= n; i++)
    {
        children.push_back(i);
    }
    int start = 0;
    while (children.size() > 0)
    {
        start %= children.size();
        int pos_remove = (start + k) % children.size();
        start = pos_remove;
        auto t = children.find_by_order(pos_remove);
        cout << *t << " ";
        children.erase(t);
    }
}