#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, i;
  cin >> n;
  int a[n];
  long int max_so_far = -1000000000000000000, max1 = 0;
  for (i = 0; i < n; i++)
  {
    cin >> a[i];
    max1 += a[i];
    if (max1 > max_so_far)
      max_so_far = max1;
    if (max1 < 0)
      max1 = 0;
  }
  cout << max_so_far << endl;
  return 0;
}