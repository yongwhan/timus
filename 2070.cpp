#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx=1e6+777;
const ll inf=1e12+777;
vector<bool> flag(mx,true);
vector<int> ct(mx,0), ps;

ll power(ll x, int e) {
	if(pow(x,e)>inf)
		return inf;
	ll ret=1;
	for (int i=0; i<e; i++)
		ret*=x;
	return ret;
}

ll eval(ll x) {
	int ct=0;
	for (const auto &e : ps) {
		for (ll b=2; b<mx; b++) {
			if(!flag[b]) continue;
			ll cur=power(b,e-1);
			if(cur>x||cur==inf) break;
			ct++;
		}
	}
	return x-ct;
}

int main() {
	flag[0]=flag[1]=false;
	for (int i=2; i*i<mx; i++)
		if(flag[i])
			for (int j=i; j*i<mx; j++)
				flag[i*j]=false;
	for (int i=3; i<50; i++)
		if(flag[i])
			ps.push_back(i);
	for (int i=1; i<mx; i++)
		ct[i]+=ct[i-1];
	ll L,R; cin>>L>>R;
	cout<<eval(R)-eval(L-1)<<endl;
	return 0;
}
