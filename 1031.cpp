#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	vector<ll> L(3), C(3);
	for (int i=0; i<3; i++) cin>>L[i];
	for (int i=0; i<3; i++) cin>>C[i];
	int n,x,y; cin>>n;
	vector<ll> d(n,0);
	cin>>x>>y; x--; y--;
	if(x>y) swap(x,y);
	for (int i=1; i<n; i++) cin>>d[i];
	map<int,ll> dp;
	for (int i=0; i<n; i++) dp[d[i]]=INT_MAX;
	dp[d[x]]=0;
	for (int i=x+1; i<=y; i++)
		for (int j=0; j<3; j++)
			dp[d[i]]=min(dp[d[i]],dp.lower_bound(d[i]-L[j])->second+C[j]);
	cout<<dp[d[y]]<<endl;
	return 0;
}
