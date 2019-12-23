#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef tuple<int,int,int> tp;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<tp> v(n);
	for (int i=0; i<n; i++) {
		int x,y; cin>>x>>y;
		v[i]={x,y,i+1};
	}
	sort(v.begin(),v.end());

	map<ii,set<tp>> mp;
	for (int i=1; i<n; i++) {
		int dx=get<0>(v[i])-get<0>(v[0]), dy=get<1>(v[i])-get<1>(v[0]);
		if(dx<0) dx=-dx, dy=-dy;
		int g=__gcd(abs(dx),abs(dy));
		dx/=g, dy/=g;
		mp[{dx,dy}].insert(v[i]);
	}
	if(mp.size()>1) {
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<endl;
	int p=get<2>(v.front()), q=get<2>(v.back());
	if(p>q) swap(p,q);
	cout<<p<<" "<<q<<endl;
	return 0;
}
