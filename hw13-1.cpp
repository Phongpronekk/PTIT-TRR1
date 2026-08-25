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

int n, W;

struct bag
{
	int w, val;
};

bag a[10005];

bool cmp(bag a, bag b)
{
	return (float)a.val/a.w > (float)b.val/b.w;
}

int Try(int i, int w, int val)
{
	if(w > W) return 0;
	if(i == n && w <= W) return val;
	int l = Try(i+1, w+a[i].w, val+a[i].val);
	int r = Try(i+1, w, val);
	return max(l, r);
}

signed main()
{
	faster();
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> W;
		for(int i=0; i<n; i++)
		{
			cin >> a[i].w >> a[i].val;
		}
		sort(a, a+n, cmp);
		cout << Try(0, 0, 0) << endl;
	}
	return 0;
}

//#include <bits/stdc++.h>
//#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
//#define int long long
//#define endl "\n"
//#define pb push_back
//#define bp pop_back
//#define maxn 1000005
//#define mp make_pair
//#define fi first
//#define se second
//
//using namespace std;
//
//int f[1005][1005], n, m, a[1005], c[1005];
//
//int dyn()
//{
//	memset(f, 0, sizeof(f));
//	for(int i=1; i<=n; i++)
//	{
//		for(int j=1; j<=m; j++)
//		{
//			f[i][j] = f[i-1][j];
//			if(j >= a[i]) f[i][j] = max(f[i][j], f[i-1][j-a[i]] + c[i]);
//		}
//	}
//	return f[n][m];
//}
//
//signed main()
//{
//	int t; cin >> t;
//	while(t--)
//	{
//		cin >> n >> m;
//		for(int i=1; i<=n; i++) cin >> a[i];
//		for(int i=1; i<=n; i++) cin >> c[i];
//		cout << dyn() << endl;
//	}
//}

