#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<iomanip>
#include<stack>
#include<deque>
using namespace std;

#define ll long long 
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define in insert

long double pi=3.141592653589793238;
const ll mod=1e9+7;
const ll infl=8e18+7;
const int inf=2e9+7;
const int N=10001000;
string yes="Yes",no="No";
int T,m,cnt,a[N],b[N];
string s;
bool vis[N];
ll ans,n,fr[N],dp[N];
ll f(ll x){return x*(x-1)/2;}
/*
vector<int>v;
set<int>sy;//multiset<int>sy;
map<int,int>mp;
*/

void clean()
{
    ans=f(n);
    for(int i=1;i<=n;i++)
    {
        dp[i]=fr[i]=0;
        vis[i]=0;
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("D.inp","r",stdin);
    freopen("D.ans","w",stdout);
	T=1;
	cin>>T;//
	while(T--)
	{
	    cin>>n;
	    clean();
	    for(int i=1;i<=n;i++)
	    {
	        cin>>a[i];
	        fr[a[i]]++;
	    }
	    for(int i=n;i>0;i--)
	    {
	        ll temp=0,gh=fr[i];
	        for(int j=2*i;j<=n;j+=i)
	        {
	            temp+=dp[j];
	            gh+=fr[j];
	        }
	        dp[i]=f(gh)-temp;
	        if(!fr[i])continue;
	        for(int j=i;j<=n;j+=i)vis[j]=1;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        if(vis[i])ans-=dp[i];
	    }
	    cout<<ans;
	    cout<<endl;
	}
	return 0;
}