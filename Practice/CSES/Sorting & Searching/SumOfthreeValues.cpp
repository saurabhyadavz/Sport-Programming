#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		v.push_back({in, i});
	}

	sort(v.begin(), v.end());
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		int l = i + 1;
		int r = n - 1;
		while (l < r)
		{
			if (v[i].first + v[l].first + v[r].first == k)
			{
				cout << v[i].second + 1 << " " << v[l].second + 1 << " " << v[r].second + 1 << endl;
				temp = 1;
				return 0;
			}
			else if (v[i].first + v[l].first + v[r].first < k)
				l++;
			else
				r--;
		}
	}
	if (!temp)
		cout << "IMPOSSIBLE" << endl;
	return 0;

}