#include<bits/stdc++.h>
using namespace std;

int eval(int d) {
	for (int i=2; i<=d; i++)
		d-=d/i;
	return d;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int l,r; cin>>l>>r;
	cout<<eval(r)-eval(l-1)<<endl;
	return 0;
}
