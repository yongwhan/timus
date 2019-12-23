#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,x; cin>>n;
	multiset<int> mst;
	for (int i=0; i<n; i++)
		cin>>x, mst.insert(x);
	int ret=n;
	bool up=true;
	while(up) {
		up=false;
		for (int i=1; i<30; i++)
			if(mst.count(i)&&mst.count(i+1)) {
				ret--, up=true, mst.erase(mst.find(i)), mst.erase(mst.find(i+1));
				break;
			}
	}
	cout<<ret<<endl;
	return 0;
}
