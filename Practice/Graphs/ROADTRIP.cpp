
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------

Question link: https://www.codechef.com/INOIPRAC/problems/ROADTRIP/
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000001];
bool visited[10000001];
int museums[10000001];
int total;

void dfs(int u) {

	visited[u] = true;
	total += museums[u];
	for (int i : graph[u]) {
		if (visited[i])
			continue;
		dfs(i);
	}
}

int32_t main()
{

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		for (int i = 1; i <= 1000000; i++) {
			graph[i].clear();
			visited[i] = false;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<int> ans;
		for (int i = 1; i <= n; i++)
			cin >> museums[i];

		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				total = 0;
				dfs(i);
				ans.push_back(total);
			}
		}

		if (ans.size() < k) {
			cout << -1 << endl;
		}
		else {
			sort(ans.begin(), ans.end());
			int min1 = 0, max1 = ans.size() - 1;
			int totalMuseums = 0;
			while (k != 0) {
				totalMuseums += ans[max1];
				max1--;
				k--;
				if (k == 0)
					break;
				totalMuseums += ans[min1];
				min1++;
				k--;

			}
			cout << totalMuseums << endl;
		}



	}


	return 0;
}