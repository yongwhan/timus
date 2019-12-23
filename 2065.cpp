#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	vector<int> a(n,0);
	int x=0, sgn=1;
	for (int i=0; i<k-1; i++) {
		if(i%2==0) x++;
		a[i]=x*sgn;
		sgn=-sgn;
	}
	for (int i=0; i<n; i++) {
		if(i) cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
