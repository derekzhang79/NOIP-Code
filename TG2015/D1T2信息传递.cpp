#include <iostream>
#include <algorithm>

using namespace std;

int n, a[200010], f[200010], t = 0, ans = 10000000;

void dfs(int x)
{
	if (f[x] == 0)
	{
		f[x] = ++t;
		dfs(a[x]);
	}
	else if (f[x] > 0) ans = min(ans, t + 1 - f[x]);
	f[x] = -1;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		if (f[i] == 0)
		{
			t = 0;
			dfs(i);
		}
	cout << ans << endl;

	return 0;
}