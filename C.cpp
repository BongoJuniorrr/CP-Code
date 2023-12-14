
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
const int N = 2e5+5;

int T,n,m,ans=0;
vector<ii> a;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>T;
    while (T--)
    {
        ans=0;
        int l1=0,rm=0;
        cin>>n>>m;
        FOR(i,1,n)
        {
            int L,R;
            cin>>L>>R;
            a.pb({L,R});
        }
        sort(a.begin(),a.end());
        priority_queue<ii,vector<ii>,greater<ii>> Q;
        for (auto i:a)
        {
            int L=i.fi;
            int R=i.se;
            if (L==1) l1++;
            if (R==m) rm++;
            // if (!Q.empty())
            //     cout<<Q.top().fi<<" "<<Q.top().se<<"\n";
            // else cout<<"0 0"<<'\n';
            while (!Q.empty() && Q.top().fi<L)
            {
                if (Q.top().se==1) l1--;
                if (Q.top().se==m) rm--;
                Q.pop();
            }
            Q.push({R,L});
            ans=max(ans,(int)Q.size()-min(l1,rm));
            //cout<<Q.size()<<" "<<l1<<" "<<rm<<'\n';
        }
        cout<<ans<<'\n';
        a.clear();
    }
    return 0;
}