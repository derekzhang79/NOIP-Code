#include <iostream>
#define ll long long

using namespace std;

ll T, n, h, r, x[1010], y[1010], z[1010], f[1010];

ll find(ll x) { return x == f[x] ? x : (f[x] = find(f[x])); }

void join(ll x, ll y) { f[find(x)] = find(y); }

inline ll sqr(ll a) { return a * a; }

inline ll dist(ll a, ll b)
{
	return sqr(x[a] - x[b]) + sqr(y[a] - y[b]) + sqr(z[a] - z[b]);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n >> h >> r;
		for (ll i = 1; i <= n; i++)
			cin >> x[i] >> y[i] >> z[i];
		for (ll i = 0; i <= n + 1; i++)
			f[i] = i;
		for (ll i = 1; i <= n; i++)
			if (z[i] <= r) join(0, i);
		for (ll i = 1; i <= n; i++)
			if (z[i] + r >= h) join(i, n + 1);
		ll t = 4 * r * r;
		for (ll i = 1; i <= n; i++)
			for (ll j = i + 1; j <= n; j++)
				if (dist(i, j) <= t)
					join(i, j);
		if (find(0) == find(n + 1)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}