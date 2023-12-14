/**
 * File              : Su tuyet vong.cpp
 * Author            : hungeazy
 * Date              : 10.11.2023
 * Last Modified Date: 10.11.2023
 * Last Modified By  : hungeazy
 */
#include <bits/stdc++.h>
#pragma GCC optimize("O3")  
#pragma GCC optimize("unroll-loops")  
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")  
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ull unsigned long long
#define sz(x) x.size()
#define sqr(x) (1LL * (x) * (x))
#define all(x) x.begin(), x.end()
#define fill(f,x) memset(f,x,sizeof(f))
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
#define ii pair<int,int>
#define iii pair<int,ii>
#define vi vector<int>
#define vii vector<ii>
#define mii map<int,int>
#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define __lcm(a,b) (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i)
#define BIT(x,i) ((x) & MASK(i))
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~MASK(i))
#define oo 1e18
#define name ""
#define endl '\n'
#define time() cout << "-------------Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << "ms.";
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
const int N = (int)1e6+10;
ii a[N],st[4*N];

void update(int node,int l,int r)
{
    if (l == r)
    {
        st[node].fi = a[l].fi, st[node].se = a[l].se;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid);
    update(node*2+1,mid+1,r);
    if (st[node*2].fi > st[node*2+1].fi) st[node] = st[node*2];
    else if (st[node*2].fi < st[node*2+1].fi) st[node] = st[node*2+1];
    else  
    {
        if (st[node*2].se < st[node*2+1].se) st[node] = st[node*2];
        else st[node] = st[node*2+1];
    }
}

ii get(int node,int l,int r,int u,int v)
{
    if (l >= u and r <= v) return st[node];
    if (l > v or r < u) return {-1,-1};
    int mid = (l+r)/2;
    ii x = get(node*2,l,mid,u,v), y = get(node*2+1,mid+1,r,u,v);
    if (x.fi > y.fi) return x;
    if (x.fi < y.fi) return y;
    if (x.fi == y.fi) return (x.se < y.se?x:y); 
}

signed main()
{
    fast;
    // freopen(name".inp","r",stdin);
    // freopen(name".out","w",stdout);
    int n,q;
    cin >> n >> q;
    FOR(i,1,n) cin >> a[i].fi, a[i].se = i;
    update(1,1,n);
    while (q--)
    {
    	int x;
    	cin >> x;
    	cout << get(1,1,n,1,x-1).se << " " << get(1,1,n,x+1,n).se << endl;
    }
    return 0;
}
// ██░ ██  █    ██  ███▄    █   ▄████
//▓██░ ██▒ ██  ▓██▒ ██ ▀█   █  ██▒ ▀█▒
//▒██▀▀██░▓██  ▒██░▓██  ▀█ ██▒▒██░▄▄▄░
//░▓█ ░██ ▓▓█  ░██░▓██▒  ▐▌██▒░▓█  ██▓
//░▓█▒░██▓▒▒█████▓ ▒██░   ▓██░░▒▓███▀▒
// ▒ ░░▒░▒░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒  ░▒   ▒
// ▒ ░▒░ ░░░▒░ ░ ░ ░ ░░   ░ ▒░  ░   ░
// ░  ░░ ░ ░░░ ░ ░    ░   ░ ░ ░ ░   ░
// ░  ░  ░   ░              ░       ░