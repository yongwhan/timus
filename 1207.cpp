#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

double angle(const iii &p, const ii &org) {
	double dx=p.first.first-org.first,
	       dy=p.first.second-org.second,
	       val=acos(abs(dx)/sqrt(dx*dx+dy*dy));
	return (dx<0)?(2*acos(0)-val):val;
}

int main() {
	int n,x,y; cin>>n;
	vector<iii> a(n);
	for (int i=0; i<n; i++)
		cin>>x>>y, a[i]={{x,y},i+1};
	sort(a.begin(),a.end(),[](const iii &p, const iii &q) { return p.first.second<q.first.second; });
	const ii org=a[0].first;
	int o=a[0].second;
	a.erase(a.begin());
	sort(a.begin(),a.end(),[&org](const iii &p, const iii &q) { return angle(p,org)<angle(q,org); });
	cout<<o<<" "<<a[(n-1)/2].second<<endl;
	return 0;
}
