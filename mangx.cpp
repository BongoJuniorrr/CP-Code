
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

const string TEMPLATE = "mangx";
const int N = 2e5+5;

int n,x,a[N];
deque<int> dq;
multiset<int,greater<int>> se;
multiset<int> se2;
multiset<int> mul1;
multiset<int,greater<int>> mul2;
multiset<ii> mul3;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>x;
    FOR(i,1,n) cin>>a[i],se.insert(a[i]),se2.insert(a[i]);
    sort(a+1,a+n+1);
    dq.pb(-1);
    int cnt=0;
    while (dq.size())
    {
        if (dq.front()==-1) dq.pop_front();
        while (dq.size()) se.insert(dq.front()),dq.pop_front();
        while (se.size())
        {
            int mx1,mx2,mi1,mi2;
            if (mul1.size()>1)
            {
                auto it1=mul1.begin(); auto it2=mul2.begin();
                mx1=*it2; mi1=*it1; mx2=mx1; mi2=mi1;
            } else mx1=mx2=a[n],mi1=mi2=a[1];
            int mx=mx1; int mi=mi1;
            int val=*se.begin();
            int da1=val-x;
            int da2=val+x;
            mx1=max(mx1,da1); mi1=min(mi1,da1);
            mx2=max(mx2,da2); mi2=min(mi2,da2);
            if (mx1-mi1==mx2-mi2 && cnt<1) dq.pb(val);
            else if (mx1-mi1 < mx2-mi2) mul1.insert(da1),mul2.insert(da1),mul3.insert({da1,val});
            else mul1.insert(da2),mul2.insert(da2),mul3.insert({da2,val});
            // mul1.erase(mul1.find(val));
            // mul2.erase(mul2.find(val));
            se.erase(se.begin());
            //cout<<val<<" "<<mx1<<" "<<mi1<<" "<<mx2<<" "<<mi2<<" "<<mx<<" "<<mi<<'\n';
        }
        cnt++;
    }
    int ans1=abs(*mul2.begin()-*mul1.begin());
    mul1.clear(); mul2.clear(); mul3.clear();
    dq.pb(-1);
    cnt=0;
    while (dq.size())
    {
        if (dq.front()==-1) dq.pop_front();
        while (dq.size()) se2.insert(dq.front()),dq.pop_front();
        while (se2.size())
        {
            int mx1,mx2,mi1,mi2;
            if (mul1.size()>1)
            {
                auto it1=mul1.begin(); auto it2=mul2.begin();
                mx1=*it2; mi1=*it1; mx2=mx1; mi2=mi1;
            } else mx1=mx2=a[n],mi1=mi2=a[1];
            int mx=mx1; int mi=mi1;
            int val=*se2.begin();
            int da1=val-x;
            int da2=val+x;
            mx1=max(mx1,da1); mi1=min(mi1,da1);
            mx2=max(mx2,da2); mi2=min(mi2,da2);
            if (mx1-mi1==mx2-mi2 && cnt<1) dq.pb(val);
            else if (mx1-mi1 < mx2-mi2) mul1.insert(da1),mul2.insert(da1),mul3.insert({da1,val});
            else mul1.insert(da2),mul2.insert(da2),mul3.insert({da2,val});
            // mul1.erase(mul1.find(val));
            // mul2.erase(mul2.find(val));
            se2.erase(se2.begin());
            //cout<<val<<" "<<mx1<<" "<<mi1<<" "<<mx2<<" "<<mi2<<" "<<mx<<" "<<mi<<'\n';
        }
        cnt++;
    }
    //cout<<'\n';
    int ans2=abs(*mul2.begin()-*mul1.begin());
    cout<<min(ans1,ans2)<<'\n';
    //cout<<ans2<<'\n';
    // for (auto i:mul3)
    //     cout<<i.fi<<" "<<i.se<<'\n';
    return 0;
}