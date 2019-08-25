#include <iostream>
#define ll long long
 
using namespace std;
 
ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    int d = exgcd(b, a % b, x, y);
    int z = x; x = y; y = z - y * (a / b);
    return d;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
 
    return 0;
}