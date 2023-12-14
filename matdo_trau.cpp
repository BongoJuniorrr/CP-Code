#include<bits/stdc++.h>
  using namespace std;
  long f[200001][30], n, a[200001], ans;
  string s;
bool check(long i, long j){
  long MAX  = 0;
  for(long k = 1; k <= 26; k++){
    MAX = max(MAX, f[j][k] - f[i-1][k]);
  }
  if(MAX > (j - i + 1) / 2){
    return true;
  }
  return false;
}
  int main(){
    freopen("matdo.inp","r",stdin);
    freopen("matdo.ans","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> s; n = s.size();    s='!' + s;
    for(long i = 1; i <= n; i++){
      a[i] = s[i] - 'a' + 1;
    }
    for(long i = 1; i <= n; i++){
      for(long j = 1; j <= 26; j++){
        f[i][j]  = f[i-1][j];
      }
      f[i][a[i]]++;
    }
    if(n <= 2000){
      for(long i = 1; i <= n; i++){
        for(long j = i; j <= n; j++){
          if(check(i, j)){
            ans = max(ans, j - i + 1);
          }
        }
      }
      cout << ans;
    }
    else{
      for(long i = 1; i <= n; i++){
        for(long l = 1; l <= 100; l++){
          if(i + l - 1 <= n){
            if(check(i, i + l - 1)){
              ans = max(ans, l);
            }
          }
        }
      }
      cout << ans;
    }
  }