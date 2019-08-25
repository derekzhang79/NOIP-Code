#include <cstdio>
 
using namespace std;
 
int n;
 
struct carpet
{
    int a, b, g, k;
} a[10010];
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &a[i].a, &a[i].b, &a[i].g, &a[i].k);
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = n; i; i--)
        if (a[i].a <= x && a[i].a + a[i].g > x && a[i].b <= y && a[i].b + a[i].k > y)
        {
            printf("%d\n", i);
            return 0;
        }
    puts("-1");
 
    return 0;
}