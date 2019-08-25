#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 10007;
   
int qmi(int a, int k)
{
    a %= mod;
    int res = 1;
    while(k)
    {
        if(k &1) res = res *a % mod;
        a = a *a % mod;
        k >>= 1;
    }
    return res;
}
   
int main()
{
    int a, b, k, n, m;
   
    cin >> a >> b >> k >> n >> m;
   
    int res = qmi(a, n) *qmi(b, m) % mod;
    for(int i = 1, j = k; i <= n; i++, j--)
    {
        res = res *j % mod;
        res = res *qmi(i, mod - 2) % mod;
    }
   
    cout << res << endl;
   
    return 0;
}