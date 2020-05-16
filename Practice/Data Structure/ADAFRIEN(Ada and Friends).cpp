#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
	int n, k;
	cin >> n >> k;
	vector<pair<int, string>> v;
	map<string, int> mp;
	for (int i = 0; i < n; i++)
	{
		string s;
		int c;
		cin >> s >> c;
		mp[s] += c;
	}
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		v.push_back(make_pair(it->second, it->first));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		ans += v[i].first;
		k--;
		if (k == 0)
			break;
	}
	cout << ans << endl;
	return 0;


}