// Reference: spoj.com/problems/RMID2

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
	int t;
	scanf("%lld", &t);
	while (t--)
	{
		int n;
		priority_queue<int> maxH;
		priority_queue < int, vector<int>, greater<int>> minH;
		while (true)
		{
			scanf("%lld", &n);
			if (n == 0) break;

			if (n == -1)
			{
				printf("%lld\n", maxH.top() );
				maxH.pop();
				if (maxH.size() < minH.size())
				{
					maxH.push(minH.top());
					minH.pop();
				}
			}
			else
			{
				if (maxH.size() == 0 && minH.size() == 0)
					maxH.push(n);
				else {
					if (n <= maxH.top())
						maxH.push(n);
					else
						minH.push(n);

					if (maxH.size() < minH.size())
					{
						maxH.push(minH.top());
						minH.pop();
					}
					else if (maxH.size() > minH.size() + 1)
					{
						minH.push(maxH.top());
						maxH.pop();
					}

				}
			}

		}
	}
}