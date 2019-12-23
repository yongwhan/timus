#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<int> l(n), r(n);
	for (int i=0; i<n; i++)
		cin>>l[i]>>r[i];
	vector<vector<int>> child(n);
	vector<int> indeg(n,0), dist(n,INT_MIN), par(n,-1);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if(i!=j&&l[i]<l[j]&&r[j]<r[i])
				child[i].push_back(j), indeg[j]++;
	queue<int> q;
	for (int i=0; i<n; i++)
		if(!indeg[i])
			q.push(i), dist[i]=1;
	while(!q.empty()) {
		int cur=q.front(); q.pop();
		for (const auto &nxt : child[cur])
			if(dist[nxt]<dist[cur]+1)
				dist[nxt]=dist[cur]+1, q.push(nxt), par[nxt]=cur;
	}
	int mx=*max_element(dist.begin(), dist.end()), cur=-1;
	for (int i=0; i<n; i++)
		if(dist[i]==mx)
			cur=i;
	cout<<mx<<endl;
	vector<int> seq;
	while(1) {
		seq.push_back(cur);
		if(par[cur]==-1) break;
		cur=par[cur];
	}
	int sz=seq.size();
	for (int i=0; i<sz; i++) {
		if(i) cout<<" ";
		cout<<seq[i]+1;
	}
	cout<<endl;
	return 0;
}
