
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
//#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "name";
const int N = 2e5+5;

int n,k,ans=0;
int a[N],cnt[N];
vector<int> v;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    FOR(i,1,n)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    FOR(i,1,k)
        if (cnt[i]) v.pb(cnt[i]);
    sort(v.begin(),v.end());
    int i=0,j=v.size()-1;
    while (i<j)
    {
        if (v[i]==0) i++;
        if (v[j]==0) j--;
        if (i>=j) break;
        if (v[i]!=0 && v[j]!=0)
        {
            ans+=2;
            v[i]--;
            v[j]--;
        }
    }
    cout<<ans;
    return 0;
}