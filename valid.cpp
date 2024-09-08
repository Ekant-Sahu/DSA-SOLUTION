#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <stack>

bool isValid(string s)
{
    stack<char> store;
    cout << store.top();
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    //     {
    //         store.push(s[i]);
    //     }
    //     else
    //     {
    //         if (s[i] == ')' && store.top() == '(')
    //         {
    //             cout << "(dfsfs)";
    //             store.pop();
    //         }
    //         else if (s[i] == '}' && store.top() == '{')
    //         {
    //             cout << "{dfdsf}";
    //             store.pop();
    //         }
    //         else if (s[i] == ']' && store.top() == '[')
    //         {
    //             cout << "[dfjkkf]";
    //             store.pop();
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }
    // }
    return true;
}

int main()
{
    cout << isValid("(]");
}