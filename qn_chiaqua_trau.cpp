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
//#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "qn_chiaqua";

int n,a[25];
bool ans=false;

void DFS(int i,int d1,int d2)
{
    if (i>n)
    {
        if (d1==d2) ans=true;
    }
    else
    {
        FOR(j,0,1)
        {
            if (j==0)
                d1+=a[i];
            else d2+=a[i];
            DFS(i+1,d1,d2);
            if (j==0)
                d1-=a[i];
            else d2-=a[j];
        }
    }
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".ans").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    DFS(1,0,0);
    cout<<(ans ? "YES" : "NO");
    return 0;
}