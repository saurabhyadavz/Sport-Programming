#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MAX 100001
int tree[5 * MAX + 1];
int arr[MAX + 10];
#define endl "\n"
void build(int node, int s, int e)
{
	if (s == e)
	{
		tree[node] = arr[s];
		return ;
	}

	build(2 * node, s, (s + e) / 2);
	build(2 * node + 1, 1 + (s + e) / 2, e);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int s, int e, int l, int r)
{
	if (l <= s && r >= e)
		return tree[node];
	if (e < l || s > r )
		return INT_MIN;
	int p1 = query(2 * node, s, (s + e) / 2, l, r);
	int p2 = query(2 * node + 1, 1 + (s + e) / 2, e, l, r);
	return max(p1, p2);
}

void update(int node, int s, int e, int index, int value)
{
	if (s == e)
	{
		arr[index] = value;
		tree[node] = value;
		return ;
	}
	else
	{
		int mid = (s + e) / 2;
		if (index >= s && index <= mid)
			update(2 * node, s, mid, index, value);
		else
			update(2 * node + 1, mid + 1, e, index, value);
		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}
int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{

		int n;
		cin >> n;
		for (int i = 0; i <= n + 1; i++)
		{
			arr[i] = 0;
		}

		build(1, 0, n + 1);
		int count = 0;
		cout << "Case " << i << ":" << endl;
		int loop = n;
		while (loop--)
		{
			char c;
			cin >> c;
			if (c == 'A')
			{
				int val;
				cin >> val;
				update(1, 0, n + 1, count, val);
				count++;
				// cout << count << endl;
			}
			else if (c == 'Q')
			{
				if (count <= 0)
					cout << "Empty" << endl;
				else
					cout << query(1, 0, n + 1, 0, count - 1) << endl;
			}
			else
			{
				if (count > 0)
				{
					count--;
					update(1, 0, n + 1, count, 0);
				}
				// cout << count << endl;


			}

		}


	}
	return 0;
}