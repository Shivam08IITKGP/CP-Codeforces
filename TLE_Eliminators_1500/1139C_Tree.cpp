long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

const int N = 1e9 + 7;
class DisjointSet
{
    vector<int> parent, size;
    int n;

public:
    DisjointSet(int n)
    {
        this->n = n;
        parent.resize(n + 1); // Resize for 1-based indexing
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find_parent(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find_parent(parent[x]); // Path compression
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
        if (size[x_root] < size[y_root])
        {
            parent[x_root] = y_root;
            size[y_root] += size[x_root];
        }
        else
        {
            parent[y_root] = x_root;
            size[x_root] += size[y_root];
        }
    }

    bool is_same_set(int x, int y)
    {
        return find_parent(x) == find_parent(y);
    }

    vector<unordered_set<int>> get_components()
    {
        unordered_map<int, unordered_set<int>> components_map;
        for (int i = 1; i <= n; i++)
        {
            int root = find_parent(i);
            components_map[root].insert(i);
        }
        vector<unordered_set<int>> components;
        for (auto &entry : components_map)
        {
            components.push_back(entry.second);
        }
        return components;
    }
};
// A sequence does not mean that it is a path from one node to another node
// Here in question we are said that you can choose a sequence a1 a2 a3 a4....ak
// such that you have to go from a1 to a2 , a2 to a3, not necesarily adjacent nodes
// Hence total sequecnes is equal to n^k 
// If we step completely into a red component then there will be no black edges
void solve()
{
    int n, k;
    cin >> n >> k;
    DisjointSet d(n);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0)
        {
            d.union_set(u, v);
        }
    }
    vector<unordered_set<int>> ans = d.get_components();
    // cout<<ans<<endl;
    int res = binpow(n, k, N);
    for (auto st : ans)
    {
        res = (res - (binpow(st.size(), k, N)) + N) % N;
    }
    cout << res << endl;
}
