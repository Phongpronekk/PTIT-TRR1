#include <bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define pb push_back
#define bp pop_back
#define maxn 1000005
#define mp make_pair
#define fi first
#define se second

using namespace std;

int n, a[100005], used[100005];

void out()
{
	for(int i=1; i<=n; i++)
	{
		cout << a[i];
	}
	cout << " ";
}

void Try(int i)
{
	for(int j=1; j<=n; j++)
	{
		if(used[j] == 0)
		{
			a[i] = j;
			used[j] = 1;
			if(i == n) out();
			else Try(i+1);
			
			
			//backtrack
			used[j] = 0;
		}
	}
}

signed main()
{
	faster();
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		memset(used, 0, sizeof(used));
		Try(1);
		cout << endl;
	}
	return 0;
}

