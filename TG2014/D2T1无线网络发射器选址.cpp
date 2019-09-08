#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int d, n;
ll a[170][170], cnt(0), ans(0), num(0);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> d >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y, k; cin >> x >> y >> k;
		a[x + 20][y + 20] = k;
	}
	for (int i = 20; i <= 148; i++)
		for (int j = 20; j <= 148; j++)
		{
			num = 0;
			for (int x = i - d; x <= i + d; x++)
				for (int y = j - d; y <= j + d; y++)
					num += a[x][y];
			if (num > ans)
				cnt = 1;
			else if (num == ans) cnt++;
			ans = max(ans, num);
		}
	cout << cnt << ' ' << ans << endl;

	return 0;
}