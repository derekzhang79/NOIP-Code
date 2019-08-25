#include <iostream>
 
using namespace std;
 
typedef long long ll;
ll n, m, k, x;
 
ll power(ll a, ll b, ll p)
{
    ll res = 1;
    for (; b; b /= 2)
    {
        if (b % 2) res = (res * a) % p;
        a = (a * a) % p;
    }
    return res;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> x;
    cout << (x + power(10, k, n) * m) % n << endl;
 
    return 0;
}