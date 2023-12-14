
//"----------------------------------------------------------------------------------------"
//"- Author: Hirobi aka BongoJuniorr"
//"- School: Le Quy Don High School for the Gifted"
//"- Date: dd/mm/yyyy"
//"- Problem: "
//"- File: "
//"- I/O File: "
//"----------------------------------------------------------------------------------------"

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl endl(*)

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)

#define ull unsigned long long
#define ll long long
#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "TRIANGLE";
const int N = 1e6+6;

int n,x,ans=0;
vector<int> a[4];
int sum[N];

bool cmp(vector<int> b, vector<int> c)
{
    return b.size() < c.size();
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        char c; int x;
        cin>>c>>x;
        if (c=='r') a[1].pb(x);
        if (c=='g') a[2].pb(x);
        if (c=='b') a[3].pb(x);
    }
    sort(a+1,a+3+1,cmp);
    for (auto x:a[3])
        sum[x]++;
    FOR(i,1,N-1)
        sum[i]+=sum[i-1];
    for (auto i:a[1])
        for (auto j:a[2])
        {
            int x=i;
            int y=j;
            if (x>y) swap(x,y);
            ans+=sum[x+y-1]-sum[y-x];
        }
    cout<<ans;
    return 0;
}