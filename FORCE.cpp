
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

const string TEMPLATE = "FORCE";

int A,B;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>A>>B;
    A--;
    int sum1=0,sum2=0;
    if (B<=6)
    {
        int val=2;
        FOR(i,1,B)
        {
            sum1+=val;
            if (val==2 && i!=5)
                val=3;
            else if (val==3 && i!=5)
                val=2;
            else val=4;
        }
    }
    else
    {
        sum1=16+(B-6)/12*31;
        int val=2;
        FOR(i,(B-6)/12*12+1,B)
        {
            sum1+=val;
            if (val==2) val=3;
            else val=2;
        }
    }
    if (A<=6)
    {
        int val=2;
        FOR(i,1,A)
        {
            sum2+=val;
            if (val==2 && i!=5)
                val=3;
            else if (val==3 && i!=5)
                val=2;
            else val=4;
        }
    }
    else
    {
        sum2=16+(A-6)/12*31;
        int val=2;
        FOR(i,(A-6)/12*12+1,A)
        {
            sum2+=val;
            if (val==2) val=3;
            else val=2;
        }
    }
    cout<<sum1-sum2;
    return 0;
}