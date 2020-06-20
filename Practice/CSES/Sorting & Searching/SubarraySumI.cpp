#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long int sum = 0, count = 0;
	map<long long int, long long int> mp;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (sum == k)
			count++;
		if (mp.find(sum - k) != mp.end())
		{
			count += mp[sum - k];
		}
		mp[sum]++;
	}
	cout << count << endl;
	return 0;

}