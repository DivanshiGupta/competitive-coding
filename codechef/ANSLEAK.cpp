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
    lli n, a, m, k;
    cin >> n >> m >> k;
    map<lli, lli> mp;
    lli minn = 0;
    vector<vector<lli>> ans(n + 2);
    vector<lli> ans1, ans2;

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < k; j++) {
            cin >> a;
            ans[i].pb(a);
        }
    }

    for (lli i = 0; i < n; i++) {
        vector<lli> cnt(m + 2, 0), v;
        lli mx = -1, ind;
        for (lli j = 0; j < k; j++) {
            a = ans[i][j];
            v.pb(a);
            if (mp[j] == minn) {
                cnt[a]++;

                if (cnt[a] > mx) {
                    mx = cnt[a];
                    ind = a;
                }
            }
        }

        for (lli j = 0; j < k; j++) {
            if (v[j] == ind) {
                mp[j]++;
            }
        }

        ans1.pb(ind);
        // cout << ind << " ";
        lli val = 6000;
        for (lli j = 0; j < k; j++) {
            val = min(val, mp[j]);
        }
        minn = val;
    }

    lli minn2 = 0;
    map<lli, lli> mp2;
    for (lli i = n - 1; i >= 0; i--) {
        vector<lli> cnt(m + 2, 0), v;
        lli mx = -1, ind;
        for (lli j = 0; j < k; j++) {
            a = ans[i][j];
            v.pb(a);
            if (mp2[j] == minn2) {
                cnt[a]++;

                if (cnt[a] > mx) {
                    mx = cnt[a];
                    ind = a;
                }
            }
        }

        for (lli j = 0; j < k; j++) {
            if (v[j] == ind) {
                mp2[j]++;
            }
        }

        ans2.pb(ind);
        // cout << ind << " ";
        lli val = 6000;
        for (lli j = 0; j < k; j++) {
            val = min(val, mp2[j]);
        }
        minn2 = val;
    }

    reverse(all(ans2));
    if (minn > minn2) {
        for (lli i = 0; i < ans1.size(); i++) {
            cout << ans1[i] << " ";
        }
    } else {
        for (lli i = 0; i < ans2.size(); i++) {
            cout << ans2[i] << " ";
        }
    }

    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}