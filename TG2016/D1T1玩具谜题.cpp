#include <iostream>
#include <string>
 
using namespace std;
 
const int N = 1e5 + 10;
int n, m, p = 0;
pair<int, string> a[N];
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= m; i++)
    {
        int op, s; cin >> op >> s;
        op ^= a[p].first;
        if (op == 0)
            p = (p - s + n) % n;
        else p = (p + s) % n;
    }
    cout << a[p].second << endl;
 
    return 0;
}