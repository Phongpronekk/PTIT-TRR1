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

const int n = 4;
int coefficients[] = {10, 5, 3, 6};
int weights[] = {5, 3, 2, 4};        
int maxWeight = 8;              

int maxProfit = 0;                  


void backtrack(int idx, int currentProfit, int currentWeight, vector<int>& solution, vector<int>& bestSolution)
{
    if (currentWeight > maxWeight) return;

    if (currentProfit > maxProfit)
	{
        maxProfit = currentProfit;
        bestSolution = solution;
    }

    for (int i = idx; i < n; ++i)
	{
        for (int j = 1; ; ++j)
		{
            if (currentWeight + j * weights[i] > maxWeight) break;

            solution[i] += j;
            backtrack(i + 1, currentProfit + j * coefficients[i], currentWeight + j * weights[i], solution, bestSolution);
            solution[i] -= j;
        }
    }
}

signed main()
{
	faster();
    vector<int> solution(n, 0);       
    vector<int> bestSolution(n, 0);     

    backtrack(0, 0, 0, solution, bestSolution);

    cout << maxProfit << endl;

    for (int i = 0; i < n; ++i) {
        cout << bestSolution[i] << " ";
    }
    cout << endl;
    return 0;
}
