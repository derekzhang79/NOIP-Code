#include <iostream>
 
using namespace std;
 
 
int n, na, nb, a[210], b[210], tota = 0, totb = 0;
 
void cmp(int a, int b)
{
    if (a == b) return;
    if (a == 0)
    {
        if (b == 2 || b == 3) tota++;
        else totb++;
    }
    else if (a == 1)
    {
        if (b == 0 || b == 3) tota++;
        else totb++;
    }
    else if (a == 2)
    {
        if (b == 1 || b == 4) tota++;
        else totb++;
    }
    else if (a == 3)
    {
        if (b == 2 || b == 4) tota++;
        else totb++;
    }
    else
    {
        if (b == 0 || b == 1) tota++;
        else totb++;
    }
     
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++)
        cin >> a[i];
    for (int i = 0; i < nb; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        int A = a[i % na], B = b[i % nb];
        cmp(A, B);
    }
    cout << tota << ' ' << totb << endl;
 
    return 0;
}