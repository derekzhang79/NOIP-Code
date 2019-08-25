#include <iostream>
#include <ctype.h>
 
using namespace std;
 
string k, s;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> s;
    for (int i = 0; i < k.size(); i++)
        k[i] = tolower(k[i]);
    for (int i = 0; i < s.size(); i++)
    {
        int j = k[i % k.size()];
        int c = tolower(s[i]);
        int t = ((c - 'a') - (j - 'a') + 26) % 26 + 'a';
        if (islower(s[i])) putchar(tolower(t));
        else putchar(toupper(t));
    }
    puts("");
 
    return 0;
}