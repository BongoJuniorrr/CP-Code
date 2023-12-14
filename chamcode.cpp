#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define int long long

const int NTEST=1000;
const int MAX=1000000000000000000;

const string NAME="TEST";
const string COMPARE="fc "+NAME+".out "+NAME+".ans";

signed main()
{
	srand(time(NULL));
	ofstream go("result.txt");
	ofstream gi("clock_result.txt");
	for (int i=1;i<=NTEST;i++)
	{
		ofstream g((NAME+".inp").c_str());

		//Create Test
		int N=rand()%MAX+1;
		g<<50<<endl;
		bool check[105];
		memset(check,0,sizeof(check));
		for (int i=1;i<=50;i++)
		{
			int t=rand()%100+1;
			while (check[t]==1)
				t=rand()%100+1;
			check[t]=1;
			g<<t<<endl;
		}
		g.close();

		//Run CT Test
		auto start1 = high_resolution_clock::now();
        system("cardgame_trau.exe");
       	auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        gi<<fixed<<setprecision(3)<<duration1.count()/(double)1000000<<"ms - CT TEST"<<endl;

        //Run Main Test
        auto start2 = high_resolution_clock::now();
        system("cardgame.exe");
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        gi<<fixed<<setprecision(3)<<duration2.count()/(double)1000000<<"ms - MAIN TEST"<<endl;
        gi<<endl;
        //Check answer
		if (system(COMPARE.c_str())==0)
			go<<"CORRECT"<<endl;
		else 
			go<<"WRONG ANSWER #"<<i<<" "<<N<<endl;
	}
	go.close();
	gi.close();
}