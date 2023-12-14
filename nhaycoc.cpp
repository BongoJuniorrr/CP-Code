
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

const string TEMPLATE = "NHAYCOC";
const int N = 1e6+6;

int n,a[N],ans=0;
stack<int> st;


signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    st.push(1);
    FOR(i,2,n)
    {
        while (!st.empty() && a[st.top()]<a[i]) st.pop(),ans++;
        if(!st.empty()&&a[st.top()]>a[i]) ans++;
        st.push(i);
    }
    cout<<ans<<'\n';
    while(!st.empty()) st.pop();
    st.push(1);
    FOR(i,2,n){
        while (!st.empty() && a[st.top()]<=a[i]){
            if(a[st.top()]==a[i]) ans++;
            st.pop();
        }
        st.push(i);
    }
    cout<<ans;
    return 0;
}