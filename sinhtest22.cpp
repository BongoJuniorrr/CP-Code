#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define INT int
#define int long long
#define ull unsigned long long

const int NTEST=1;
const int MAX=20;

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

signed main()
{
    srand(time(NULL));
    for (int i=1;i<=NTEST;i++)
    {
        ofstream g("evensub.inp");
        //Rand(l,r);
        g<<1000<<'\n';
        for (int i=1;i<=1000;i++)
            g<<abs(Rand(1,1000000000))<<" ";
        g.close();
    }
    return 0;
}