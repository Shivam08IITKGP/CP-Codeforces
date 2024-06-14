int cnt[200001][26];

int differ(int u,int v)
{
    int r=0,mx=0;
    for(int j=0;j<26;j++)
    {
        r+= cnt[u][j]+cnt[v][j];
        remax(mx, cnt[u][j]+cnt[v][j]);
    }
    return r- mx;

}

void solve()
{

    //min possible operations to make k length substrings as palindrome
    //and make it periodic
    int n,k;
    string s;
    cin>>n>>k>>s;
    memset(cnt,0,sizeof(cnt));

    for(int i=0;i<n;i++)
    {
        cnt[i%k][s[i]-'a']++;
    }
    int ans= 0;

    for(int i=0;i<k;i++)
    {
        ans+= differ(i,k-i-1);


    }
    cout<<ans/2<<endl;
    
    

}
