#include <iostream>

using namespace std;

int n, m, t;
long long sum[210][210], f[210][210] = { 1 };
char a[1010], b[1010];

int main()
{
	scanf("%d%d%d%s%s", &n, &m, &t, a, b);
	for (int i = 1; i <= n; i++)
		for (int j = m; j; j--)
			for (int k = t; k; k--)
				f[j][k] = (f[j][k] + (sum[j][k] = a[i - 1] == b[j - 1] ? sum[j - 1][k] + f[j - 1][k - 1] : 0)) % 1000000007;
	printf("%lld\n", f[m][t]);

	return 0;
}