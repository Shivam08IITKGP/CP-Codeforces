/*
Take a look at this greedy approach.
Let pi be the i-th poorest invited person.(pi < Pi+l)
Find the poorest person v that x — 1 — av <= O < bv. 
We will invite this person so p1 = v.
For each 2<=i <=c find the poorest person v that v > p[i-1] 
and x — 1 — av <=i — 1 <= bv this means that person v can be the 
i-th poorest invited person.
Imagine we fail to find x people but there is a way to do so.
The solution chooses S1 , s2,..... , Sx.
for each i we chose the minimum Pi possible, therefor pi<=Si.
But if our algorithm fails there must exist an index i that Pi > Si.
So out algorithm is correct.
T = O(nlogn)
*/

void solve()
{
    int n;
    cin >> n;
    vi a(n), b(n);
    fr(i, n)
    {
        cin >> a[i] >> b[i];
    }
 
    function<bool(int)> check = [&](int x) -> bool
    {
        int cnt = 0;
        fr(i, n)
        {
            if ((x - 1 - a[i] <= cnt) and (cnt <= b[i]))
                cnt++;
        }
        return cnt >= x;
    };
 
    int l = -1, r = n + 1;
    int ans = 0;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}
