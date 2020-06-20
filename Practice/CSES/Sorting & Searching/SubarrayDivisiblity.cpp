#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long int in, fre[n] = {};
	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		sum += in;
		int rem = sum % n;
		if (rem < 0)
			rem += n;
		fre[rem]++;
	}
	long long int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (fre[i] > 1)
		{
			ans += ((fre[i]) * (fre[i] - 1)) / 2;
		}
	}
	ans += fre[0];
	cout << ans << endl;
}