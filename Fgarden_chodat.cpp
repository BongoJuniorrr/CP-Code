#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define db long double
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
const ll N=2e2+5;
ll n,t,A[N],res;
signed main(){
    freopen("Fgarden.inp","r",stdin);
    freopen("Fgarden.ans","w",stdout);
    fast
    cin>>n>>t;
    FOR(i,1,n) cin>>A[i];
    FOR(l,1,n){
        FOR(r,l,n){
            ll mn=1e18,mx=0;
            FOR(x,l,r){
                mn=min(mn,A[x]),mx=max(mx,A[x]);

            }
            if(mx-mn<=t) res=max(res,r-l+1);
        }
    }
    cout<<res;
    return 0;
}