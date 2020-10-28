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
        string s;
        cin >> s;
        lli y = 1;
        stack<lli> z, o;
        vector<lli> ans(n + 1, 0);
        for1(i, 0, n)
        {
            if (s[i] == '1')
            {
                if (z.empty())
                {
                    ans[i] = y;
                    y += 1;
                }
                else
                {
                    lli x = z.top();
                    z.pop();
                    ans[i] = ans[x];
                }
                o.push(i);
            }
            else
            {
                if (o.empty())
                {
                    ans[i] = y;
                    y += 1;
                }
                else
                {
                    lli x = o.top();
                    o.pop();
                    ans[i] = ans[x];
                }
                z.push(i);
            }
        }
        cout << y - 1 << endl;
        for1(i, 0, n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}