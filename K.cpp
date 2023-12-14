#include <bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'

int F[50005];

signed main()
{
    fast;
    int n,a[50005],m=1;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    F[1]=F[n]=1;
    for (int i=2;i<=n;i++) 
    {
        F[i]=min(min(F[i-1]+1,min(i,n-i+1)),min(a[i+1],a[i]));
    }
    for (int i=1;i<=n/2+1;i++) m=max(m,F[i]);

    cout<<m;
    /*
    cout<<endl;
    for (int i=1;i<=n;i++) cout<<F[i]<<" ";
    */

    return 0;
}