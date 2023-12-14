#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ull unsigned long long
#define ii pair<int,int>
#define fi first
#define se second

const int MAXN = 1e6+6;
const int INF = 1e9;

int ST[4*MAXN];

int n,m,k;
int C[MAXN],F[MAXN];

void build(int id,int L,int R)
{
	if (L==R)
	{
		ST[id]=C[L];
		return;
	}
	int mid=(L+R)/2;
	build(2*id,L,mid);
	build(2*id+1,mid+1,R);
	ST[id]=min(ST[2*id],ST[2*id+1]);
}

int get(int id,int L,int R,int u,int v)
{
	if (L>v || u>R)
		return INF;
	if (L>=u && R<=v)
		return ST[id];
	int mid=(L+R)/2;
	int get1=get(2*id,L,mid,u,v);
	int get2=get(2*id+1,mid+1,R,u,v);
	return min(get1,get2);
}

main()
{
	fast;
	ifstream f("LOCDAU.inp");
	f>>n>>m>>k;
	for (int i=1;i<=n;i++)
		f>>C[i];
	f.close();
	ofstream g("LOCDAU.out");
	F[1]=C[1];
	build(1,1,n);
	for (int i=2;i<=k;i++)
		F[i]=min(F[i-1],C[i]);
	for (int i=k+1;i<=n;i++)
	{
		int MINX=get(1,1,n,i-k+1,i);
		F[i]=MINX;
	}
	double sum=0;
	for (int i=1;i<=n;i++)
		sum+=F[i]*m;
	g<<fixed<<setprecision(4)<<sum/(n*m);
	g.close();
}