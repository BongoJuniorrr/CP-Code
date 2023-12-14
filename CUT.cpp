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

const string TEMPLATE = "cut";

int k,ans=1;

int cal_sum(int R)
{
    if (R==0) return 1;
    int L=1;
    int d=(R-L)+1;
    return (L+R)*d/2+1;
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>k;
    int L=0,R=1000000,mid;
    while (L<=R)
    {
        mid=L+R>>1;
        //cout<<mid<<" "<<cal_sum(mid)<<'\n';
        if (cal_sum(mid)>=k)
            ans=mid,R=mid-1;
        else L=mid+1;
    }
    cout<<ans;
    return 0;
}