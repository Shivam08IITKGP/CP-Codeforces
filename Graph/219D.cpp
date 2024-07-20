#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[200005];
int dist[200005];
int redOnPath[200005];
int redEntireTree = 0;

void dfs(int v, int p)
{
    for (auto edge : adj[v])
    {
        int to = edge.first;
        int color = edge.second; // 0 for green, 1 for red
        if (to == p)
            continue;
        dist[to] = dist[v] + 1;
        redOnPath[to] = redOnPath[v] + color;
        redEntireTree += color;
        dfs(to, v);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0}); // green edge
        adj[v].push_back({u, 1}); // red edge
    }

    dfs(1, -1);

    int minFlips = INT_MAX;
    vector<int> capitals;

    for (int i = 1; i <= n; ++i)
    {
        int flips = redEntireTree - 2 * redOnPath[i] + dist[i];
        if (flips < minFlips)
        {
            minFlips = flips;
            capitals.clear();
            capitals.push_back(i);
        }
        else if (flips == minFlips)
        {
            capitals.push_back(i);
        }
    }

    sort(capitals.begin(), capitals.end());
    cout << minFlips << endl;
    for (int capital : capitals)
    {
        cout << capital << " ";
    }
    cout << endl;

    return 0;
}
