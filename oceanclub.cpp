#include<bits/stdc++.h>
using namespace std;
#define FOR(x,l,r) for (int x=l;x<=r;x++)
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int MAXN = 105;
const int MAXK = 105;
const int MOD = 2023;

vector<int> adj[100005];
int dp[MAXN][MAXK],a[105];
bool cnt[100005];

signed main() {
    fast;
    int n;
    cin>>n;
    FOR(i,1,n)
    {
        cin>>a[i];
        if (!cnt[a[i]]) cnt[a[i]]=1;
        else a[i]=-1;
    }
    FOR(i,1,n-1)
        FOR(j,i+1,n)
        {
            if (a[i]==-1 || a[j]==-1)
                continue;   
            if (a[i]<a[j] && __gcd(a[i],a[j])==1)
                adj[a[j]].push_back(a[i]);
        }
    int q;
    cin>>q;
    while (q--) {
        int s, t, k;
        cin >> s >> t >> k;
        //k++;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = 0;

        dp[t][0] = 1;
        queue<pair<int, int>> que;
        que.push({t, 0});

        while (!que.empty()) {
            int v=que.front().first;
            int d=que.front().second;
            que.pop();
            //cout<<v<<" "<<d<<'\n';
            if (d == k) continue;

            for (int u : adj[v]) {
                if (dp[u][d + 1] == 0) que.push({u, d + 1});
                dp[u][d + 1] += dp[v][d];
                dp[u][d + 1] %= MOD;
            }
        }

        cout<<dp[s][k]<<'\n';
        // FOR(kk,0,k)
        //     cout<<dp[s][kk]<<" ";
    }

    return 0;
}