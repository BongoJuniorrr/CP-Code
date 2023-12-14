
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

const string TEMPLATE = "icecream";
const int MOD = 1e9+9;

int n,mmax,m1,m2,m3,ans=0;

void DFS(int i,int d1,int d2,int d3)
{
    if (i>n)
        ans++,ans%=MOD;
    else
    {
        FOR(j,0,2)
        {
            int n1=d1;
            int n2=d2;
            int n3=d3;
            if (j==0)
                n1++;
            if (j==1)
            {
                n2++;
                n1--;
            }
            if (j==2)
            {
                if (n1!=0 && n2!=0)
                    n1--,n2--,n3++;
                else n1-=3,n3++;
            }
            if (n1>=0 && n2>=0 && n3>=0 && n1<=mmax && n2<=mmax && n3<=mmax)
                DFS(i+1,n1,n2,n3);
        }
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>mmax>>m1>>m2>>m3;
    DFS(1,m1,m2,m3);
    cout<<ans<<'\n';
    return 0;
}