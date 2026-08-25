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

void find(int index, vector<int> &sub, vector<int> &a, int n, int k, vector<vector<int>> &res)
{
	int sum = 0;
	for(int n : sub) sum += n; // tinh tong day con
	if(sum == k) res.pb(sub); // neu dung thi them day con vao kqua
	for(int i=index; i<n; i++)
	{
		sub.pb(a[i]); // cho a[i] vao day
		find(i+1, sub, a, n, k, res); // de quy voi phan tu ke tiep
		sub.bp();
	}
}

signed main()
{
	faster();
	int t; cin >> t;
	while(t--)
	{
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		vector<vector<int>> res; // luu tru day con co tong bang k
		vector<int> sub; // day con tam thoi
		find(0, sub, a, n, k, res);
		for(const auto &seq : res)
		{
			for(int num : seq) cout << num << " ";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
