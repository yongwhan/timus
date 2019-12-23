#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=55;
ll binom[mx][mx];
vector<ll> p;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	vector<bool> flag(mx,true);
	flag[0]=flag[1]=false;
	for (int i=2; i*i<mx; i++)
		if(flag[i])
			for (int j=i; j*i<mx; j++)
				flag[i*j]=false;
	for (int i=0; i<mx; i++)
		if(flag[i])
			p.push_back(i);
	binom[0][0]=1;
	for (int i=1; i<mx; i++) {
		binom[i][0]=binom[i][i]=1;
		for (int j=1; j<i; j++)
			binom[i][j]=binom[i-1][j-1]+binom[i-1][j];
	}
	int K,S; cin>>K>>S;
	ll ret=0;
	int sz=p.size();
	for (int bt=1; bt<(1<<sz); bt++) {
		ll cur=1, sgn=-1;
		for (int i=0; i<sz; i++)
			if(bt&(1<<i)) {
				cur*=p[i], sgn=-sgn;
				if(cur>S) break;
			}
		if(cur>S) continue;
		ll val=S/cur;
		if(val>=K)
			ret+=sgn*binom[val][K];
	}
	cout<<min(10000LL,ret)<<endl;
	return 0;
}
