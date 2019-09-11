#include <iostream>
#include <cstring>

using namespace std;

int t, k, n, m, c[2010][2010], s[2010][2010];

int main()
{
	scanf("%d%d", &t, &k);
	memset(c, 0, sizeof c);
	memset(s, 0, sizeof s);
	c[1][1] = 1;
	for (int i = 0; i <= 2000; i++) c[i][0] = 1;
	for (int i = 2; i <= 2000; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
	for (int i = 2; i <= 2000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			if (c[i][j] == 0) s[i][j]++;
		}
		s[i][i + 1] = s[i][i];
	}
	while (t--)
	{
		scanf("%d%d", &n, &m);
		if (m > n) m = n;
		printf("%d\n", s[n][m]);
	}

	return 0;
}
