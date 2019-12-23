#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,x; cin>>n;
	stack<int> stk;
	int mx=1;
	for (int i=0; i<n; i++) {
		cin>>x;
		if(x>=mx) {
			for (int i=mx; i<x; i++)
				stk.push(i);
			mx=x+1;
		} else {
			if(stk.top()!=x) {
				cout<<"Cheater"<<endl;
				return 0;
			} else stk.pop();
		}
	}
	cout<<(stk.empty()?"Not a proof":"Cheater")<<endl;
	return 0;
}
