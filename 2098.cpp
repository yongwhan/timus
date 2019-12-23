#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll b,c,d,p,t; int k; cin>>b>>c>>d>>k>>p;
	ll x=b*100, y=0;
	for (int i=1; i<=k; i++)
		t=c+i*d, x+=t*100, y+=t*(100+p);
	cout<<(x<y?"Cash":"Insurance")<<endl;
	cout<<setprecision(2)<<fixed<<abs(x-y)/100.<<endl;
	return 0;
}
