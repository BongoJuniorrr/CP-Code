
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

int n,k;
vector<int> ans;

void phantich(int n)
{
    while (n%2==0 && n>1)
        n/=2,ans.pb(2);
    int i=3;
    while (n>1)
    {
        if (n%i==0)
            n/=i,ans.pb(i);
        else i+=2;
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    if (n==0)
    {
        cout<<0;
        return 0;
    }
    phantich(n);
    for (auto i:ans)
        if (i>9)
        {
            cout<<-1;
            return 0;
        }
    deque<int> dq;
    for (auto i:ans)
        dq.pb(i);
    while (dq.size()>k)
    {
        int a=dq.back();
        dq.pop_back();
        int b=dq.back();
        dq.pop_back();
        if (a*b>9)
            dq.push_front(a),dq.push_back(b);
        else
            dq.push_back(a*b);
    }
    while (dq.size()<k)
        dq.push_front(1);
    vector<int> res;
    while (!dq.empty())
        res.pb(dq.front()),dq.pop_front();
    sort(res.begin(),res.end());
    int res1=0,res2=0,kt1=1,kt2=1;
    for (auto i:res)
        res1*=10,res1+=i,kt1*=i;
    if (kt1!=n) res1=1e18;
    priority_queue<int,vector<int>,greater<int>> dq2;
    for (auto i:ans)
        dq2.push(i);
    while (dq2.size()>k)
    {
        int a=dq2.top();
        dq2.pop();
        int b=dq2.top();
        dq2.pop();
        if (a*b>9)
            break;
        dq2.push(a*b);
    }
    while (dq2.size()<k)
        dq2.push(1);
    res.clear();
    while (!dq2.empty())
        res.pb(dq2.top()),dq2.pop();
    sort(res.begin(),res.end());
    for (auto i:res)
        res2*=10,res2+=i,kt2*=i;
    if (kt2!=n)
        kt2=1e18;
    int rescue = min(res1,res2);
    if (rescue==1e18)
        cout<<-1;
    else cout<<rescue<<" "<<res1<<" "<<res2;
    return 0;
}