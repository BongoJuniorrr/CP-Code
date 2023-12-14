#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define INT int
#define int long long
#define ull unsigned long long

const int NTEST=50;
const int MAX=20;

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

signed main()
{
    srand(time(NULL));
    double ans=0;
    for (int i=1;i<=1;i++)
    {
        int bd=1e8-i+1;
        ofstream g("chiakeo1.inp");
        g<<10<<'\n';
        for (int i=1;i<=10;i++)
            g<<abs(Rand(1,100))<<" ";
        g.close();
        system("chiakeo1.exe");
        ifstream ck("chiakeo1.out");
        double d;
        while (ck>>d);
        ans=max(ans,d);
    }
    cout<<ans<<" ";
    return 0;
}