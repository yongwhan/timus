#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	vector<int> a;
	int x;
	while(cin>>x) a.push_back(x-1);
	int n=a.size();
	vector<int> deg(n+1,1);
	for (const auto &x : a) deg[x]++;
	map<int,set<int>> adj;
	for (const auto &i : a) for (int j=0; j<=n; j++)
		if(j!=i&&deg[j]==1) {
			deg[i]--, deg[j]--; adj[i].insert(j); adj[j].insert(i); break;
		}
	for (const auto it : adj) {
		cout<<it.first+1<<":";
		for (const auto j : it.second) cout<<" "<<j+1;
		cout<<endl;
	}
	return 0;
}
