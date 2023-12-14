#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ull unsigned long long
#define ii pair<int,int>
#define fi first
#define se second

int n,m,k;
int C[105],F[105];

main()
{
	fast;
	ifstream f("GIADAU.inp");
	f>>n>>m>>k;
	for (int i=1;i<=n;i++)
		f>>C[i];
	f.close();
	ofstream g("GIADAU.out");
	F[1]=C[1];
	for (int i=2;i<=k;i++)
		F[i]=min(F[i-1],C[i]);
	for (int i=k+1;i<=n;i++)
	{
		int MINX=C[i];
		for (int j=i-1;j>=i-k+1;j--)
			MINX=min(MINX,C[j]);
		F[i]=MINX;
	}
	double sum=0;
	for (int i=1;i<=n;i++)
		sum+=F[i];
	g<<fixed<<setprecision(4)<<sum/n;
	g.close();
}