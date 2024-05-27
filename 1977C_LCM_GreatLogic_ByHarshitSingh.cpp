#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define EB emplace_back
#define sz(v) (int)v.size()
#define int long long
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define rep(i, a, b) for (ll i = a; i <= b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; i--)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> graph;
long double EPS = 1e-9;
long long M = 998244353;

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
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
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
ll binpow(ll b, ll p)
{
    ll ans = 1;
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

long long lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    fr(i, n) cin >> a[i];

    sort(all(a));
    fr(i, n)
    {
        if (a[n - 1] % a[i] != 0)
        {
            cout << n << endl;
            return;
        }
    }
  /* now if the function is running here 
  then it means that all the numbers divide the last number
  It means that lcm should be smaller than the last number
  But as we know all numbers divide a[n-1], so one of the factors of a[n-1]
  can be the possible lcms which is not in the array

  So we check if a subsequence is possible whoose lcm is v (v is not present in the array)
  */
  
    map<int, int> m;
    fr(i, n)
    {
        m[a[i]] = 1;
    }
    vector<int> factors;
    for (int i = 1; i * i <= a[n - 1]; i++)
    {
        if (a[n - 1] % i == 0)
        {
            factors.pb(i);
            if (i != a[n - 1] / i)
            {
                factors.pb(a[n - 1] / i);
            }
        }
    }

    int cnt = 0, curr = 1, ans = 0;
    for (auto v : factors)
    {
        if (m.find(v) != m.end())
            continue;
        cnt = 0, curr = 1;
        for (int i = 0; i < n; i++)
        {
            if (v % a[i] == 0)
            {
                curr = lcm(curr, a[i]);
                cnt++;
            }
            else if (v < a[i])
            {
                break;
            }
        }
        if (curr == v)
            remax(ans, cnt);
    }
    cout << ans << endl;
}

int32_t main()
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
