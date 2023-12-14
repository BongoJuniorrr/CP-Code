int n,m,k;
int mx[N],my[N],dist[N];
void DFS(int u,int pre)
{
    for (auto v:g[u])
    {
        int vv=v.fi;
        int ww=v.se;
        if (vv==pre)
            continue;
        F[vv]=F[u]+ww;
        h[vv]=h[u]+1;
        P[vv][0]=u;
        DFS(vv,u);
    }
}
 
void pre_process()
{
    for (int i=1;(1<<i)<=n;i++)
        for (int j=1;j<=n;j++)
            P[j][i]=P[P[j][i-1]][i-1];
}
 
int LCA(int x,int y)
{
    if (h[x]<h[y]) swap(x,y);
    int p=log2(n);
    for (int z=p;z>=0;z--)
        if (h[x] - (1<<z) >= h[y])
            x=P[x][z];
    if (x==y)
        return x;
    for (int z=p;z>=0;z--)
        if (P[x][z]!=P[y][z])
        {
            x=P[x][z];
            y=P[y][z];
        }
    return P[x][0];
}