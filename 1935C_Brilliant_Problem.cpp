#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

//First very important to note
//when we calculate the sum of differences of the first element of pairs,
//It is actually equal to the distance between the last and first first element of the pair

//Hence we may be benifited by not storing the differences in the sum variable and instead
//just adding the second element of the pair and check p[r].first - p[l].first + sum > limit
void solve()
{
    int n, limit;
    cin >> n >> limit;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    // p[i].first is b[i] and p[i].second is a[i]
    // We sort according to b[i]
    // Now we will use two pointer technique
    // For a particular index we will see how many elements we can take,
    // which are having larger b[i]s' than the current element
    int ans = 0;
    for (int l = 0; l < n; l++)
    {
        priority_queue<int> pq;
        int sum = 0;
        //sum variable will store sum of only a[i]s'
        for (int r = l; r < n; r++)
        {
            pq.push(p[r].second);
            sum += p[r].second;
            while (!pq.empty() && p[r].first - p[l].first + sum > limit)
            {
                sum -= pq.top();
                pq.pop();
            }
            //this is sort of a dp approach from here

            //Here suppose l=1 and we have indices r = 3 ,4 in the pq
            //Now we check for r= 5,6 and so on
            //We actually know that taking 5 and 6 is much more optimal than taking 3 and 4
            //Then we can just remove 3 and 4 from the pq and add 5 and 6

            //pq.top() is a[i] which is not in ascending order
            //So we can remove the top element and add the smaller a[i] to the pq
            ans = max(ans, (int)pq.size());
        }
    }
    cout << ans << endl;
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
