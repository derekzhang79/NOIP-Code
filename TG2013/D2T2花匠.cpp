#include <iostream>

using namespace std;

int n, h[100010], ans(1);
bool c;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	if (h[2] >= h[1]) c = true;
	for (int i = 1; i <= n; i++)
	{
		if (!c && i == n) { ans++; break; }
		if (c)
		{
			if (h[i + 1] < h[i]) { ans++; c = false; }
		}
		else
		{
			if (h[i + 1] > h[i]) { ans++; c = true; }
		}
	}
	cout << ans << endl;

	return 0;
}