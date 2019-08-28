#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n;
struct node
{
    int x, y;
} a[N], b[N];
int c[N], d[N];
long long ans;

bool cmp(node a, node b) { return a.x < b.x; }

void merge_sort(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
        if (j > r || (i <= mid && c[i] <= c[j])) d[k] = c[i++];
        else d[k] = c[j++], ans = (ans + mid - i + 1) % 99999997;
    for (int k = l; k <= r; k++)
        c[k] = d[k];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
        a[i].y = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].x;
        b[i].y = i;
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        c[a[i].y] = b[i].y;
    merge_sort(1, n);
    cout << ans << endl;

    return 0;
}