#include<bits/stdc++.h>
using namespace std;

#define int long long int

#define MAX 100001

int tree[6 * MAX];
int lazy[6 * MAX];

void update(int node, int s, int e, int l, int r, int val)
{
	if (lazy[node] != 0)
	{
		tree[node] += (e - s + 1) * lazy[node];

		if (s != e)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (s > r || e < l)
		return;
	if (s >= l && e <= r)
	{
		tree[node] += (e - s + 1) * val;
		if (s != e)
		{
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return;
	}

	update(2 * node, s, (s + e) / 2, l, r, val);
	update(2 * node + 1, 1 + (s + e) / 2, e, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int s, int e, int l, int r)
{
	if (lazy[node] != 0)
	{
		tree[node] += (e - s + 1) * lazy[node];

		if (s != e)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (s > r || e < l)
		return 0;
	if (s >= l && e <= r)
		return tree[node];

	return query(2 * node, s, (s + e) / 2, l, r) + query(2 * node + 1, 1 + (s + e) / 2, e, l, r);

}

int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, c;
		cin >> n >> c;
		for (int i = 0; i <= 5 * n; i++)
		{
			lazy[i] = tree[i] = 0;
		}

		while (c--)
		{
			int k;
			cin >> k;
			if (k == 0)
			{
				int l, r, v;
				cin >> l >> r >> v;
				update(1, 1, n, l, r, v);
			}
			else {
				int l, r;
				cin >> l >> r;
				cout << query(1, 1, n, l, r) << endl;
			}
		}
	}
	return 0;
}