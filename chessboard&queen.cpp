#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>

#include <iostream>
#include <vector>

using namespace std;

// Board size and constraints
const int N = 8;
vector<string> board(N);
vector<bool> cols(N, false), diag1(2 * N, false), diag2(2 * N, false);
int solutions = 0;

void solve(int row)
{
    if (row == N)
    {
        // All queens are successfully placed
        solutions++;
        return;
    }

    for (int col = 0; col < N; col++)
    {
        // Check if the current square is free and the position is valid (not under attack)
        if (board[row][col] == '.' && !cols[col] && !diag1[row - col + N] && !diag2[row + col])
        {
            // Place the queen
            cols[col] = diag1[row - col + N] = diag2[row + col] = true;

            // Move to the next row
            solve(row + 1);

            // Backtrack: remove the queen
            cols[col] = diag1[row - col + N] = diag2[row + col] = false;
        }
    }
}

int main()
{
    // Input the chessboard (8x8)
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    // Start solving from row 0
    solve(0);

    // Output the total number of solutions
    cout << solutions << endl;

    return 0;
}
