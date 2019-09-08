#include <iostream>

using namespace std;

const int N = 50010;
int L, n, m, a[N];

bool check(int x)
{
	int last(0), move(0);
	for (int i = 2; i <= n; i++)
	{
		if (a[i] - last < x)
			move++;
		else last = a[i];
	}
	return move <= m;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> L >> n >> m;
	a[1] = 0;
	for (int i = 2; i <= n + 1; i++)
		cin >> a[i];
	n += 2;
	a[n] = L;
	int l = 0, r = 1000000000, res;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid + 1;
			res = mid;
		}
		else r = mid - 1;
	}
	cout << res << endl;

	return 0;
}