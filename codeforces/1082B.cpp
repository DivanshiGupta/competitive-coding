#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, a;
    cin >> n;
    string st;
    cin >> st;
    vector<lli> pref(n + 2, 0), suff(n + 2, 0);

    lli ans = 0, tot = 0;

    if (st[0] == 'G') {
        tot++;
        pref[0] = 1;
    }
    if (st[n - 1] == 'G') {
        suff[n - 1] = 1;
    }

    for (lli i = 1; i < n; i++) {
        if (st[i] == 'G') {
            tot++;
            pref[i] = pref[i - 1] + 1;
        }
    }

    for (lli i = n - 2; i >= 0; i--) {
        if (st[i] == 'G') {
            suff[i] = suff[i + 1] + 1;
        }
    }

    for (lli i = 0; i < n; i++) {
        ans = max({ans, pref[i], suff[i]});
        if (st[i] == 'S') {
            lli val1 = 0, val2 = 0;
            if (i != 0) {
                val1 = pref[i - 1];
            }
            if (i != n - 1) {
                val2 = suff[i + 1];
            }
            if (val1 + val2 != tot) {
                ans = max(ans, val1 + val2 + 1);
            } else {
                if (val1 != tot) {
                    ans = max(ans, val1 + 1);
                }
                if (val2 != tot) {
                    ans = max(ans, val2 + 1);
                }
                ans = max(ans, val1 + val2);
            }
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}