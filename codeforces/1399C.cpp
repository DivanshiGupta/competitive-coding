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
        vector<lli> v(n + 1, 0);
        for1(i, 0, n)
        {
            lli k;
            cin >> k;
            v[k] += 1;
        }
        lli a = 2 * n;
        lli m = 0;
        for1(i, 2, a + 1)
        {
            lli x = 0;
            for1(j, 1, n + 1)
            {
                if (i - j > 0 && i - j <= n)
                {
                    lli k = i - j;
                    lli f = min(v[j], v[k]);
                    x += f;
                }
            }
            x /= 2;
            if (x > m)
            {
                m = x;
                // ans = i;
            }
        }
        cout << m << endl;
    }
}