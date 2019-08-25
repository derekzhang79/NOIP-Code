#include <iostream>
 
using namespace std;
 
int n, l, r, a[45][45];
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    l = 1; r = (n + 1) / 2;
    a[l][r] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        if (l == 1 && r == n)
            l++;
        else if (l == 1)
        {
            l = n; r++;
        }
        else if (r == n)
        {
            r = 1; l--;
        }
        else if (a[l - 1][r + 1]) l++;
        else
        {
            l--; r++;
        }
        a[l][r] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << a[i][j] << ' ';
        cout << a[i][n] << '\n';
    }
 
    return 0;
}