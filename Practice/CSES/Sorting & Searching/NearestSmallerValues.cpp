#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		while (s.size() != 0 && a[s.top()] >= a[i])
			s.pop();
		if (s.size() == 0)
			printf("0 ");
		else
			cout << s.top() + 1 << " ";
		s.push(i);
	}
	return 0;
}