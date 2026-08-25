#include <iostream>
#include <vector>

using namespace std;

int n, K, S;
vector<int> a;
vector<int> solution;
vector<vector<int>> results;

void backtrack(int index, int count, int sum)
{
    if (count == K && sum == S) {
        results.push_back(solution);
        return;
    }

    if (index >= n || count > K || sum > S)
	{
        return;
    }

    solution.push_back(1);
    backtrack(index + 1, count + 1, sum + a[index]);
    solution.pop_back();

    solution.push_back(0);
    backtrack(index + 1, count, sum);
    solution.pop_back();
}

int main()
{
    cin >> n;
    cin >> K;
    cin >> S;

    a.resize(n);
    for (int i = 0; i < n; i++)
	{
        cin >> a[i];
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

