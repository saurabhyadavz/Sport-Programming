/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
#include <bits/stdc++.h>
using namespace std;


int visit[10001][10001];
char a[10001][10001];
int n, m;
void dfs(int x, int y)
{
  visit[x][y] = 1;
  if (x - 1 >= 0 && a[x - 1][y] == '.' && visit[x - 1][y] == 0)
  {
    dfs(x - 1, y);
  }
  if (y - 1 >= 0 && a[x][y - 1] == '.' && visit[x][y - 1] == 0)
  {
    dfs(x, y - 1);
  }
  if (x + 1 < n && a[x + 1][y] == '.' && visit[x + 1][y] == 0)
  {
    dfs(x + 1, y);
  }
  if (y + 1 < m && a[x][y + 1] == '.' && visit[x][y + 1] == 0)
  {
    dfs(x, y + 1);
  }
  else
    return;
}
int main()
{

  scanf("%d %d", &n, &m);
  cin >> n >> m;
  int i, j, count = 0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      int ch = getchar();
      if (ch == '\n' || ch == EOF)
        break;
      a[i][j] = (char)ch;
      visit[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (a[i][j] == '.' && visit[i][j] == 0)
      {
        dfs(i, j);
        count++;
      }
    }
  }

  printf("%d", count);

  return 0;
}