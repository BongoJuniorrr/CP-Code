#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll N=1e6+5;
ll n,k,A[N],Sp[N][30],Lg[N];
ll get(ll l,ll r){
    ll lg=Lg[r-l+1];
    return min(Sp[l][lg],Sp[r-(1<<lg)+1][lg]);
}
signed main(){
    freopen("DIFFERENCE.inp","r",stdin);
    freopen("DIFFERENCE.out","w",stdout);
    fast
    cin>>n>>k;
    ll d=n-k;
    FOR(i,1,n) cin>>A[i];
    sort(A+1,A+n+1);
    FOR(i,1,n-1) Sp[i][0]=A[i+1]-A[i];
    FOR(i,2,n) Lg[i]=Lg[i>>1]+1;
    FOR(j,1,Lg[n-1]){
        FOR(i,1,n-(1<<j)){
            Sp[i][j]=min(Sp[i][j-1],Sp[i+(1<<(j-1))][j-1]);
        }
    }
    ll ans=1e18;
    FOR(i,d,n){
        ll val=A[i]-A[i-d+1]+get(i-d+1,i-1);
        ans=min(ans,val);
    }
    cout<<ans;
    return 0;
}