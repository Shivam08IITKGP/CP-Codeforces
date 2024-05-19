#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

class DisjointSet
{
    vector<int> parent, rank;
    int n;

public:
    DisjointSet(int n)
    {
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find_parent(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find_parent(parent[x]);
        }
        return parent[x];
    }
    void union_set(int x, int y)
    {
        int x_root = find_parent(x);
        int y_root = find_parent(y);
        if (x_root == y_root)
        {
            return;
        }
        if (rank[x_root] < rank[y_root])
        {
            parent[x_root] = y_root;
        }
        else if (rank[x_root] > rank[y_root])
        {
            parent[y_root] = x_root;
        }
        else
        {
            parent[y_root] = x_root;
            rank[x_root]++;
        }
    }
    bool is_same_set(int x, int y)
    {
        return find_parent(x) == find_parent(y);
    }
    int get_num_components()
    {
        int num_components = 0;
        for (int i = 1; i < n; i++)
        {
            if (parent[i] == i)
            {
                num_components++;
            }
        }
        return num_components;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    DisjointSet ds(n + 1);
    f(i, 1, n + 1)
    {
        cin >> v[i];
        ds.union_set(i, v[i]);
    }
    vector<set<int>> adj(n + 1);
    // We are using set here if i remembers j and j also remembers i
    //, then it will be duplicate and set will take care of it.
    f(i, 1, n + 1)
    {
        adj[i].insert(v[i]);
        adj[v[i]].insert(i);
    }

    vector<int> d(n + 1);
    f(i, 1, n + 1)
    {
        d[i] = adj[i].size();
    }
    int bamboos = 0, cycles = 0;
    vector<bool> vis(n+1);
    //Bfs on the graph
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            vector<int> component = {i};
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                        component.push_back(v);
                    }
                }
            }
            bool bamboo = false;
            for (int j : component)
            {
                if (d[j] == 1)
                {
                    bamboo = true;
                    break;
                }
            }
            if (bamboo)
            {
                bamboos++;
            }
            else
            {
                cycles++;
            }
        }
    }
    cout << cycles + min(bamboos, 1) << " " << ds.get_num_components() << "\n";
    /*
    OR
    cout<<cycles+min(bamboos,1)<<" "<<bamboos+cycles<<"\n";
    */
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
