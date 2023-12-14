#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
const ll N=1e6+5,oo=1e18;
ll n,k,Val[N],Cop[N],res=oo;
void check(ll mask){
    FOR(i,1,n) Cop[i]=Val[i];
    FOR(i,0,n-1){
        if((mask>>i)&1) Cop[i+1]+=k;
        else Cop[i+1]-=k;
    }
    ll mx=-oo,mn=oo;
    FOR(i,1,n){
        mx=max(mx,Cop[i]);
        mn=min(mn,Cop[i]);
    }
    // if(mx-mn==43){
    //     FOR(i,1,n) cout<<Cop[i]<<" ";cout<<endl;
    // }
    res=min(res,mx-mn);
}
signed main(){
    freopen("mangx.inp","r",stdin);
    freopen("mangx.ans","w",stdout);
    fast
    cin>>n>>k;
    FOR(i,1,n) cin>>Val[i];
    FOR(mask,0,(1<<n)-1) check(mask);
    cout<<res;
    return 0;
}