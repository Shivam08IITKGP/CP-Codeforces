const int N = 2e5 + 1;
int smallestPrime[N];
vi primeFactors[N];
void seive()
{
    for (int i = 2; i < N; i++)
        smallestPrime[i] = i;

    for (int i = 2; i < N; i++)
    {
        if (smallestPrime[i] == i)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                smallestPrime[j] = min(smallestPrime[j], i);
            }
        }
    }
}
int n;
graph g(N);
vi a(N);
vi indp1[N], indp2[N], outdp[N];

void indfs(int node, int par)
{
    for (int ch : g[node])
    {
        if (ch != par)
        {
            indfs(ch, node);
            for (int i = 0; i < primeFactors[a[node]].size(); i++)
            {
                for (int j = 0; j < primeFactors[a[ch]].size(); j++)
                {
                    if (primeFactors[a[node]][i] == primeFactors[a[ch]][j])
                    {
                        int temp = 1 + indp1[ch][j];
                        if (indp1[node][i] < temp)
                        {
                            indp2[node][i] = indp1[node][i];
                            indp1[node][i] = temp;
                        }
                        else if (indp2[node][i] < temp)
                        {
                            indp2[node][i] = temp;
                        }
                    }
                }
            }
        }
    }
}
void outdfs(int node, int par)
{
    for (int ch : g[node])
    {
        if (ch != par)
        {
            for (int i = 0; i < primeFactors[a[node]].size(); i++)
            {
                for (int j = 0; j < primeFactors[a[ch]].size(); j++)
                {
                    if (primeFactors[a[node]][i] == primeFactors[a[ch]][j])
                    {
                        outdp[ch][j] = max(outdp[ch][j], 1 + outdp[node][i]);
                        if (indp1[node][i] == indp1[ch][j] + 1)
                        {
                            outdp[ch][j] = max(outdp[ch][j], indp2[node][i]);
                        }
                        else
                        {
                            outdp[ch][j] = max(outdp[ch][j], indp1[node][i]);
                        }
                    }
                }
            }
            outdfs(ch, node);
        }
    }
}

void solve()
{
    cin >> n;

    rep(i, 1, n)
    {
        cin >> a[i];
        int num = a[i];
        vector<int> temp(0);
        while (num > 1)
        {
            int p = smallestPrime[num];
            temp.pb(p);
            while (num % p == 0)
            {
                num /= p;
            }
        }
        primeFactors[a[i]] = temp;

        indp1[i].assign(temp.size(), 1);
        indp2[i].assign(temp.size(), 1);
        outdp[i].assign(temp.size(), 0);
    }

    rep(i, 1, n - 1)
    {
        int u, v;
        read(u, v);
        g[u].pb(v);
        g[v].pb(u);
    }

    indfs(1, -1);
    outdfs(1, -1);
    int ans = 0;
    rep(i, 1, n)
    {
        for(int p=0;p<primeFactors[a[i]].size();i++)
        {
            ans = max(ans, indp1[i][p] + outdp[i][p]);
        }
    }

    cout << ans << endl;
}
