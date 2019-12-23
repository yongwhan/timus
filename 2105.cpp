#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll L,T,vA,vB,dA=0,dB=0; cin>>L>>T>>vA>>vB;
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		int type,t,d; cin>>type>>t>>d;
		if(type==1) dA+=d;
		else if(type==2) dB+=d;
	}
	cout<<(vA*(T-dA)+vB*(T-dB))/L<<endl;
	return 0;
}
