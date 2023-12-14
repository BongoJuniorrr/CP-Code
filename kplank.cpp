
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

const string TEMPLATE = "kplank";
const int N = 1e6+6;

int n,a[N],L[N],R[N];
stack<int> st;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    a[0]=-1;
    a[n+1]=0;
    st.push(0);
    FOR(i,1,n+1)
    {
        while (a[st.top()] >= a[i])
        {
            int pos=st.top(); st.pop();
            L[pos]=st.top()+1;
            R[pos]=i-1;
        }
        st.push(i);
    }
    int res=1;
    FOR(i,1,n)
        if (a[i]<=R[i]-L[i]+1)
            res=max(res,a[i]);
    cout<<res;
    return 0;
}