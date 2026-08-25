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
#define t() int tc; cin >> tc; while(tc--)

using namespace std;

int n, c[105][105], x[105];
int vis[105];
int dis = 0, ans = 1e9, cmin = 1e9;

void inp()
{
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> c[i][j];
			if(c[i][j] != 0) cmin = min(cmin, c[i][j]);
		}
	}
	memset(vis, 0, sizeof(int));
}

void Try(int i)
{
	for(int j=1; j<=n; j++)
	{
		if(vis[j] == 0)
		{
			vis[j] = 1;
			x[i] = j;
			dis += c[x[i-1]][x[i]];
			if(i == n) ans = min(ans, dis + c[x[n]][1]);
			// danh gia can
			else if(dis + (n-i+1) * cmin < ans) Try(i+1);
			// backtrack
			vis[j] = 0;
			dis -= c[x[i-1]][x[i]];
		}
	}
}

signed main()
{
	faster();
	t()
	{
		inp();
		x[1] = 1, vis[1] = 1;
		Try(2);
		cout << ans << endl;
	}
	return 0;
}
