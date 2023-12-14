
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
#define endl "\n"

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)

#define ull unsigned long long
#define ll long long
//#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "teacher";

const int MAXN = 3e3 + 9;
const int MOD = 1e9 + 7;
string str[MAXN];
int n;
struct Node{
    int child[27];
    int cnt; 
    Node(){
        memset(child,0,sizeof(child));
        cnt = 0;
    }
};
int ans = 1;
int fact[MAXN];
struct Trie{
    vector<Node> T = {Node(),Node()};
    void insert(string key){
        int p = 1;
        for(int i=0;i<key.size();i++){
            int c = key[i] -  'A';
            
            if (T[p].child[c] == 0){
                T[p].child[c] = T.size();
                T.pb(Node());
            }
            p = T[p].child[c];
        }
        cout<<endl;
        
        T[p].cnt++;
    }
};
Trie trie;

void dfs(int p){
    int cnt = trie.T[p].cnt;
    for(int i=0;i<26;i++){
        if (trie.T[p].child[i] > 0){
            cnt++;
            dfs(trie.T[p].child[i]);
        }
    }
    

    ans = (ans * fact[cnt])%MOD;

}
signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    ans = 1;
    for(int i=1;i<=n;i++){
        cin>>str[i];
        trie.insert(str[i]);
    }
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = (fact[i-1] * i)%MOD;
    }
    dfs(1);
    cout<<ans<<endl;
    

    return 0;
}