#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, k, in;
	cin >> n >> k;
	vector<int> v;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		a[i] = in;
		v.push_back(in);
	}

	sort(v.begin(), v.end());
	int t1 = -1, t2 = -1, temp1 = 0, temp2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] <= k)
		{
			int other = k - v[i];
			auto it = lower_bound(v.begin(), v.end(), other);
			if (other == v[i])
			{
				it++;
				if (it != v.end())
				{
					if (*it == other)
					{
						t1 = other;
						t2 = other;
						temp1 = 1;
						break;
					}
				}

			}
			else {
				auto it = lower_bound(v.begin(), v.end(), other);
				if (it != v.end() && *it == other)
				{
					t1 = v[i];
					t2 = other;
					temp2 = 1;
					break;
				}
			}
		}
	}

	if (temp1 == 1)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (t1 == a[i])
			{
				t1 = i + 1;
				count = i;
				break;
			}
		}
		for (int i = count + 1; i < n; i++)
		{
			if (t2 == a[i])
			{
				t2 = i + 1;
				break;
			}
		}
	}
	else
	{


		for (int i = 0; i < n; i++)
		{
			if (t1 == a[i])
			{
				t1 = i + 1;
				break;
			}

		}
		for (int i = 0; i < n; i++)
		{
			if (t2 == a[i])
			{
				t2 = i + 1;
				break;
			}

		}


	}
	if (temp1 == 0 && temp2 == 0)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << t1 << " " << t2 << endl;
	return 0;
}