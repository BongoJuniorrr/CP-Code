
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

const string TEMPLATE = "PAIRSFR";
const int N = 1e6+6;

int L,R,ans=0,n;
int sum[N];
bool cnt[N];

void sieve()
{
    n=N;
    FOR(i,1,n)
        for (int j=i*2;j<=n;j+=i)
            sum[j]+=i;
}

signed main()
{
    fast;
    //freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    //freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>L>>R;
    sieve();
    FOR(i,L,R)
    {
        int a=sum[i];
        if (a>R)
            continue;
        int b=sum[a];
        if (b==i && a>=L && a<=R && b>=L && b<=R && !cnt[i] && !cnt[sum[i]])
        {
            ans++,cnt[i]=1,cnt[sum[i]]=1;//,cout<<i<<" "<<a<<" "<<b<<'\n';
            cout<<i<<" "<<sum[i]<<"\n";
        }
    }
    cout<<ans;
    return 0;
}