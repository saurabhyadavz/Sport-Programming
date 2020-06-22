/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
#include <bits/stdc++.h>
using namespace std;
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
struct node
{
  int row;
  int col;
  vector<char> ans;
};

int main()
{
  REDBULL
  int n, m;
  cin >> n >> m;
  char a[n][m];
  int r1 = 0, c1 = 0;
  int visited[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];

      if (a[i][j] == '#')
        visited[i][j] = 1;
      else
        visited[i][j] = 0;
      if (a[i][j] == 'A')
        r1 = i, c1 = j;
    }
  }

  queue<node> q;
  vector<char> check;
  check.push_back('A');
  q.push({r1, c1, check});
  visited[r1][c1] = 1;
  while (q.size() != 0)
  {
    node p = q.front();
    q.pop();

    if (a[p.row][p.col] == 'B')
    {
      cout << "YES" << endl;
      cout << p.ans.size() - 1 << endl;
      for (int i = 1; i < p.ans.size(); i++)
        cout << p.ans[i];
      cout << endl;
      // cout << p.ans << endl;
      return 0;
    }

    if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == 0)
    {
      vector<char> check1;
      check1 = p.ans;
      check1.push_back('U');
      q.push({p.row - 1, p.col, check1});
      visited[p.row - 1][p.col] = 1;
    }
    if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == 0)
    {
      vector<char> check1;
      check1 = p.ans;
      check1.push_back('L');
      q.push({p.row, p.col - 1, check1});
      visited[p.row][p.col - 1] = 1;
    }
    if (p.row + 1 < n  && visited[p.row + 1][p.col] == 0)
    {
      vector<char> check1;
      check1 = p.ans;
      check1.push_back('D');
      q.push({p.row + 1, p.col, check1});
      visited[p.row + 1][p.col] = 1;
    }
    if (p.col + 1 < m && visited[p.row][p.col + 1] == 0)
    {
      vector<char> check1;
      check1 = p.ans;
      check1.push_back('R');
      q.push({p.row , p.col + 1, check1});
      visited[p.row][p.col + 1] = 1;
    }
  }

  cout << "NO" << endl;


  return 0;
}