
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

const string TEMPLATE = "name";
const int N = 50005;

int n,a[N],ans=1;

bool check(int L,int R,int t)
{
    if (t==1)
    {
        int curr=1;
        FOR(i,L,R)
        {
            if (a[i]<curr)
                return 0;
            curr++;
        }
        return 1;
    }
    else
    {
        int curr=1;
        FOD(i,R,L)
        {
            if (a[i]<curr)
                return 0;
            curr++;
        }
        return 1;
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    FOR(i,2,n-1)
    {
        int L=1,R=1;
        int j=i-1;
        while(check(j,i,1) && j>=1)
            j--;
        j++;
        L=i-j;
        j=i+1;
        while (check(i,j,2) && j<=n)
            j++;
        j--;
        R=j-i;
        ans=max(ans,min(L,R)+1);
        //cout<<i<<" "<<L<<" "<<R<<'\n';
    }
    cout<<ans;
    return 0;
}