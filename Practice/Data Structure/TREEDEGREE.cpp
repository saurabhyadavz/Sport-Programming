#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[2 * n];
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> a[i];
		}
		stack<int> s;
		map<int, int> count, mp;
		for (int i = 0; i < 2 * n; i++)
		{
			mp[a[i]]++;
			if (mp[a[i]] == 1)
			{
				s.push(a[i]);
			}
			else {
				if (s.size() == 1)
				{
					s.pop();
				}
				else
				{
					count[s.top()]++;
					s.pop();
					if (s.size() != 0)
						count[s.top()]++;
				}


			}
		}
		int max1 = 0;

		for (auto it : count)
		{
			max1 = max(max1, it.second);
			// cout << it.first <</ "->" << it.second << endl;
		}
		cout << max1 << endl;
	}
}