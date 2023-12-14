#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define INT int
#define int long long
#define ll long long
#define ull unsigned long long
#define ii pair<int,int>

const int NTEST=10000;
const int MAX=1e18;

const string NAME = "samac";
const string NAME1 ="samac";
const string NAME2 = "samac_trau";
const string COMPARE="fc "+NAME+".out "+NAME+".ans";

signed main()
{
    srand(time(NULL));
    ofstream go("result.txt");
    ofstream gi("clock_result.txt");
    for (int i=1;i<=NTEST;i++)
    {
        ofstream g((NAME+".inp").c_str());
        //ofstream test_out("TEST_OUTPUT.txt");

        //Create Test
        int N=20;
        g<<N<<'\n';
        for (int i=1;i<=N;i++)
        {
            int val=rand()%32767+1;
            int dau=rand()%2;
            if (dau) val=-val;
            g<<val<<" ";
        }
        g.close();

        //Run CT Test
        auto start1 = high_resolution_clock::now();
        system((NAME1+".exe").c_str());
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        gi<<fixed<<setprecision(3)<<duration1.count()/(double)1000000<<"ms - NAME1 TEST"<<endl;

        //Run Main Test
        auto start2 = high_resolution_clock::now();
        system((NAME2+".exe").c_str());
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        gi<<fixed<<setprecision(3)<<duration2.count()/(double)1000000<<"ms - NAME2 TEST"<<endl;
        gi<<endl;
        //Check answer
        if (system(COMPARE.c_str())==0)
            go<<"CORRECT"<<endl;
        else 
            go<<"WRONG ANSWER #"<<i<<" "<<endl;

        //test_out<<"TEST CASE #"<<i<<": "<<endl;
        //test_out<<N<<endl;
    }
    go.close();
    gi.close();
    //test_out.close();
    return 0;
}