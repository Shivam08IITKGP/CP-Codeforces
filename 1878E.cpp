#include <bits/stdc++.h>
using namespace std;

#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;
#define vll vector<ll>
#define vi vector<int>

void build(int index, int l, int r, vi &a, vi &segment_tree)
{
    if (l == r)
    {
        segment_tree[index] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index + 1, l, mid, a, segment_tree);
    build(2 * index + 2, mid + 1, r, a, segment_tree);
    segment_tree[index] = segment_tree[2 * index + 1] & segment_tree[2 * index + 2];
}

int query(int index, int l, int r, int ql, int qr, vi &segment_tree)
{
    if (l > qr || r < ql)
    {
        return INT_MAX;
    }
    if (l >= ql && r <= qr)
    {
        return segment_tree[index];
    }
    int mid = (l + r) / 2;
    int left = query(2 * index + 1, l, mid, ql, qr, segment_tree);
    int right = query(2 * index + 2, mid + 1, r, ql, qr, segment_tree);
    return left & right;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi segment_tree(4 * n);
    build(0, 0, n - 1, a, segment_tree);
    int q;
    cin >> q;
    while (q--)
    {
        int l, k;
        cin >> l >> k;
        l--;

        if (a[l] < k)
        {
            cout << -1 << " ";
            continue;
        }

        int high = n - 1, low = l;
        int ans = l;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (query(0, 0, n - 1, l, mid, segment_tree) >= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans + 1 << " ";
    }
    cout << endl;
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
}
