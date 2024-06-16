
int g[1500][1500] = {};
vi ans(2000001);
void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    int curr = 1;
    for (int i = 1; i < 1500; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            // Total sum of row and column is i
            // From bottom left to upper right
            // for seeing the matrix click the link below
            // https://drive.google.com/file/d/1Q4Q0vT7YzDrLRMgESpwLJbvVo_jcKpj5/view?usp=sharing
            g[j][i - j] = g[j - 1][i - j] + g[j][i - j - 1] - g[j - 1][i - j - 1] + curr * curr;
            ans[curr++] = g[j][i - j];
        }
    }
    while (t--)
    {
        solve();
    }
}
