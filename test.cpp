#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define iii pair<int,ii>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'
using namespace std;
const double eps = 0.000001;
const int mod = 998244353;
const int N = 200001;
const int MATRIX_SIZE = 3;
int n,k,dp[401][401],T[401];
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;++i) cin>>T[i];
    for (int i=1,ma=0,s=0;i<=n;++i){
        ma=max(ma,T[i]);
        s+=T[i];
        dp[i][0]=ma*i-s;
    }
    for (int i=2,ma,s;i<=n;++i){
        for (int j=1;j<=k;++j){
            ma=s=T[i];
            dp[i][j]=1e18;
            for (int z=i-1;z>=j;--z){
                dp[i][j]=min(dp[i][j],dp[z][j-1]+(i-z)*ma-s);
                // cout<<i<<' '<<j<<' '<<z<<' '<<dp[z][k-1]<<' '<<dp[i][j]<<endl;
                ma=max(ma,T[z]);
                s+=T[z];
            }
            // cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][k];
}   
main() {
    // freopen("ok.inp","r",stdin);
    // freopen("ok.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}


//  ▄████▄   █    ██  ▒█████   ███▄    █   ▄████ 
// ▒██▀ ▀█   ██  ▓██▒▒██▒  ██▒ ██ ▀█   █  ██▒ ▀█▒
// ▒▓█    ▄ ▓██  ▒██░▒██░  ██▒▓██  ▀█ ██▒▒██░▄▄▄░
// ▒▓▓▄ ▄██▒▓▓█  ░██░▒██   ██░▓██▒  ▐▌██▒░▓█  ██▓
// ▒ ▓███▀ ░▒▒█████▓ ░ ████▓▒░▒██░   ▓██░░▒▓███▀▒
// ░ ░▒ ▒  ░░▒▓▒ ▒ ▒ ░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ░▒   ▒ 
//   ░  ▒   ░░▒░ ░ ░   ░ ▒ ▒░ ░ ░░   ░ ▒░  ░   ░ 
// ░         ░░░ ░ ░ ░ ░ ░ ▒     ░   ░ ░ ░ ░   ░ 
// ░ ░         ░         ░ ░           ░       ░ 
// ░