
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

string s1,s2;
int ans=0,cnt[30][2];

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>s1>>s2;
    FOR(i,0,s1.size()-1) cnt[s1[i]-'a'][0]++;
    FOR(i,0,s2.size()-1) cnt[s2[i]-'a'][1]++;
    FOR(i,0,26)
    {
        if ((cnt[i][0]==0 && cnt[i][1]!=0) || (cnt[i][0]!=0 && cnt[i][1]==0))
            ans+=max(cnt[i][0],cnt[i][1]);
    }
    cout<<ans;
    return 0;
}