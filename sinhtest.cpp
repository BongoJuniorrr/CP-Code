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
        ofstream g("alpha_country.inp");
        //Rand(l,r);
        int n=1e5;
        g<<n<<'\n';
        for (int i=1;i<=n;i++)
        {
            int val=rand()%500+1;
            int dau=rand()%2;
            if (dau) val*=-1;
            g<<val<<" ";
        }
        g.close();
    }
    return 0;
}