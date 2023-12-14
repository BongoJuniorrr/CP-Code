
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

#define int unsigned int
#define ll long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "name";
const int N = 2e5+5;

int n,q,a[N];
int dp[N][40];

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n)
    {
        FOR(j,0,31)
        {
            dp[i][j]=dp[i-1][j];
            if ((a[i]^(1<<j)) > (a[i]&(1<<j))) dp[i][j]++;
        }
    }
    cin>>q;
    while (q--)
    {
        int L,R,x;
        cin>>L>>R>>x;
        int u;
        FOD(i,31,0)
        {
            if (x&(1<<i))
            {
                u=i;
                break;
            }
        }
        cout<<dp[R][u]-dp[L-1][u]<<'\n';
    }
    return 0;
}