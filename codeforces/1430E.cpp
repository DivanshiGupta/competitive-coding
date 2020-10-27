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
vector<int> seg,lazy;
void merge(const int &a,const int &b,int &c)
{
    c=a+b;
}
void build(int pos,int ss,int se,vector<int>&a)
{
    if(pos==0)
    {
        seg.resize(4*(se+1)+1);
        lazy.resize(4*(se+1)+1);
    }
    if(ss==se)
    {
        seg[pos]=a[ss];
        return ;
    }
    int mid=(ss+se)/2;
    build(2*pos+1,ss,mid,a);
    build(2*pos+2,mid+1,se,a);
    merge(seg[2*pos+1],seg[2*pos+2],seg[pos]);
}
void update(int pos,int ss,int se,int l,int f,int val)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=(se-ss+1)*lazy[pos];
        if(ss!=se){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
            lazy[pos]=0;
    }
    if(ss > f || se < l || l > f)
       return ;
    if(ss >=l && se <=f)
    {
        seg[pos]+=(se-ss+1)*val;
        if(ss!=se)
        {
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }
    return ;
    }
    int mid=(ss+se)/2;
    update(2*pos+1,ss,mid,l,f,val);
    update(2*pos+2,mid+1,se,l,f,val);
    merge(seg[2*pos+1],seg[2*pos+2],seg[pos]);
    return ;
}
int query(int pos,int ss,int se,int l,int f)
{
   if(lazy[pos]!=0)
    {
        seg[pos]+=(se-ss+1)*lazy[pos];
        if(ss!=se){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
            lazy[pos]=0;
    }
    //normal
    if(ss > f || se < l)
    return 0;
    if(ss >=l && se <=f)
     return seg[pos];
     int mid=(ss+se)/2;
     int ans;
     merge(query(2*pos+1,ss,mid,l,f),query(2*pos+2,mid+1,se,l,f),ans);
     return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;cin>>n;
    string s;cin>>s;
    vector<queue<int> > que(26);
    for(int i=n-1;i>=0;i--)
    {
    	que[s[i]-'a'].push(i);
    }
    v pos(n);
    for(int i=0;i<n;i++)
    {
    	pos[i]=i;
    }
    build(0,0,n-1,pos);
    string t=s;
    reverse(all(t));
    vb vst(n,true);
    int p=n-1;
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
    	if(!vst[p])
    	{
    		p--;
    		i++;
    		continue;
    	}
    	if(s[p]==t[i])
    	{
    		p--;
    		continue;
    	}
    	while(que[t[i]-'a'].front()>p)
    		que[t[i]-'a'].pop();
    	int u=que[t[i]-'a'].front();
    	que[t[i]-'a'].pop();

    	int pu=query(0,0,n-1,u,u);
    	ans+=i-pu;
    	update(0,0,n-1,u+1,p,-1);
    	vst[u]=false;
    }
    cout<<ans<<endl;
    return 0;
}