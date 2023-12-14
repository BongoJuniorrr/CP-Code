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
int n,k,ans=0,cnt[50],T[300001];
string s;
void solve(){
    cin>>n>>k;
    cin>>s;
    T[1]=s.size();
    ++cnt[s.size()];
    for (int i=2;i<=n;++i){
        if (i>k+1) --cnt[T[i-k-1]];
        cin>>s;
        T[i]=s.size();
        ans+=cnt[s.size()];
        // cout<<ans<<' '<<s.size()<<' '<<cnt[s.size()]<<' '<<i<<endl;
        ++cnt[s.size()];

    }
    cout<<ans;
}   
main() {
    freopen("friends.inp","r",stdin);
    freopen("friends.out","w",stdout);
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