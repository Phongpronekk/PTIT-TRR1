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

void find(int index, int cnt, int sum, vector<int> &sub, vector<int> &a, int n, int k, int b, vector<vector<int>> &res)
{
	if(cnt == k && sum == b) // neu dung thi them vao kqua
	{
		res.pb(sub);
		return;
	}
	
	if(cnt > k || index >= n) return; // neu ko chon duoc nua thi dung lai
	
	sub.pb(a[index]); // thu voi phan tu a[index]
	find(index+1, cnt+1, sum+a[index], sub, a, n, k, b, res);
	sub.bp();
	find(index+1, cnt, sum, sub, a, n, k, b, res); // ko chon a[index] ma tiep tuc voi phan tu tiep thep
}

signed main()
{
	faster();
	int t; cin >> t;
	while(t--)
	{
		int n, k, b; cin >> n >> k >> b;
		vector<int> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		vector<vector<int>> res;
		vector<int> sub;
		
		find(0, 0, 0, sub, a, n, k, b, res);
		for(const auto &seq : res)
		{
			for(int num : seq) cout << num << " ";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
