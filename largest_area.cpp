
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
const int N = 1e5+5;

int n,m,w,h;
bool isVertical[N];
set<int> a,b;
multiset<int,greater<int>> distx,disty;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>w>>h;
    a.insert(w);
    b.insert(h);
    distx.insert(w);
    disty.insert(h);
    cin>>n;
    FOR(i,1,n)
        cin>>isVertical[i];
    cin>>m;
    FOR(i,1,m)
    {
        int x;
        cin>>x;
        if (isVertical[i])
        {
            a.insert(x);
            auto it=a.lower_bound(x); auto itt=it;
            int l,r;
            if (it!=a.begin())
                l=*(itt--);
            else l=0;
            itt=it;
            if (it!=a.end())
                r=*(itt++);
            else r=w;
            distx.erase(r-l);
            distx.insert(x-l); distx.insert(r-x);
        }
        else 
        {
            b.insert(x);
            auto it=b.lower_bound(x); auto itt=it;
            int l,r;
            if (it!=b.begin())
                l=*(itt--);
            else l=0;
            itt=it;
            if (it!=b.end())
                r=*(itt++);
            else r=h;
            disty.erase(r-l);
            disty.insert(x-l); disty.insert(r-x);
        }
        int ans=(*distx.begin())*(*disty.begin());
        cout<<ans<<" "<<*distx.begin()<<" "<<*disty.begin()<<'\n';
    }

    return 0;
}