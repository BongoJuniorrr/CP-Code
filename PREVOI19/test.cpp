#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string a,b;

string Cong(string a,string b)
{
	while (a.size()<b.size()) a='0'+a;
	while (b.size()<a.size()) b='0'+b;
	int x,y,nho=0,c; string st="";
	for (int i=a.size()-1;i>=0;i--)
	{
		x=int(a[i])-48; y=int(b[i])-48;
		c=x+y+nho;
		nho=c/10;
		c%=10;
		st=char(c+48)+st;
	}
	if (nho==1)
		st='1'+st;
	return st;
}

string Tru(string a,string b)
{
	while (a.size()<b.size()) a='0'+a;
	while (b.size()<a.size()) b='0'+b;
	int x,y,muon=0,c; string st=""; bool kt=false;
	if (b>a) {swap(a,b); kt=true;}
	for (int i=a.size()-1;i>=0;i--)
	{
		x=int(a[i])-48; y=int(b[i])-48;
		c=x-y-muon;
		if (c<0)
		{
			muon=1;	
			c+=10;
		} else muon=0;
		st=char(c+48)+st;
	}
	while (st[0]=='0' && st.size()>1)
		st.erase(0,1);
	if (kt)
		st='-'+st;
	return st;
}

string Nhan(string a,string b)
{
	if (a=="0" || b=="0")
		return "0";
	vector<int> vec(a.size()+b.size()+1);
	for (int i=b.size()-1;i>=0;i--)
	{
		for (int j=a.size()-1;j>=0;j--)
		{
			vec[i+j+1]=vec[i+j+1] + (int(a[j])-48)*(int(b[i])-48);
			vec[i+j]=vec[i+j] + vec[i+j+1]/10;
			vec[i+j+1]%=10;
		}
	}
	vec.erase(vec.end()-1,vec.end());
	if (vec[0]==0)
		vec.erase(vec.begin());
	for (auto i:vec)
		cout<<i;
	return "";
}

int main()
{
	cin>>a>>b;
	cout<<Cong(a,b)<<endl;
	cout<<Tru(a,b)<<endl;
	cout<<Nhan(a,b)<<endl;
	return 0;
}
