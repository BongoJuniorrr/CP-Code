
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

const string TEMPLATE = "SECRCD";
const int MOD = 1e9+7;
const int N = 1e6+6;

int n,ans=1;
int isPrime[N];
int cnt[N];

void sieve()
{
    for (int i=2;i<=1000;++i)
    {
        if (!isPrime[i]){
            isPrime[i]=i;
            for (int j=i*i;j<=1000000;j+=i)
                if (!isPrime[j]) isPrime[j]=i;
        }
    }
    for (int i=1001;i<=1000000;++i)
        if (!isPrime[i]) isPrime[i]=i;
}

void phantich(int n)
{
    while (n>1)
    {
        cnt[isPrime[n]]++;
        n/=isPrime[n];
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    sieve();
    cin>>n;
    FOR(i,1,n)
    {
        int x;
        cin>>x;
        phantich(x);
    }
    FOR(i,1,N-1)
    {
        if (!cnt[i])
            continue;
        int x=cnt[i];
        ans=((ans%MOD)*(x+1)%MOD)%MOD;
    }
    cout<<ans;
    return 0;
}