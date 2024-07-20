#include <bits/stdc++.h>
#define fo freopen((NAME+".INP").c_str(), "r", stdin), freopen((NAME+".OUT").c_str(), "w", stdout)
#define pb push_back
#define ppb pop_back
#define fr first
#define sc second
#define all(v) v.begin(), v.end()
#define mod (long long)(1e9 + 7)
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
void solve(){
    int n, ans = 0;
    cin >> n;
 
    vector <int> a(n + 1);
 
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] > 4) a[i] = 0, ans ++;
        a[i] += (a[i] & 1);
    }
 
    for(int i = 2; i <= n; i ++){
        if(a[i] == 4 && a[i - 1] == 4){
            ans ++;
            a[i] = a[i - 1] = 2;
        } 
    }
 
    for(int i = 2; i <= n; i ++){
        if(a[i] == 2 && a[i - 1] == 2){
            ans ++;
            a[i] = a[i - 1] = 0;
        } 
    }
 
    for(int i = 1; i <= n; i ++) if(a[i]) ans ++;
 
        cout << ans;
} 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n = 1;
    cin >> n;
 
    // cout << 1; return 1;
 
    while(n){ 
        solve();
        n --;
        cout << "\n";
    }
} 
