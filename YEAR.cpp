
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

const string TEMPLATE = "YEAR";

int n,a[1005],b[1005];

bool check(int a,int b)
{
    int cnt=0;
    while (a>0 && b>0)
    {
        if (a%10!=b%10)
            cnt++;
        a/=10;
        b/=10;
    }
    if (cnt>1)
        return 0;
    return 1;
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    int curr=1000;
    FOR(i,1,n)
    {
        while (curr<=2011)
        {
            if (check(a[i],curr))
                break;
            curr++;
        }
        b[i]=curr;
    }
    bool ans=1;
    FOR(i,1,n)
        if (!check(a[i],b[i]) || b[i]<1000 || b[i]>2011)
        {
            ans=0;
            break;
        }
    FOR(i,2,n)
    {
        if (b[i]<b[i-1])
        {
            ans=0;
            break;
        }
    }
    if (!ans)
        cout<<-1;
    else
    {
        FOR(i,1,n)
            cout<<b[i]<<"\n";    
    }
    return 0;
}