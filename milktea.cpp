#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FOD(i,a,b) for(ll i=a;i>=b;i--)
#define ii pair<ll,ll>
#define fi first
#define se second
const ll N=2e5+5;
ll n,H[N],P[N][30],Lg[N],Cnt[N],Add[N],res;
vector<ii> G[N];
ii C[N];
void setup(ll u,ll pre){
    for(ii v:G[u]){
        if(v.se==pre) continue;
        H[v.se]=H[u]+1,P[v.se][0]=u;
        setup(v.se,u);
    }
}
void Build(){
    FOR(i,2,n) Lg[i]=Lg[i>>1]+1;
    FOR(i,1,Lg[n]){
        FOR(u,1,n) P[u][i]=P[P[u][i-1]][i-1];
    }
}
ll LCA(ll u,ll v){
    if(H[u]<H[v]) swap(u,v);
    ll lg=Lg[H[u]];
    FOD(i,lg,0){
        if(H[u]-H[v]-(1<<i)>=0) u=P[u][i];
    }
    if(u==v) return u;
    FOD(i,lg,0){
        if(P[u][i]!=P[v][i]){
            u=P[u][i],v=P[v][i];
        }
    }
    return P[u][0];
}
void DFS(ll u,ll pre){
    for(ii v:G[u]){
        if(v.se==pre) continue;
        DFS(v.se,u);
        Cnt[v.fi]=Add[v.se];
        Add[u]+=Add[v.se];
    }
}
signed main(){
    fast
    cin>>n;
    FOR(i,1,n-1){
        ll u,v;cin>>u>>v;
        G[u].push_back({i,v});
        G[v].push_back({i,u});
        cin>>C[i].fi>>C[i].se;
    }
    setup(1,0);Build();
    FOR(u,1,n-1){
        ll p=LCA(u,u+1);
        Add[p]-=2,Add[u]++,Add[u+1]++;
    }
    DFS(1,0);
    FOR(i,1,n-1){
        res+=min(Cnt[i]*C[i].fi,C[i].se);
    }
    cout<<res<<endl;
    return 0;
}