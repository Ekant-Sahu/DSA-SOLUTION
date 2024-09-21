#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9 + 7;
int n, m;
vector<string> grid;
vector<vector<int>> monster_time, player_time;
vector<vector<pair<int, int>>> parent;
queue<pair<int, int>> q_monsters, q_player;

// Directions: D (Down), U (Up), R (Right), L (Left)
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<char> direction_labels = {'D', 'U', 'R', 'L'};

// BFS for monsters spreading through the map
void bfs_monsters()
{
    while (!q_monsters.empty())
    {
        auto [x, y] = q_monsters.front();
        q_monsters.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + directions[d].first;
            int ny = y + directions[d].second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && monster_time[nx][ny] == INF)
            {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                q_monsters.push({nx, ny});
            }
        }
    }
}

// BFS for player (starting from 'A')
bool bfs_player()
{
    while (!q_player.empty())
    {
        auto [x, y] = q_player.front();
        q_player.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + directions[d].first;
            int ny = y + directions[d].second;

            // Check if out of bounds -> successful escape
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                return true; // Reached the boundary, so we can escape
            }

            // If it's a valid move for the player
            if (grid[nx][ny] == '.' && player_time[nx][ny] == INF && player_time[x][y] + 1 < monster_time[nx][ny])
            {
                player_time[nx][ny] = player_time[x][y] + 1;
                parent[nx][ny] = {x, y}; // Record the path
                q_player.push({nx, ny});
            }
        }
    }

    return false; // No valid escape found
}

// Reconstruct the path by backtracking from the exit point
string reconstruct_path(pair<int, int> exit_point)
{
    string path;
    auto [x, y] = exit_point;

    while (parent[x][y] != make_pair(-1, -1))
    {
        auto [px, py] = parent[x][y];
        for (int d = 0; d < 4; d++)
        {
            if (x == px + directions[d].first && y == py + directions[d].second)
            {
                path.push_back(direction_labels[d]);
                break;
            }
        }
        x = px;
        y = py;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    monster_time.assign(n, vector<int>(m, INF));
    player_time.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start;
    // Read the grid
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
                player_time[i][j] = 0; // Start position for the player
                q_player.push({i, j});
            }
            else if (grid[i][j] == 'M')
            {
                monster_time[i][j] = 0; // Start positions for monsters
                q_monsters.push({i, j});
            }
        }
    }

    // Perform BFS for monsters first
    bfs_monsters();

    // Perform BFS for the player to find the path
    bool found = bfs_player();

    if (found)
    {
        cout << "YES" << endl;

        // Find the point where the player escaped (an edge point)
        for (int i = 0; i < n; i++)
        {
            if (player_time[i][0] < monster_time[i][0])
            {
                cout << player_time[i][0] << endl;
                cout << reconstruct_path({i, 0}) << endl;
                return 0;
            }
            if (player_time[i][m - 1] < monster_time[i][m - 1])
            {
                cout << player_time[i][m - 1] << endl;
                cout << reconstruct_path({i, m - 1}) << endl;
                return 0;
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (player_time[0][j] < monster_time[0][j])
            {
                cout << player_time[0][j] << endl;
                cout << reconstruct_path({0, j}) << endl;
                return 0;
            }
            if (player_time[n - 1][j] < monster_time[n - 1][j])
            {
                cout << player_time[n - 1][j] << endl;
                cout << reconstruct_path({n - 1, j}) << endl;
                return 0;
            }
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
