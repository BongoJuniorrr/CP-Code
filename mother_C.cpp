#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void DFS(int v) {
    visited[v] = true;
    cout<<v<<" "<<visited[v]<<'\n';
    for (int u : adj[v]) {
        if (!visited[u])
            DFS(u);
    }
}

int findMotherVertex(int n) {
    visited.assign(n, false);
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
            v = i;
        }
    }

    visited.assign(n, false);
    DFS(v);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
        {
            return -1;
        }
    }
    cout<<endl;
    return v;
}

int main() {
    // freopen("mother.inp","r",stdin);
    // freopen("mother.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout<<endl;
    cout << findMotherVertex(n);
    // cout<<'\n';
    // cout<<clock()/1000.0;
    return 0;
}
