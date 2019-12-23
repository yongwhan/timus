#include<bits/stdc++.h>
using namespace std;
const int mx=1e7+7;
int ret[mx];
int main() {
	int k,p; cin>>k>>p;
	if(k<2) {
		cout<<0<<endl;
		return 0;
	}
	ret[1]=0;
	ret[2]=1%p;
	for (int i=3; i<=k; i++) {
		if(i%2) ret[i]=ret[i-1];
		else ret[i]=ret[i-1]+ret[i/2];
		if(ret[i]>=p) ret[i]-=p;
	}
	cout<<ret[k]<<endl;
	return 0;
}
