#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010, M = 10007;
int n, he[N], ver[N * 2], ne[N *2], tot(0), w[N];

void add(int u, int v)
{
	ver[++tot] = v; ne[tot] = he[u]; he[u] = tot;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		add(u, v); add(v, u);
	}
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	int ans = 0, maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = he[i];
		int t = w[ver[j]], sum = w[ver[j]];
		for (j = ne[j]; j; j = ne[j])
		{
			int v = ver[j];
			ans = (ans + sum * w[v]) % M;
			maxn = max(maxn, t * w[v]);
			sum = (sum + w[v]) % M;
			t = max(t, w[v]);
		}
	}
	cout << maxn << ' ' << ans * 2 % M << endl;

	return 0;
}