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
        string s1, s2;
        cin >> s1 >> s2;
        vector<lli> ans;
        lli x = n - 1, y = 1, c = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s1[0] != s2[i])
            {
                ans.pb(i + 1);
            }
            else
            {
                ans.pb(1);
                ans.pb(i + 1);
            }
            if (c % 2)
            {
                s1[0] = '0' + '1' - s1[x];
                x -= 1;
            }
            else
            {
                s1[0] = s1[y];
                y += 1;
            }
            c += 1;
        }
        cout << ans.size() << " ";
        for1(i, 0, ans.size())
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}