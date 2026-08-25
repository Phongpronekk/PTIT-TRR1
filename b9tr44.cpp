#include <iostream>
#include <vector>

using namespace std;

int n, W, K;
vector<int> a, c;
vector<int> solution;
vector<vector<int>> results;


void backtrack(int index, int sumA, int sumC)
{
    
    if (sumC == K && sumA <= W)
	{
        results.push_back(solution);
    }

    if (index >= n || sumA > W || sumC > K)
	{
        return;
    }

    solution.push_back(1);
    backtrack(index + 1, sumA + a[index], sumC + c[index]);
    solution.pop_back();

    solution.push_back(0);
    backtrack(index + 1, sumA, sumC);
    solution.pop_back();
}

int main()
{
    cin >> n;
    cin >> W;
    cin >> K;

    a.resize(n);
    c.resize(n);
    for (int i = 0; i < n; ++i)
	{
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
	{
        cin >> c[i];
    }

    backtrack(0, 0, 0);

    for (const auto& vec : results)
	{
        for (int x : vec)
		{
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

