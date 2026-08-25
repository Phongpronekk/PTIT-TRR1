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

int n, a[1005];

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
	for(int j=0; j<=1; j++)
	{
		a[i] = j;
		if(i == n) out();
		else Try(i+1);
	}
}

signed main()
{
	faster();
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		Try(1);
		cout << endl;
	}
	return 0;
}
