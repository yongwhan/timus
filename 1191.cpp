#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,n; cin>>x>>n;
	for (int i=0; i<n; i++) {
		int k; cin>>k;
		if(x%k) x-=k;
		if(x<0) {
			cout<<"YES"<<endl;
			return 0;
		}
		if(x%k) x+=k-x%k;
	}
	cout<<"NO"<<endl;
	return 0;
}
