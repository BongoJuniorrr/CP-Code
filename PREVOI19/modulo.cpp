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

const string TEMPLATE = "modulo";

string Cong(string a,string b)
{
	while (a.size()<b.size()) a='0'+a;
	while (b.size()<a.size()) b='0'+b;
	int x,y,nho=0,c; string st="";
	for (int i=a.size()-1;i>=0;i--)
	{
		x=int(a[i])-48; y=int(b[i])-48;
		c=x+y+nho;
		nho=c/10;
		c%=10;
		st=char(c+48)+st;
	}
	if (nho==1)
		st='1'+st;
	return st;
}

string Tru(string a,string b)
{
	while (a.size()<b.size()) a='0'+a;
	while (b.size()<a.size()) b='0'+b;
	int x,y,muon=0,c; string st=""; bool kt=false;
	if (b>a) {swap(a,b); kt=true;}
	for (int i=a.size()-1;i>=0;i--)
	{
		x=int(a[i])-48; y=int(b[i])-48;
		c=x-y-muon;
		if (c<0)
		{
			muon=1;	
			c+=10;
		} else muon=0;
		st=char(c+48)+st;
	}
	while (st[0]=='0' && st.size()>1)
		st.erase(0,1);
	if (kt)
		st='-'+st;
	return st;
}

string Nhan(string a,string b)
{
	if (a=="0" || b=="0")
		return "0";
	vector<int> vec(a.size()+b.size()+1);
	for (int i=b.size()-1;i>=0;i--)
	{
		for (int j=a.size()-1;j>=0;j--)
		{
			vec[i+j+1]=vec[i+j+1] + (int(a[j])-48)*(int(b[i])-48);
			vec[i+j]=vec[i+j] + vec[i+j+1]/10;
			vec[i+j+1]%=10;
		}
	}
	vec.erase(vec.end()-1,vec.end());
	if (vec[0]==0)
		vec.erase(vec.begin());
    string res;
	for (auto i:vec)
		res.pb(char(i+48));
	return res;
}

int A,B,n,k;
string ans="-1";

string doi(int n)
{
    string res="";
    while (n>0)
        res.pb(n%10+48),n/=10;
    return res;
}

bool check(string s)
{
    if (s.size()!=n) return false;
    for (auto c:s)
        if (c==char(A+48) || c==char(B+48))
            continue;
        else return false;
    return true;
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>A>>B>>n>>k;
    char c=char(A+48);
    string a=""; a.pb(c);
    c=char(B+48);
    string b=""; b.pb(c);
    ll d=(1<<n);
    string t="";
    string st="";
    FOR(i,1,n) st.pb(char(max(A,B)+48));
    ll cnt=0;
    while (d>0)
        cnt++,t.pb(char(d%10+48)),d/=10;
    int i=1;
    while (true)
    {
        string s=Nhan(t,doi(i));
        s=Cong(s,doi(k));
        string checker=Tru(st,s);
        if (checker[0]=='-')
            break;
        if (check(s))
        {
            ans=s;
            break;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
