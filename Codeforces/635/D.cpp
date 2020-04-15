#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
const ll mod = 1e9 + 7;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> data_struct;

void solve() {
	ll i, r, b, g;
	cin >> r >> b >> g;
	vector<ll> rd(r), bl(b), gr(g);
	for (i = 0; i < r; i++)
		cin >> rd[i];
	for (i = 0; i < b; i++)
		cin >> bl[i];
	for (i = 0; i < g; i++)
		cin >> gr[i];
	sort(rd.begin(), rd.end());
	sort(bl.begin(), bl.end());
	sort(gr.begin(), gr.end());
	ll mn = 1999999999999999999, p, q, a;
	for (i = 0; i < r; i++)
	{
		a = 0;
		p = lower_bound(bl.begin(), bl.end(), rd[i]) - bl.begin();
		q = lower_bound(gr.begin(), gr.end(), rd[i]) - gr.begin();
		if (p == b)
			p--;
		if (q == g)
			q--;
		if (p != 0 && abs(rd[i] - bl[p]) > abs(rd[i] - bl[p - 1]))
			p--;
		if (q != 0 && abs(rd[i] - gr[q]) > abs(rd[i] - gr[q - 1]))
			q--;
		a += (rd[i] - bl[p]) * (rd[i] - bl[p]);
		a += (rd[i] - gr[q]) * (rd[i] - gr[q]);
		a += (bl[p] - gr[q]) * (bl[p] - gr[q]);
		mn = min(mn, a);
	}
	for (i = 0; i < b; i++)
	{
		a = 0;
		p = lower_bound(rd.begin(), rd.end(), bl[i]) - rd.begin();
		q = lower_bound(gr.begin(), gr.end(), bl[i]) - gr.begin();
		if (p == r)
			p--;
		if (q == g)
			q--;
		if (p != 0 && abs(bl[i] - rd[p]) > abs(bl[i] - rd[p - 1]))
			p--;
		if (q != 0 && abs(bl[i] - gr[q]) > abs(bl[i] - gr[q - 1]))
			q--;
		a += (rd[p] - bl[i]) * (rd[p] - bl[i]);
		a += (rd[p] - gr[q]) * (rd[p] - gr[q]);
		a += (bl[i] - gr[q]) * (bl[i] - gr[q]);
		mn = min(mn, a);
	}
	for (i = 0; i < g; i++)
	{
		a = 0;
		p = lower_bound(bl.begin(), bl.end(), gr[i]) - bl.begin();
		q = lower_bound(rd.begin(), rd.end(), gr[i]) - rd.begin();
		if (p == b)
			p--;
		if (q == r)
			q--;
		if (p != 0 && abs(gr[i] - bl[p]) > abs(gr[i] - bl[p - 1]))
			p--;
		if (q != 0 && abs(gr[i] - rd[q]) > abs(gr[i] - rd[q - 1]))
			q--;
		a += (rd[q] - bl[p]) * (rd[q] - bl[p]);
		a += (rd[q] - gr[i]) * (rd[q] - gr[i]);
		a += (bl[p] - gr[i]) * (bl[p] - gr[i]);
		mn = min(mn, a);
	}
	cout << mn << "\n";
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}