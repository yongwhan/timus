#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<int> a(n), idx(n,-1);
	for (int i=0; i<n; i++)
		cin>>a[i];
	int cur=0;
	for (int i=0; i<n; i++) {
		cur=(cur+a[i])%n;
		if(cur==0) {
			cout<<i+1<<endl;
			for (int j=0; j<=i; j++)
				cout<<a[j]<<endl;
			return 0;
		}
		if(idx[cur]!=-1) {
			cout<<i-idx[cur]<<endl;
			for (int j=idx[cur]+1; j<=i; j++)
				cout<<a[j]<<endl;
			return 0;
		}
		idx[cur]=i;
	}
	return 0;
}
