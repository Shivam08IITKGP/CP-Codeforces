#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
void solve(int n)
{
	string s;
	cin >> s;
	char maxright[n];
	maxright[n - 1] = s[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		maxright[i] = max(maxright[i + 1], s[i]);
	}
	int prefix = 1;
	//it stores the maximum length of prefix that is equal to each other
	//when we reverse bba, then if do not subtract prefix, then answer will be 2
	//and we get abb then bba 
	//so we subtract prefix from size
	vector<int> indices;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == maxright[i])
		{
			indices.push_back(i);
		}
	}
	int size = indices.size();

	for (int i = 1; i < size; i++)
	{
		if (s[indices[i]] == s[indices[i - 1]])
		{
			prefix++;
		}
		else
		{
			break;
		}
	}
	for (int i = 0, j = size - 1; i <= j; i++, j--)
	{
		swap(s[indices[i]], s[indices[j]]);
	}
	bool flag = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] > s[i + 1])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << size - prefix << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}
int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		solve(n);
	}
}
