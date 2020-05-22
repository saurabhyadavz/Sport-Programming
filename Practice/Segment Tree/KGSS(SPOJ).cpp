// Reference: https://www.spoj.com/problems/KGSS/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MAX 100001
struct node
{
	int maxx;
	int maxxx;
} tree[4 * MAX];

int arr[MAX];

void build(int s, int l, int r)
{
	if (l == r)
	{
		tree[s].maxx = INT_MIN;
		tree[s].maxxx = arr[l];
		return ;
	}

	build(2 * s, l, (l + r) / 2);
	build(2 * s + 1, 1 + (l + r) / 2, r);
	if (tree[2 * s].maxxx >= tree[2 * s + 1].maxxx)
	{
		tree[s].maxxx = tree[2 * s].maxxx;

		tree[s].maxx = max(tree[2 * s].maxx, max(tree[2 * s + 1].maxxx, tree[2 * s + 1].maxx));
	}
	else {
		tree[s].maxxx = tree[2 * s + 1].maxxx;
		tree[s].maxx = max(tree[2 * s + 1].maxx, max(tree[2 * s ].maxxx, tree[2 * s ].maxx));
	}
}

void update(int ss, int s, int e, int index, int value)
{
	if (s == e)
	{
		tree[ss].maxx = INT_MIN;
		tree[ss].maxxx = value;
		return ;
	}

	int mid = (s + e) / 2;

	if (index <= mid)
		update(2 * ss, s, mid, index, value);
	else
		update(2 * ss + 1, mid + 1, e, index, value);


	if (tree[2 * ss].maxxx >= tree[2 * ss + 1].maxxx)
	{
		tree[ss].maxxx = tree[2 * ss].maxxx;

		tree[ss].maxx = max(tree[2 * ss].maxx, max(tree[2 * ss + 1].maxxx, tree[2 * ss + 1].maxx));
	}
	else {
		tree[ss].maxxx = tree[2 * ss + 1].maxxx;
		tree[ss].maxx = max(tree[2 * ss + 1].maxx, max(tree[2 * ss ].maxxx, tree[2 * ss ].maxx));
	}

}

pair<int, int> query(int ss, int s, int e, int l, int r)
{

	if (s > r || e < l)
	{
		return { INT_MIN, INT_MIN};
	}
	if (s >= l && e <= r )
	{
		return {tree[ss].maxx, tree[ss].maxxx};
	}

	pair<int, int> p1 = query(2 * ss, s, (s + e) / 2, l, r);
	pair<int, int> p2 = query(2 * ss + 1, 1 + (s + e) / 2, e, l, r);

	if (p1.second >= p2.second)
	{
		return {max(p1.first, max(p2.first, p2.second)), p1.second};
	}
	else
		return {max(p1.first, max(p2.first, p1.second)), p2.second};


}

int32_t main()
{

	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	build(1, 0, n - 1);

	int q;
	cin >> q;
	while (q--)
	{
		char c;
		cin >> c;
		if (c == 'Q')
		{
			int l, r;
			cin >> l >> r;
			pair<int, int> p = query(1, 0, n - 1, l - 1, r - 1);
			cout << p.first + p.second << endl;
		}
		else {
			int index, val;
			cin >> index >> val;
			update(1, 0, n - 1, index - 1, val);
		}

	}
	return 0;
}