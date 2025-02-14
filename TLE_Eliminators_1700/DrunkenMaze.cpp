// You also need to store the number of steps, and the direction you used to get to a cell
// Because suppose at first you reached a cell by some path, and felt that this path is not good to reach this point
// SO you mark it as visited
// Suppose you use another path which is good to the same cell, then you won't be able to traverse further because,
// you marked it as visited

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Structure to hold the current position and state.
struct State
{
    int x, y;  // Current cell coordinates
    int d;     // Last direction taken (0: up, 1: right, 2: down, 3: left). -1 means no move yet.
    int count; // Number of consecutive steps in the same direction (if d != -1)
    int steps; // Steps taken so far
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; // Read maze dimensions

    // Read the maze grid line by line
    vector<string> maze(n);
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
    }

    // Find the start (S) and target (T) positions.
    int startX, startY, targetX, targetY;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
            else if (maze[i][j] == 'T')
            {
                targetX = i;
                targetY = j;
            }
        }
    }

    // visited[x][y][dir][cnt]: for cell (x,y) having reached it with
    // the last move 'dir' (0 to 3) and consecutive steps 'cnt' (1 to 3).
    // Note: For the initial state (with no direction), we do not need a visited flag.
    vector<vector<vector<vector<bool>>>> visited(
        n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(4, false))));

    // Standard BFS queue.
    queue<State> q;
    // Start state: position at S, no previous direction (d = -1), count 0, and 0 steps.
    q.push({startX, startY, -1, 0, 0});

    // Movement vectors: up, right, down, left.
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        // If we reached the target, output the number of steps.
        if (cur.x == targetX && cur.y == targetY)
        {
            cout << cur.steps;
            return 0;
        }

        // Try all four possible directions.
        for (int d = 0; d < 4; d++)
        {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            // Skip if new cell is out of bounds or a wall.
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (maze[nx][ny] == '#')
                continue;

            // Calculate new consecutive count based on whether we
            // continue moving in the same direction or change direction.
            int ncount = (cur.d == d ? cur.count + 1 : 1);

            // Cannot take more than three consecutive steps in the same direction.
            if (ncount > 3)
                continue;

            // For the initial state (cur.d == -1), no visit check is required.
            if (cur.d != -1 && visited[nx][ny][d][ncount])
                continue;

            // Mark the state as visited.
            if (cur.d != -1)
                visited[nx][ny][d][ncount] = true;
            else
            {
                // Even if starting from the initial cell, after making a move we treat
                // the resulting state as visited for that direction and count.
                visited[nx][ny][d][ncount] = true;
            }

            // Push the new state to the queue.
            q.push({nx, ny, d, ncount, cur.steps + 1});
        }
    }

    // If no valid path is found, output -1.
    cout << -1;
    return 0;
}
