#include<bits/stdc++.h>
using namespace std;

map<int,bool> _exist, _odd;
map<int,int> _prev;

bool add(int a,int b,bool c){
	if (!_exist[b]) {
		_odd[b]=c; _prev[b]=a;
		return _exist[b]=true;
	}
	if(_prev[b]==a) return c==_odd[b];
	else if(_prev[b]<a) return add(_prev[b],a-1,!(c==_odd[b]));
	else return add(a,_prev[b]-1,!(c==_odd[b]));
}

int main() {
	int n,m,a,b; string s; bool done;
	while(cin>>n&&n!=-1) {
		cin>>m;
		_exist.clear(); _odd.clear(); _prev.clear();
		done=false;
		for (int i=0; i<m; i++) {
			cin>>a>>b>>s;
			if(!done&&!add(a,b,s=="odd")) cout<<i, done=true;
		}
		if(!done) cout<<m;
		cout<<endl;
	}
	return 0;
}
