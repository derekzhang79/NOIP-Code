#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1000010;
int n, m;
int r[N], d[N], s[N], t[N];
LL b[N];

bool check(int k)
{
    for (int i = 1; i <= n; i++) b[i] = r[i];
    for (int i = 1; i <= k; i++)
    {
        b[s[i]] -= d[i];
        b[t[i] + 1] += d[i];
    }
    LL res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += b[i];
        if (res < 0) return true;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    for (int i = n; i; i--) r[i] -= r[i - 1];
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &d[i], &s[i], &t[i]);
    int l = 1, r = m;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (check(r))
    {
        puts("-1");
        printf("%d\n", r);
    }
    else puts("0");
    
    return 0;
}