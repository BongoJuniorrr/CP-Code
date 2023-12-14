
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

const string TEMPLATE = "TraSua";

int n,m,k;
map<ii,int> ma;
bool check[1005];

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    //freopen((TEMPLATE+".inp").c_str(),"w",stdout);
    n = 10;
    m = abs(rand()%20+1);
    k = abs(rand()%5+1);
    cout<<n<<" "<<m<<" "<<k<<'\n';
    FOR(i,1,n-1)
    {
        cout<<i<<" "<<i+1<<" "<<abs(rand()%10+1)<<'\n';
        ma[{i,i+1}]=1;
    }
    m-=n-1;
    while (m--)
    {
        int i;
        int j;
        while (true)
        {
            i=abs(rand()%n+1);
            j=abs(rand()%n+1);  
            if (i==j)
            continue;
            if (ma[{i,j}])
            continue;
            break;
            cout<<i<<" "<<j<<'\n';
        }
        ma[{i,j}]=1;
        cout<<i<<" "<<j<<" "<<abs(rand()%10+1)<<'\n';
    }
    while (k--)
    {
        int t=abs(rand()%n+1);
        int d=abs(rand()%2);
        cout<<t<<" "<<d<<'\n';
    }
    return 0;
}