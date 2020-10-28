#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define rt return 0
#define endln "\n"
#define all(v) v.begin(), v.end()
#define for1(i, a, b) for (long long int i = a; i < b; i++)
#define for2(i, a, b) for (long long int i = a; i > b; i--)
//  cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;typedef long long int i;
typedef long long int lli;
typedef pair<lli, lli> pll;
int rec(string &s, lli f, lli r, lli x, char c)
{
    // cout << c << endl;
    if (x == 1)
    {
        if (s[f] == c && s[r] == c + 1)
        {
            return 0;
        }
        else if (s[f] == c + 1 && s[r] == c)
        {
            return 0;
        }
        else if (s[f] == c || s[f] == c + 1)
        {
            return 1;
            // break;
        }
        else if (s[r] == c || s[r] == c + 1)
        {
            return 1;
            // break;
        }
        else
        {
            return 2;
            // break;
        }
    }
    lli c1 = 0, c2 = 0;
    for1(i, f, f + x)
    {
        if (s[i] == c)
        {
            c1 += 1;
        }
    }
    for1(i, f + x, r + 1)
    {
        if (s[i] == c)
        {
            c2 += 1;
        }
    }
    lli y = x / 2;
    char f1 = c + 1;
    lli x1 = (x - c1) + rec(s, f + x, r, y, f1);

    lli x2 = (x - c2) + rec(s, f, f + x - 1, y, f1);
    lli a = min(x1, x2);
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin >> t;
    vector<lli> v;
    while (t--)
    {
        lli n;
        cin >> n;
        string s1;
        cin >> s1;
        string s;
        s.pb(0);
        for1(i, 0, n)
        {
            s.pb(s1[i]);
        }
        char c = 'a';
        if (n == 1)
        {
            if (s[1] == c)
            {
                cout << "0" << endl;
            }
            else
            {
                cout << "1" << endl;
            }
            continue;
        }

        lli ans = rec(s, 1, n, n / 2, c);
        cout << ans << endl;
    }
}
