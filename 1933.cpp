#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	int k=2*n+1;
	for (int i=0; i<k; i++) {
		int x=i;
		for (int j=0; j<k; j++) {
			x++;
			if(i==j) {
				cout<<"0 ";
				continue;
			}
			if(x>k) x=1;
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}
