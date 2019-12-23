#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	bool a[n][m];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin>>a[i][j];
	ii ret; int val=-1;
	for (int i=0; i<m; i++)
		for (int j=i+1; j<m; j++) {
			map<int,set<int>> ct;
			for (int k=0; k<n; k++)
				if(a[k][i]&&a[k][j]) ct[0].insert(k);
				else if(a[k][i]) ct[1].insert(k);
				else if(a[k][j]) ct[2].insert(k);
				else ct[3].insert(k);
			int cur=max({ct[0].size(),
			             ct[1].size(),
			             ct[2].size(),
			             ct[3].size()});
			if(val==-1||cur<val) val=cur, ret={i+1,j+1};
		}
	cout<<val<<endl<<ret.first<<" "<<ret.second<<endl;
	return 0;
}
