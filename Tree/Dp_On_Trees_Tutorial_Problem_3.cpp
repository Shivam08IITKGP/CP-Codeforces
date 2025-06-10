#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define EB emplace_back
#define sz(v) (int)v.size()
#define int long long
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define rall(o) (o).rbegin(), (o).rend()
#define mset(m, v) memset(m, v, sizeof(m))
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define rep(i, a, b) for (ll i = a; i <= b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; i--)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define pb push_back
#define endl '\n'
#define cy                 \
    cout << "YES" << endl; \
    return;
#define cn                \
    cout << "NO" << endl; \
    return;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> graph;
typedef vector<vii> wgraph;
long double EPS = 1e-9;
long long M = 998244353;
const int N = 1e9 + 7;
const int V = 2e5 + 5;
const int INF = 1e18;

#define debarr(a, n)            \
    cout << #a << " : ";        \
    for (int i = 0; i < n; i++) \
        cerr << a[i] << " ";    \
    cerr << endl;
#define debmat(mat, row, col)         \
    cout << #mat << " :\n";           \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cerr << mat[i][j] << " "; \
        cerr << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
    for (auto &it : p)
        os << it << " ";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
void dbs(string str, T t) { cerr << str << " : " << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b)
{
    cerr << "[";
    for (T i = a; i != b; ++i)
    {
        if (i != a)
            cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}
template <class T>
void read(T &x) { cin >> x; }
template <class H, class... T>
void read(H &h, T &...t)
{
    read(h);
    read(t...);
}
template <class T>
void read(vector<T> &a)
{
    for (int i = 0; i < sz(a); i++)
        read(a[i]);
}
template <class T>
void read1(vector<T> &a)
{
    for (int i = 1; i < sz(a); i++)
        read(a[i]);
}
ll binpow(ll b, ll p)
{
    ll ans = 1;
    ;
    for (; p; p >>= 1)
    {
        if (p & 1)
            ans = ans * b;
        b = b * b;
    }
    return ans;
}

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

void solve()
{
    int n, k;
    cin >> n >> k;

    graph g(n);
    fr(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    graph f(n, vi(k + 1, 0));
    function<void(int, int)> dfs = [&](int u, int p)
    {
        f[u][1] = 1;
        vi dp(k + 1, 0);

        for (auto &child : g[u])
        {
            if (child == p)
                continue;
            dfs(child, u);

            vi new_dp(k + 1, 0);
            fr(i, k + 1)
            {
                fr(j, k - i + 1)
                {
                    new_dp[i + j] += f[u][i] * dp[j];
                }
            }
            dp = new_dp;
        }
        f[u] = dp;
    };

    dfs(0, -1);

    int ans = 0;
    fr(i, k + 1)
    {
        fr(j, n)
        {
            ans += f[j][i];
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}