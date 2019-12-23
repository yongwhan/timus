#include<bits/stdc++.h>
using namespace std;

int s2n(const string &s) {
	stringstream ss(s);
	int ret; ss>>ret;
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	map<int,vector<int>> par, chd;
	string s;
	while(cin>>s) {
		if(s[0]=='B') break;
		int x=s2n(s), y; cin>>y;
		par[x].push_back(y);
		chd[y].push_back(x);
	}
	set<int> victim;
	int x;
	while(cin>>x)
		victim.insert(x);
	vector<int> ret;
	for (int i=1; i<=n; i++) {
		if(victim.count(i)) continue;
		bool wolf=true;
		queue<int> q; q.push(i);
		while(!q.empty()) {
			int cur=q.front(); q.pop();
			for (const int &nxt : par[cur]) {
				if(victim.count(nxt)) {
					wolf=false; break;
				}
				q.push(nxt);
			}
			if(!wolf) break;
		}
		if(!wolf) continue;
		q.push(i); wolf=true;
		while(!q.empty()) {
			int cur=q.front(); q.pop();
			for (const int &nxt : chd[cur]) {
				if(victim.count(nxt)) {
					wolf=false; break;
				}
				q.push(nxt);
			}
			if(!wolf) break;
		}
		if(wolf) ret.push_back(i);
	}
	if(ret.empty()) {
		cout<<0<<endl;
		return 0;
	}
	bool first=true;
	for (const int &x : ret) {
		if(!first) cout<<" ";
		cout<<x;
		first=false;
	}
	cout<<endl;
	return 0;
}
