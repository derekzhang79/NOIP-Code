#include <iostream>

using namespace std;

int n, last = 0, ans = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a; cin >> a;
		if (a > last) ans += a - last;
		last = a;
	}
	cout << ans << endl;

	return 0;
}