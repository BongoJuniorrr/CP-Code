
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
//#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "qn_chiaqua";

int n,sum1=0,sum2=0,cnt1=0,cnt2=0;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        int x;
        cin>>x;
        if (x==100) cnt1++;
        else cnt2++;
    }
    while (cnt2>0)
    {
        if (sum1<sum2) sum1+=200;
        else sum2+=200;
        cnt2--;
    }
    while (cnt1>0)
    {
        if (sum1<sum2) sum1+=100;
        else sum2+=100;
        cnt1--;
    }
    cout<<(sum1==sum2 ? "YES" : "NO");
    return 0;
}