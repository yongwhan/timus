#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	cout<<n-1<<" ";
	int ret=(n-1)/2*3;
	if(n%2==0) ret++;
	cout<<ret<<endl;
	return 0;
}
