#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m,amax=0,bmax=0; cin>>n>>m;
	vector<int> a(n), b(m);
	for (int i=0; i<n; i++) cin>>a[i];
	for (int i=0; i<m; i++) cin>>b[i];
	for (int i=1; i<n-1; i++) amax=max(amax,a[i]);
	for (int i=1; i<m-1; i++) bmax=max(bmax,b[i]);
	cout<<max({min(a[0],b[m-1]),
						 min(b[0],a[n-1]),
						 min({a[0],bmax,a[n-1]}),
						 min({b[0],amax,b[m-1]})})<<endl;
	return 0;
}
