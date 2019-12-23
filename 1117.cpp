#include<bits/stdc++.h>
using namespace std;

int eval(int x) {
	return x?(x-2*(__builtin_popcount(x)-1)-__builtin_popcount(x^(x-1))):0;
}

int main() {
	int x,y;
	cin>>x>>y;
	if(x>y) swap(x,y);
	cout<<eval(y)-eval(x)<<endl;
	return 0;
}
