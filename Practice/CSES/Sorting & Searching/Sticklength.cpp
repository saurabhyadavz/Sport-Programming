#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if (n % 2 != 0)
	{
		int mid1 = a[n / 2];
		long long int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += abs(a[i] - mid1);
		}
		cout << sum << endl;
	}
	else
	{
		int mid1 = a[n / 2];
		int mid2 = a[n / 2 - 1];
		long long int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++)
		{
			sum1 += abs(a[i] - mid1);
			sum2 += abs(a[i] - mid2);
		}
		cout << min(sum1, sum2) << endl;
	}
	return 0;
}