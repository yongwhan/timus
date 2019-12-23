#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000;
pair<int, int> t[4*MAXN];
int z=1;

void build_tree(int v, int tl, int tr) {
	if (tl==tr) {
		t[v]=make_pair(1,z++);
		return;
	}
	int tm=(tl+tr)/2;
	build_tree(2*v, tl, tm); build_tree(2*v+1, tm+1, tr);
	t[v].first=t[2*v].first+t[2*v+1].first;
	t[v].second=-1;
}

int req(int v, int tl, int tr, int n) {
	if (tl==tr) {
		--t[v].first;
		return t[v].second;
	}
	int tm=(tl+tr)/2;
	t[v].first--;
	return t[2*v].first>=n ? req(2*v, tl, tm, n) : req(2*v+1, tm+1,tr,n-t[2*v].first);
}

int main() {
	int n, k; cin>>n>>k;
	build_tree(1,1,100000);
	int cur=k;
	for (int i=0; i<n; ++i) {
		if(i) cout<<" ";
		cout<<req(1,1,100000, cur);
		if (i==n-1) break;
		cur=(cur-1+k)%(n-1-i);
		if (cur==0) cur+=n-1-i;
	}
	cout<<endl;
	return 0;
}
