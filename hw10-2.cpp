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

int n, k, a[1005];

void out()
{
	for(int i=1; i<k; i++)
	{
		cout << a[i];
	}
	cout << " ";
}

void Try(int i)
{
	for(int j=a[i-1]+1; j<=n-k+i; j++)
	{
		a[i] = j;
		if(i == k) out();
		else Try(i+1);
	}
}

signed main()
{
	faster();
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> k;
		Try(1);
		cout << endl;
	}
}
