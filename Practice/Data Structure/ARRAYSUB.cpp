
// Question reference: https://www.spoj.com/problems/ARRAYSUB/
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
#define int long long int
int arr[MAX];
int tree[4 * MAX + 1];

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
	if (s > r || e < l)
		return INT_MIN;
	if (s >= l && e <= r)
	{
		return tree[node];
	}
	return max(query(2 * node, s, (s + e) / 2, l, r), query(2 * node + 1, 1 + (e + s) / 2, e, l, r));
}

int32_t main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(1, 0, n - 1);
	int k; cin >> k;
	k--;
	for (int i = 0; i < n; i++)
	{
		if ((k + i) < n)
			cout << query(1, 0, n - 1, i, k + i) << " ";
		else
			break;
	}


	return 0;
}