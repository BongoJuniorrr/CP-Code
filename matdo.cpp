#include <bits/stdc++.h>
// #define int long long
#define ii pair<int, int>
#define iii pair<ii, int>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'
#pragma GCC O("fast")
using namespace std;
const double eps = 0.0000001;
const int mod = 998244353;
const int N = 200005;
const int MATRIX_SIZE = 3;
int n,cnt[26][N],ans=0,l,r;
string s;
bool check(int s,int t){
    int dist=t-s+1;
    for (int i=0;i<26;++i)
        if (cnt[i][t]-cnt[i][s-1]>dist>>1)
            return true;
    return false;
}
void solve(){
    cin>>s;
    n=s.size();
    s=' '+s;
    for (int i=1;i<=n;++i){
        ++cnt[s[i]-'a'][i];
        for (int j=0;j<26;++j)
            cnt[j][i]+=cnt[j][i-1];
    }
    if (check(1,n))
        return void(cout<<n);
    l=1;
    r=n/2+n%2;
    while (l<=r){
        int mid=(l+r)>>1;
        int res=(mid<<1)-1;
        bool kt=false;
        for (int i=1;i<=n-res+1;++i)
            if (check(i,i+res-1)){
                l=mid+1;
                kt=true;
                ans=res;
            }
        if (!kt) r=mid-1;
    }
    cout<<ans;
}
main() {
    freopen("matdo.inp","r",stdin);
    freopen("matdo.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}