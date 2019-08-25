#include <bits/stdc++.h>
 
using namespace std;
 
int n, k, p, now, x, y, ans = 0;
int last[200010], sum[200010], cnt[200010];
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (y <= p) now = i;
        if (last[x] <= now) sum[x] = cnt[x];
        last[x] = i; cnt[x]++;
        ans += sum[x];
    }
    cout << ans << endl; 
     
    return 0;
}