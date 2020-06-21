#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		v.push_back({in, i});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++ )
		{
			int l = j + 1;
			int r = n - 1;
			while (l < r)
			{
				if (v[i].first + v[j].first + v[l].first + v[r].first == k)
				{
					printf("%d %d %d %d\n", v[i].second + 1, v[j].second + 1, v[l].second + 1, v[r].second + 1 );
					return 0;
				}
				if (v[i].first + v[j].first + v[l].first + v[r].first < k)
					l++;
				else
					r--;
			}
		}
	}

	printf("IMPOSSIBLE\n");
	return 0;

}