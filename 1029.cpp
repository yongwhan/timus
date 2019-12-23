#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	ll a[n][m], dp[n][m], par[n][m];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin>>a[i][j], dp[i][j]=-1;
	for (int j=0; j<m; j++)
		par[0][j]=-1, dp[0][j]=a[0][j];
	for (int i=1; i<n; i++) {
		for (int j=0; j<m; j++) {
			ll cur=0;
			for (int k=j; k>=0; k--) {
				cur+=a[i][k];
				ll cost=cur+dp[i-1][k];
				if(dp[i][j]==-1||dp[i][j]>cost)
					dp[i][j]=cost, par[i][j]=k;
			}
			cur=0;
			for (int k=j; k<m; k++) {
				cur+=a[i][k];
				ll cost=cur+dp[i-1][k];
				if(dp[i][j]==-1||dp[i][j]>cost)
					dp[i][j]=cost, par[i][j]=k;
			}
		}
	}

	ll cost=-1;
	int best=-1;
	for (int j=0; j<m; j++)
		if(cost==-1||cost>dp[n-1][j])
			cost=dp[n-1][j], best=j;
	vector<int> ret;
	for (int i=n-1; i>=0; i--)
		ret.push_back(best+1), best=par[i][best];
	reverse(ret.begin(),ret.end());
	cout<<ret[0];
	for (int i=1; i<n; i++) {
		if(ret[i-1]>=ret[i]) {
			for (int j=ret[i-1]; j>=ret[i]; j--) cout<<" "<<j;
		}
		else {
			for (int j=ret[i-1]; j<=ret[i]; j++) cout<<" "<<j;
		}
	}
	cout<<endl;
	return 0;
}
