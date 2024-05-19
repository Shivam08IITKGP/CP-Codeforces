#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i, start, end) for (ll i = start; i < end; i++)
#define fr(i, start, end) for (ll i = start; i > end; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define v vector
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

class DisjointSet
{
    vector<int> parent, sizes;

public:
    DisjointSet(int size) : parent(size), sizes(size, 1)
    {
        f(i, 0, size)
        {
            parent[i] = i;
        }
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        else
            return find(parent[i]);
    }

    void union_byset(int i, int j)
    {
        int i_root = find(i);
        int j_root = find(j);
        if (i_root == j_root)
        {
            return;
        }
        int i_size = sizes[i_root];
        int j_size = sizes[j_root];
        if (i_size > j_size)
        {
            parent[j_root] = i_root;
            j_size += i_size;
        }
        else
        {
            parent[i_root] = j_root;
            i_size += j_size;
        }
        return;
    }
    int areConnected(int x, int y)
    {
        return find(x) == find(y);
    }
    int size(int x)
    {
        return sizes[x];
    }
};

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    DisjointSet dsu(n);
    vector<int> arr(n);
    map<int,int>m;
    f(i, 0, n)
    {
        cin >> arr[i];
        m[arr[i]]=i;
    }
    vector<bool> can_a(n,0), can_b(n,0);
    f(i, 0, n)
    {
        if (m.count(a-arr[i]))
        {
            dsu.union_byset(i, m[a-arr[i]]);
            can_a[i] = true;
        }
        if (m.count(b-arr[i]))
        {
            dsu.union_byset(i, m[b-arr[i]]);
            can_b[i] = true;
        }
    }

    vector<int> can_components(n, 3);
    f(i, 0, n)
    {
        int mask = 0;
        if (can_a[i])
            mask += 1;
        if (can_b[i])
            mask += 2;
        can_components[dsu.find(i)]= mask&(can_components[dsu.find(i)]);
        // if i belong to set 1 only then mask& this will be 1
        // if i belong to set 2 only then mask& this will be 2
    }

    //checking if there is no left number that is not gone to any one of the two sets
    f(i,0,n)
    {
        if(!can_components[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    f(i,0,n)
    {
        int mask= can_components[dsu.find(i)];
        if(mask==1)
        {
            cout<<0<<" ";
        }
        else 
        {
            cout<<1<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    FAST;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
