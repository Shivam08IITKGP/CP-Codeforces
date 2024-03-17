#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long int ll;

// First i thought that Alice will pick elements in this way 0 ,1 ,2 ,....
// So there should be atleast 2 occurences of a number so that it can not be a MEX.
// As If Bob picks the first occurences of a number, Alice will pick that number in the next turn.

// Now(I realised later), we can directly skip 0 and go to the number that has got only 1 occurence
// (if 0 has got more than one occurences). 
// Alice picks that number.
// This number can't be a MEX. 
// The next number that has got one occurence will be a MEX. 

// Now if array is only '0' (array.size=1), then by logic no number will be printed.
void solve()
{
    int n;
    cin >> n;

    vector<int> count_occurences(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        count_occurences[x]++;
    }
    if (n == 1 and count_occurences[0] == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (count_occurences[0] == 0)
    {
        cout << 0 << endl;
        return;
    }
    bool got_1_occurence_number = false;
    for (int i = 0; i < n; i++)
    {
        if (count_occurences[i] == 0)
        {
            cout << i << endl;
            return;
        }
        if (count_occurences[i] == 1 and got_1_occurence_number)
        {
            cout << i << endl;
            return;
        }
        if (count_occurences[i] == 1)
        {
            got_1_occurence_number = true;
        }
    }
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
    return 0;
}
