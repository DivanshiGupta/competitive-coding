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
    lli n, a, x, y, b, c, p;
    cin >> x >> y >> a >> b >> c;
    vector<pair<lli, lli>> v;

    for (lli i = 0; i < a; i++) {
        cin >> p;
        v.pb({p, 1});
    }
    for (lli i = 0; i < b; i++) {
        cin >> p;
        v.pb({p, 2});
    }
    for (lli i = 0; i < c; i++) {
        cin >> p;
        v.pb({p, 0});
    }

    sort(v.rbegin(), v.rend());
    lli ans = 0, red = 0, white = 0, cnt = 0;

    for (lli i = 0; i < v.size(); i++) {
        if (cnt == x + y) {
            break;
        }
        if (v[i].second == 1 && red < x) {
            ans += v[i].first;
            red++;
            cnt++;
        }
        if (v[i].second == 2 && white < y) {
            ans += v[i].first;
            white++;
            cnt++;
        }
        if (v[i].second == 0) {
            ans += v[i].first;
            cnt++;
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