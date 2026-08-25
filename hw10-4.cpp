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

bool check(const string &s, int k, int m)
{
	int cnt0 = 0, cnt1 = 0;
	int seq0 = 0, seq1 = 0;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] == '0')
		{
			cnt1 = 0; 
			cnt0++;
		}
		else
		{
			cnt0 = 0;
			cnt1++;
		}
		
		if(cnt0 == k) seq0++;
		if(cnt1 == m) seq1++;
		if(cnt0 > k) seq0 = 2;
		if(cnt1 > m) seq1 = 2;
	}
	return seq0 == 1 && seq1 == 1;
}

void gen(int n, int k, int m, string &cur, vector<string> &res)
{
	if(cur.length() == n)
	{
		if(check(cur, k, m)) res.pb(cur);
		return;
	}
	
	cur.pb('0');
	gen(n, k, m, cur, res);
	cur.bp();
	cur.pb('1');
	gen(n, k, m, cur, res);
	cur.bp();
}

signed main()
{
	faster();
	int t; cin >> t;
	while(t--)
	{
		int n, k, m; cin >> n >> k >> m;
		vector<string> res;
		string cur = "";
		gen(n, k, m, cur, res);
		for(const string &s : res)
		{
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
