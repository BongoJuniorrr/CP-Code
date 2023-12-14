
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

const string TEMPLATE = "D";
const int N = 1e6+6;

int T,n,cnt[N],ans;
set<int> b[N];

void phantich(int x)
{
    int d1=0;
    int d2=0;
    for (int i=x;i<=n;i+=x)
    {   
        d1+=cnt[i];
        if (b[i]) d2+=cnt[i];
        b[i].insert(x);
    }
    int s1=d1*(d1-1)/2;
    int s2=d2*(d2-1)/2;
    ans-=s1-s2;
    // FOR(i,0,v.size()-2)
    //     FOR(j,i+1,v.size()-1)
    //         cout<<v[i]<<" "<<v[j]<<'\n';
    cout<<x<<" "<<d1<<" "<<d2<<'\n';
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>T;
    while (T--)
    {
        cin>>n;
        FOR(i,1,n+1) cnt[i]=b[i]=0;
        FOR(i,1,n)
        {
            int x;
            cin>>x;
            cnt[x]++;
        }
        ans=n*(n-1)/2;
        FOR(i,1,n)
            if (cnt[i])
                phantich(i);
        cout<<ans<<'\n';
    }
    return 0;   
}