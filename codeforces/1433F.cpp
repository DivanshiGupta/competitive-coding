#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>   
using namespace std;
using namespace __gnu_pbds;
typedef long long ll; 
#define int long long
typedef unsigned long long lu;
typedef vector<ll> v;
typedef vector<vector<ll> > vv;
typedef vector<string>  vs;
typedef vector<pair<ll,ll>> vpr;
typedef vector<bool>vb;
typedef vector<double>vd;
typedef long double ld;
#define f(i,n) for(ll i = 0; i < n; i++)
#define ff(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define amax(x,y) if(y>x) x=y;
#define amin(x,y) if(y<x)x=y;
#define bg(x) x.begin()
#define sz(x) (ll)x.size()
#define in(x,n) for(ll i=0;i<n;i++)cin>>x[i]
#define out(x,n) for(ll i=0;i<n;i++)cout<<x[i]<<" " 
#define mxt(a) *(max_element(a.begin(),a.end()))
#define mnt(a) *(min_element(a.begin(),a.end())
#define tc ll t;cin>>t;while(t--)
typedef pair<ll,ll> pi;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define yesno(f) if(f) yes else no
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
const ld PI = 2 * acos(0.0);
ll cel(ll x1,ll y1){if((x1%y1)==0)return x1/y1;else return x1/y1+1;}
ll power(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    ll d=power(a,b/2,m);
    d=(d*d)%m;
    if(b&1)
        d=(d*a)%m;
    return d;
}
const ll mod=1e9+7;
int MOD(int a)
{
    if(a<0)
        a+=mod;
    if(a>=mod)
        a%=mod;
    return a;
}
// set_name.find_by_order(k) It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time
// set_name.order_of_key(k) It returns to the number of items that are strictly smaller than our item k in O(logn) time.
/*string operations :
str.substr (x,y) : returns a substring str[x],str[x+1],...str[x+y-1]
str.substr (x) : returns a substring str[x],... end of string
str.find(qtr) : returns the first occurenece of qtr in str */
v RowDP(v a,int k)
{
	int n=a.size();
	int d=n/2;
	vector<vv> dp(n+1,vv(d+1,v(k,-1)));
	for(int i=0;i<=d;i++)
	{
		dp[n][i][0]=0;
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=d;j++)
		{
			for(int k1=0;k1<k;k1++)
			{
				dp[i][j][k1]=dp[i+1][j][k1];
				int k11=(k1-(a[i]%k)+k)%k;
				if(j!=0 && dp[i+1][j-1][k11]!=-1)
					dp[i][j][k1]=max(dp[i][j][k1],dp[i+1][j-1][k11]+a[i]);
			}
		}
	}
	v ans(k);
	for(int i=0;i<k;i++)
	{
		ans[i]=dp[0][d][i];
	}
	return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m,k;cin>>n>>m>>k;
    vv mat(n,v(m));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>mat[i][j];

    	}
    }
    vv row(n);
    for(int i=0;i<n;i++)
    {
    	row[i]=RowDP(mat[i],k);
    	// for(auto it:row[i])
    	// 	cout<<it<<" ";
    	// cout<<endl;
    }

    vv dp(n+1,v(k,-1));
    dp[n][0]=0;
    for(int i=n-1;i>=0;i--)
    {
    	for(int j=0;j<k;j++)
    	{
    		dp[i][j]=dp[i+1][j];
    		for(int j1=0;j1<k;j1++)
    		{
    			int j11=(j-j1+k)%k;
    			if(dp[i+1][j11]!=-1 && row[i][j1]!=-1)
    				dp[i][j]=max(dp[i][j],dp[i+1][j11]+row[i][j1]);
    		}
    	}
    }
    cout<<max(0ll,dp[0][0])<<endl;
    return 0;
}