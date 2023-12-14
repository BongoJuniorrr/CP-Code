
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

const string TEMPLATE = "name";
const int N = 1e5+5;
int tog(int x){
    if (x==0) return 0;
    return x*(x+1)/2;
}
int n,sl=0,sum=0,i,sau=0;
signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    int T;
    cin>>T;
    while (T--)
    {
        
        string s;
        cin>>n>>s;
        reverse(s.begin(),s.end());
        s='#'+s;
        // n--;
        sl=s[1]=='1';
        sum=sl;
        i=1;
        sau=0;
        for (int pos=2;pos<=n;++pos){
            if (s[pos]=='1') {
                ++sl;
                sum+=pos;
            }
            if (pos-i==sl){
                sau=pos*sl-tog(sl-1)-sum;cout<<sau<<' ';
                ++i;
            }
            else if (pos-i>sl){
                cout<<sau<<' ';
                ++i;
            }
        }
        if (sl==0) {
            ++i;
            cout<<0<<' ';
        }
        for (int j=i;j<=n;++j) cout<<-1<<' ';
        cout<<'\n';
    }
    return 0;
}