#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int S,N; cin>>S>>N;
	vector<int> A(S);
	for (int i=0; i<S; i++)
		cin>>A[i];
	for (int i=0; i<2; i++) {
		int sum=0;
		for (int j=0; j<S; j++) {
			sum+=A[j];
			if(sum>j+1+N) {
				cout<<"NO"<<endl;
				return 0;
			}
		}
		reverse(A.begin(),A.end());
	}
	cout<<"YES"<<endl;
	return 0;
}
