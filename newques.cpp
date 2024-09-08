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

int strStr(string haystack, string needle)
{
    bool check = false;
    int i = 0;
    int j = 0;
    int index = 0;

    while (i < haystack.size() && j < needle.size())
    {
        if (needle[j] == haystack[i])
        {
            cout << needle[j] << " " << needle[i] << "    ";
            if (check == false)
            {
                index = i;
                check = true;
            }
            j++;
            i++;
        }
        else
        {
            cout << "dskfsdf";
            check = false;
            i++;
        }
    }
    if (check)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

int main()
{
    cout << strStr("leeto", "leetcode");
}