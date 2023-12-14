
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

const string TEMPLATE = "trungthuong";
const int N = 2e5+5;
const int LG = 15;

int n,a[N],ans=0;
int st[21][2005][2];

void preprocess()
{
    for (int i = 1; i <= n; ++i) st[0][i][0] = st[0][i][1] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            st[j][i][0] = min(st[j - 1][i][0], st[j - 1][i + (1 << (j - 1))][0]);
            st[j][i][1] = max(st[j - 1][i][1], st[j - 1][i + (1 << (j - 1))][1]);
        }
}
int queryMin(int l, int r) 
{
    int k = __lg(r - l + 1);
    return min(st[k][l][0], st[k][r - (1 << k) + 1][0]);
}

int queryMax(int l, int r) 
{
    int k = __lg(r - l + 1);
    return max(st[k][l][1], st[k][r - (1 << k) + 1][1]);
}

void sub12()
{
    preprocess();
    FOR(i,1,n)
        FOR(j,i+1,n)
        {
            int c=min(a[i],a[j]);
            int d=max(a[i],a[j]);
            // cout<<c<<" "<<d<<" "<<queryMin(i,j)<<" "<<queryMax(i,j)<<'\n';
            if (c==queryMin(i,j) && d==queryMax(i,j)) ans++;
        }
}

int C2(int n)
{
    return n*(n-1)/2;
}

void sub3()
{
    vector<int> v1,v2,v3;
    FOR(i,1,n)
    {
        if (a[i]==1) v1.push_back(i);
        else if (a[i]==2) v2.push_back(i);
        else v3.push_back(i);
    }
    FOR(i,1,n)
    {
        if (a[i]==1)
        {
            if (v3.size())
            {
                int idx3 = lower_bound(v3.begin(),v3.end(),i)-v3.begin();
                ans+=v3.size()-idx3;
                //cout<<"1:"<<" "<<v3.size()-idx3<<" ";
            }
            int vt3=n+1;
            if (v3.size())
            {
                auto it3 = lower_bound(v3.begin(),v3.end(),i);
                if (it3==v3.end()) vt3=n+1;
                else vt3=*it3;
            }
            int idx2=0;
            if (v2.size())
            {
                auto it21 = lower_bound(v2.begin(),v2.end(),vt3);
                auto it22 = lower_bound(v2.begin(),v2.end(),i);
                if (it21 != v3.begin()) it21--,idx2=it21-it22+1;
            }
            if (idx2<0) idx2=0;
            ans+=idx2;
            //cout<<idx2<<'\n';
        }
        if (a[i]==2)
        {
            if (v1.size() && v3.size())
            {
                auto it1 = lower_bound(v1.begin(),v1.end(),i);
                int vt=n+1;
                if (it1!=v1.end()) vt=*it1;
                auto it31 = lower_bound(v3.begin(),v3.end(),vt);
                auto it32 = lower_bound(v3.begin(),v3.end(),i);   
                int idx3=0;
                if (it31 != v3.begin()) it31--,idx3=it31-it32+1;
                ans+=idx3;
                //cout<<"2:"<<" "<<idx3<<" ";
                it1 = lower_bound(v3.begin(),v3.end(),i);
                vt=n+1;
                if (it1!=v3.end()) vt=*it1;
                it31 = lower_bound(v1.begin(),v1.end(),vt);
                it32 = lower_bound(v1.begin(),v1.end(),i);   
                idx3=0;
                if (it31 != v3.begin()) it31--,idx3=it31-it32+1;
                if (idx3<0) idx3=0;
                ans+=idx3;
                //cout<<idx3<<'\n';
            }
            if (v1.size() && !v3.size())
            {
                int idx = lower_bound(v1.begin(),v1.end(),i)-v1.begin();
                int c=v1.size()-idx;
                if (c<0) c=0;
                ans+=c;
            }
            if (!v1.size() && v3.size())
            {
                int idx = lower_bound(v3.begin(),v3.end(),i)-v3.begin();
                int c=v3.size()-idx;
                if (c<0) c=0;
                ans+=c;
            }
        }
        if (a[i]==3)
        {
            if (v1.size())
            {
                int idx3 = lower_bound(v1.begin(),v1.end(),i)-v1.begin();
                ans+=v1.size()-idx3;
                //cout<<"3:"<<" "<<v1.size()-idx3<<" ";
            }
            int vt3=n+1;
            if (v1.size())
            {
                auto it3 = lower_bound(v1.begin(),v1.end(),i);
                if (it3!=v1.end())
                    vt3=*it3;
                else vt3=n+1;
            }
            int idx2=0;
            if (v2.size())
            {
                auto it21 = lower_bound(v2.begin(),v2.end(),vt3);
                auto it22 = lower_bound(v2.begin(),v2.end(),i);
                if (it21 != v3.begin()) it21--,idx2=it21-it22+1;
            }
            if (idx2<0) idx2=0;
            ans+=idx2;
            //cout<<idx2<<'\n';
        }
    }
    int pre=a[1],d=1;
    FOR(i,2,n)
    {
        if (a[i]==pre) d++;
        else ans+=C2(d),d=1,pre=a[i];
    }
    ans+=C2(d);
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    // if (n<=2000) sub12();
    // else sub3();
    //sub12();
    sub3();
    cout<<ans;
    return 0;
}