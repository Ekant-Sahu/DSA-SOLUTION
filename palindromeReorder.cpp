#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

void create_palindrome(const string &s)
{
    unordered_map<char, int> char_count;

    // Count the frequency of each character
    for (char c : s)
    {
        char_count[c]++;
    }

    // Track the number of characters with odd frequency
    int odd_count = 0;
    char odd_char = '\0';

    // Check how many odd frequencies there are
    for (auto &entry : char_count)
    {
        if (entry.second % 2 != 0)
        {
            odd_count++;
            odd_char = entry.first;
        }
    }

    // If more than one character has an odd frequency, no solution is possible
    if (odd_count > 1)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    string first_half = "";
    string middle = "";

    // Construct the first half and middle of the palindrome
    for (auto &entry : char_count)
    {

        if (entry.second % 2 != 0)
        {
            middle = string(entry.second, entry.first);
            continue; // The middle character with odd count
        }
        string temp(entry.second / 2, entry.first); // Add half the occurrences to the first half
        first_half += temp;
    }

    // The palindrome is the first half + middle + reverse of the first half
    string second_half = first_half;
    reverse(second_half.begin(), second_half.end());

    cout << first_half + middle + second_half << endl;
}

int main()
{
    string s;
    cin >> s;
    create_palindrome(s);
    return 0;
}