#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;

const ll N = 7500000;
ll n, m, q, u, v, t;
double x;
ll a[N], ans[N], s(0), y(0), tot(0);
queue<ll> q1, q2, q3;

ll getmax()
{
	ll x1 = -(1 << 30), x2 = x1, x3 = x1;
	if (q1.size()) x1 = q1.front();
	if (q2.size()) x2 = q2.front();
	if (q3.size()) x3 = q3.front();
	if (x1 >= x2 && x1 >= x3)
	{
		q1.pop();
		return x1;
	}
	if (x2 >= x1 && x2 >= x3)
	{
		q2.pop();
		return x2;
	}
	q3.pop();
	return x3;
}

void put(ll x1, ll x2)
{
	if (x1 < x2) swap(x1, x2);
	q2.push(x1); q3.push(x2);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q >> u >> v >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<ll>());
	for (int i = 1; i <= n; i++) q1.push(a[i]);
	for (int i = 1; i <= m; i++)
	{
		ans[i] = getmax() + y;
		int j = ans[i] * u / v, k = ans[i] - j;
		y += q;
		put(j - y, k - y);
	}
	while (q1.size() || q2.size() || q3.size()) a[++tot] = getmax() + y;
	for (int i = t; i <= m; i += t) cout << ans[i] << ' ';
	cout << '\n';
	for (int i = t; i <= tot; i += t) cout << a[i] << ' ';
	cout << '\n';

	return 0;
}
