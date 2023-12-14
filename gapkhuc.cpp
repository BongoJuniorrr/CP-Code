#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define iii pair<ii,int>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'
using namespace std;
const double eps = 0.000001;
const int mod = 1000000007;
const int N = 101;
const int MATRIX_SIZE = 3;
int n,mi=1e18,ma=0,mahi=0,cao,tam,ans=0;
ii st[5001];
bool T[1001][1001];
void lazy(int id){
	st[id*2].fi=max(st[id*2].fi,st[id].se);
	st[id*2+1].fi=max(st[id*2+1].fi,st[id].se);
	st[id*2].se=max(st[id*2].se,st[id].se);
	st[id*2+1].se=max(st[id*2+1].se,st[id].se);
}
void up(int id,int l,int r,int ct,int cp,int val){
	if (l>cp||r<ct) return;
	if (l>=ct&&r<=cp){
		st[id].fi=max(st[id].fi,val);
		st[id].se=max(st[id].se,val);
		return;
	}
	lazy(id);
	int mid=l+r>>1;
	up(id*2,l,mid,ct,cp,val);
	up(id*2+1,mid+1,r,ct,cp,val);
}
int get(int id,int l,int r,int pos){
	if (l>pos||r<pos) return 0;
	if (l==r) return st[id].fi;
	lazy(id);
	int mid=l+r>>1;
	return max(get(id*2,l,mid,pos),get(id*2+1,mid+1,r,pos));
}
void solve(){
	cin>>n;
	for (int i=1,l,r,h;i<=n;++i){
		cin>>l>>r>>h;
		++l;
		--r;
		mi=min(mi,l);
		ma=max(ma,r);
		up(1,1,1000,l,r,h);
	}
	// ++mi;--ma;
	cao=get(1,1,1000,mi);
	for (int i=0;i<=cao;++i) T[i][mi]=true;
    cao=0;
    // cao=get(1,1,1000,mi);
    // for (int i=0;i<=cao;++i) T[i][ma+1]=true;
	for (int i=mi;i<=ma;++i){
		tam=get(1,1,1000,i);
		// cout<<i<<' '<<tam<<endl;
		mahi=max(mahi,tam);
		for (int j=min(cao,tam);j<=max(cao,tam);++j)
			T[j][i]=true;
		cao=tam;
	}
	for (int i=0;i<=cao;++i) T[i][ma+1]=true;
	// cout<<ma<<endl;
	// for (int j=mi;j<=ma;j++)
	// 	if (T[mahi][j]) T[mahi][j]=0,T[mahi-1][j]=1;
    // for (int i=mahi;i>=1;i--)
    //     if (T[i][mi]) T[i][mi]=0,T[i][mi+1]=1;
    // for (int i=mahi;i>=1;i--)
    //     if (T[i][ma]) T[i][ma]=0,T[i][ma-1]=1;
    // int ans=0;
	for (int i=mahi;i>=1;--i){
		for (int j=mi;j<=ma+1;++j){
			if (T[i][j]) ans++;
		}
    }
    cout<<ans<<'\n';
	for (int i=mahi;i>=1;--i){
		for (int j=mi;j<=ma+1;++j){
			if (T[i][j]) cout<<'#';
			else cout<<'.';
		}
		cout<<endl;
	}
	for (int i=mi;i<=ma+1;++i) cout<<'*';
}
main() {
    // freopen("ok.inp","r",stdin);
	// freopen("ok.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    solve();
}
